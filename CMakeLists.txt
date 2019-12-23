cmake_minimum_required(VERSION 3.9)
project(RawImageViewer CXX)

option(ENABLE_TESTING "Enable Testing" ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(options)

find_package(Qt5 REQUIRED Widgets)

add_executable(
  ${PROJECT_NAME}
)

target_sources(
  ${PROJECT_NAME}
  PRIVATE
  main.cpp
  # MainWidget
  include/MainWidget.hpp
  src/MainWidget.cpp
  # ImageView
  include/ImageView.hpp
  src/ImageView.cpp
  # ImageModel
  include/ImageModel.hpp
  src/ImageModel.cpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
  Qt5::Widgets
  options::options
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  # STL
  CXX_EXTENSIONS        OFF
  CXX_STANDARD          17
  CXX_STANDARD_REQUIRED ON
  # Qt5
  AUTOMOC               ON
)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
