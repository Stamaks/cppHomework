#include_directories(../src)
#
#include_directories(gtest)
#include_directories(gtest/gtest)
#
#add_executable(xipoint_test_start
#    # point tests
#    point_test.cpp
#    point_array_test.cpp
#    # point sources
#    ../src/xipoint.cpp
#    ../src/xipoint.h
#    # gtest sources
#    gtest/gtest/gtest-all.cc
#    gtest/gtest/gtest_main.cc
#)
#
#cmake_minimum_required(VERSION 3.3)
#
#project(point)
#
#include_directories(../src)
#
#include_directories(gtest)
#include_directories(gtest/gtest)
#
#add_executable(xipoint_test_start
#    # point tests
#    point_test.cpp
#    point_array_test.cpp
#    # point sources
#    ../src/xipoint.cpp
#    ../src/xipoint.h
#    # gtest sources
#    gtest/gtest/gtest-all.cc
#    gtest/gtest/gtest_main.cc
#)

cmake_minimum_required(VERSION 3.3)

set(REPO ~/ClionProjects/.repo)

project(Test)

project(Example)

include(CTest)
enable_testing()

#set(gtest_disable_pthreads on) #needed in MinGW
include(~/CLionProjects/.repo/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

#set(test_SRCS ADD ALL TEST SOURCE FILES HERE)
add_executable(runUnitTests point_test.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
#add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.