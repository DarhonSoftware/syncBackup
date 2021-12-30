cmake_minimum_required(VERSION 3.16)

project(syncbackup VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_VERSION_MAJOR 5)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick QuickControls2 LinguistTools REQUIRED)

set(TS_FILES syncbackup_es.ts)

set(PROJECT_SOURCES
        main.cpp
        backend.cpp
        about.cpp
        mainwindow.cpp
        dr_standarditemmodel.cpp
        qml.qrc
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(syncbackup
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET syncbackup APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(syncbackup SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(syncbackup
          ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_compile_definitions(syncbackup
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(syncbackup
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2)

set_target_properties(syncbackup PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(syncbackup)
    qt_finalize_executable(syncbackup)
endif()

install(TARGETS syncbackup)
install(PROGRAMS pkg-info/com.darhon.syncbackup.desktop  DESTINATION /app/share/applications)
install(FILES pkg-info/com.darhon.syncbackup.metainfo.xml DESTINATION /app/share/metainfo)
install(FILES pkg-info/com.darhon.syncbackup_16.png DESTINATION /app/share/icons/hicolor/16x16/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_24.png DESTINATION /app/share/icons/hicolor/24x24/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_32.png DESTINATION /app/share/icons/hicolor/32x32/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_48.png DESTINATION /app/share/icons/hicolor/48x48/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_64.png DESTINATION /app/share/icons/hicolor/64x64/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_128.png DESTINATION /app/share/icons/hicolor/128x128/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_256.png DESTINATION /app/share/icons/hicolor/256x256/apps RENAME com.darhon.syncbackup.png)
install(FILES pkg-info/com.darhon.syncbackup_512.png DESTINATION /app/share/icons/hicolor/512x512/apps RENAME com.darhon.syncbackup.png)




