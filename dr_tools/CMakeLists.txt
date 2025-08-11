# Static library
# Provides standard Darhon Tools

qt_add_library(DarhonTools STATIC
  dr_standarditemmodel.cpp
)

target_link_libraries(DarhonTools PRIVATE Qt6::Quick)
