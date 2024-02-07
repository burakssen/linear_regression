cmake_minimum_required(VERSION 3.27)
project(linear_regression)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_DIR src)
set(VENDOR_DIR vendor)

add_subdirectory("${VENDOR_DIR}/raylib")

file(GLOB_RECURSE SOURCE_FILES 
    "${SOURCE_DIR}/**.cpp" 
    "${SOURCE_DIR}/**.h" 
)

add_executable(linear_regression "${SOURCE_FILES}")

target_include_directories(linear_regression PUBLIC 
    "${SOURCE_DIR}"
    "${SOURCE_DIR}/App"
    "${VENDOR_DIR}/raylib/src"
)

target_link_libraries(linear_regression PUBLIC raylib)