# ${CMAKE_SOURCE_DIR}/tests/CMakeLists.txt
project(Tests CXX)
find_package(Qt5 REQUIRED Test)

set(
  test_cases
  test_model
)

foreach(test_case IN LISTS test_cases)
  add_executable(
    ${test_case}
    ${test_case}.cpp
  )

  target_link_libraries(
    ${test_case}
    PRIVATE
    Qt5::Widgets
    Qt5::Test
  )

  target_include_directories(
    ${test_case}
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/include/
  )

  set_target_properties(
    ${test_case}
    PROPERTIES
    # STL
    CXX_EXTENSIONS        OFF
    CXX_STANDARD          17
    CXX_STANDARD_REQUIRED ON
    # Qt5
    AUTOMOC               ON
  )

  add_test(
    ${test_case}
    ${test_case}
  )
endforeach()

target_sources(
  test_model
  PRIVATE
  ${CMAKE_SOURCE_DIR}/include/ImageModel.hpp
  ${CMAKE_SOURCE_DIR}/src/ImageModel.cpp
)
