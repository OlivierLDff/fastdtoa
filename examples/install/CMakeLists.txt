# ~~~
# Copyright (C) Olivier Le Doeuff - All Rights Reserved
# This work is licensed under the terms of the MIT license.
# For a copy, see <https://opensource.org/licenses/MIT>.
# ~~~

cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)
project(fastdtoa_example LANGUAGES CXX)
find_package(fastdtoa REQUIRED)
add_executable(fastdtoa_example ${CMAKE_CURRENT_SOURCE_DIR}/../fastdtoa_example.cpp)
target_link_libraries(fastdtoa_example PRIVATE fastdtoa::fastdtoa)
