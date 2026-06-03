cmake_minimum_required(VERSION 3.16)
project(clicker_plus_plus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CONFIGURE_DEPENDS_NEW OFF CACHE INTERNAL "" FORCE)

if(APPLE)
    set(CMAKE_XCODE_GENERATE_SCHEME TRUE)
    if(NOT DEFINED CMAKE_OSX_ARCHITECTURES)
        set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Build for both Intel and Apple Silicon")
    endif()
    if(NOT DEFINED CMAKE_OSX_DEPLOYMENT_TARGET)
        set(CMAKE_OSX_DEPLOYMENT_TARGET "13.0")
    endif()
endif()

file(GLOB_RECURSE ALL_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS header/*.hpp)
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS unit_tests/*.cpp)

set(SRC_FILES "")
foreach(file ${ALL_SRC})
    if(NOT file MATCHES ".*main\\.cpp$")
        list(APPEND SRC_FILES ${file})
    endif()
endforeach()

foreach(file ${SRC_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_SOURCE_DIR}/src" ${file})
    get_filename_component(dir "${rel_path}" DIRECTORY)
    source_group("src/${dir}" FILES ${file})
endforeach()

foreach(file ${HEADER_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_SOURCE_DIR}/header" ${file})
    get_filename_component(dir "${rel_path}" DIRECTORY)
    source_group("header/${dir}" FILES ${file})
endforeach()

foreach(file ${TEST_FILES})
    file(RELATIVE_PATH rel_path "${CMAKE_SOURCE_DIR}/unit_tests" ${file})
    get_filename_component(dir "${rel_path}" DIRECTORY)
    source_group("unit_tests/${dir}" FILES ${file})
endforeach()

add_library(project_lib ${SRC_FILES} ${HEADER_FILES})
target_include_directories(project_lib PUBLIC header)
target_precompile_headers(project_lib PRIVATE header/std_aliases.hpp)

if(EXISTS "${CMAKE_SOURCE_DIR}/src/main.cpp")
    add_executable(clicker_plus_plus src/main.cpp)
    target_link_libraries(clicker_plus_plus PRIVATE project_lib)
    target_precompile_headers(clicker_plus_plus REUSE_FROM project_lib)
endif()

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_environment ${TEST_FILES})
target_link_libraries(test_environment PRIVATE project_lib GTest::gtest_main GTest::gmock)
target_include_directories(test_environment PRIVATE header)
target_precompile_headers(test_environment REUSE_FROM project_lib)

add_test(NAME AllTests COMMAND test_environment WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
