cmake_minimum_required(VERSION 3.22)

project(syncBackup VERSION 2.1.4 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widget is required to provide QtQuick.Dialogs for non GTK+ platforms
find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2 LinguistTools Widgets)

#qt_policy(SET QTP0004 NEW)

qt_standard_project_setup(
  I18N_SOURCE_LANGUAGE en
  I18N_TRANSLATED_LANGUAGES es
)

add_subdirectory(darhon_tools)

qt_add_executable(${PROJECT_NAME}
  main.cpp
  backend.cpp
  about.cpp
  mainwindow.cpp
)

qt_add_resources(${PROJECT_NAME} "resources"
  FILES
  html/excinchelp.html
  html/help.html
)

qt_add_qml_module(${PROJECT_NAME}
  URI darhon
  RESOURCE_PREFIX /

  QML_FILES
  qml/AboutDialog.qml
  qml/CommandlineDialog.qml
  qml/ExcIncHelpDialog.qml
  qml/HelpDialog.qml
  qml/initpage.qml
  qml/mainwindow.qml
  qml/settings.qml
  qml/SSHDialog.qml

  RESOURCES
  images/about.png
  images/about1.png
  images/back.png
  images/cancel.png
  images/command.png
  images/copy.png
  images/darhon.png
  images/delete.png
  images/folder.png
  images/help.png
  images/insert.png
  images/load.png
  images/quit.png
  images/remote.png
  images/reset.png
  images/run.png
  images/save.png
  images/settings.png
)

# To update the entries in the .ts file, build the update_translations target:
# <build-dir>$ cmake --build . --target update_translations
qt_add_translations(${PROJECT_NAME}
  LUPDATE_OPTIONS -no-obsolete
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE DarhonTools Qt6::Quick Qt6::QuickControls2 Qt6::Widgets
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

install(TARGETS ${PROJECT_NAME})
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
