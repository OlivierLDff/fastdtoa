# ~~~
# Copyright (C) Olivier Le Doeuff - All Rights Reserved
# This work is licensed under the terms of the MIT license.
# For a copy, see <https://opensource.org/licenses/MIT>.
# ~~~

cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)

# ──── Include guards ────

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR "In-source builds not allowed. "
                "Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# ──── Main Project behavior ────

set(FASTDTOA_MAIN_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(FASTDTOA_MAIN_PROJECT ON)
endif()

# ──── Default build to Release ────

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose Release or Debug" FORCE
  )
endif()

include(cmake/Dependencies.cmake)

# ───── 🔧 Configuration ─────

set(FASTDTOA_TARGET
    "fastdtoa"
    CACHE STRING "Target Name"
)

set(FASTDTOA_PROJECT
    "fastdtoa"
    CACHE STRING "Project Name"
)

set(FASTDTOA_BUILD_SHARED
    OFF
    CACHE BOOL "Build as a shared library"
)

set(FASTDTOA_FOLDER_PREFIX
    ""
    CACHE STRING
          "Prefix folder for all fastdtoa generated targets in generated project (only decorative)"
)

set(FASTDTOA_ENABLE_TESTS
    ${FASTDTOA_MAIN_PROJECT}
    CACHE BOOL "Create or not a target for test (compatible with CTests)"
)

set(FASTDTOA_ENABLE_EXAMPLES
    ${FASTDTOA_MAIN_PROJECT}
    CACHE BOOL "Create or not a target for test (compatible with CTests)"
)

set(FASTDTOA_ENABLE_UNITY_BUILD
    ON
    CACHE BOOL "fastdtoa source files will be combined into batches for faster compilation."
)

set(FASTDTOA_ENABLE_POSITION_INDEPENDENT_CODE
    ON
    CACHE BOOL
          "Determines whether position independent executables or shared libraries will be created."
)

set(FASTDTOA_VERBOSE
    ${FASTDTOA_MAIN_PROJECT}
    CACHE BOOL "Log Verbose configuration"
)

set(FASTDTOA_ENABLE_INSTALL
    ${FASTDTOA_MAIN_PROJECT}
    CACHE BOOL "Create an install target."
)

# ───── 🚀 Project ─────

include(cmake/Version.cmake)

project(
  ${FASTDTOA_PROJECT}
  VERSION ${FASTDTOA_VERSION}
  LANGUAGES CXX
)

if(FASTDTOA_MAIN_PROJECT)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# ───── 🔊 Log config ─────

if(FASTDTOA_VERBOSE)
  message(STATUS "------ ${FASTDTOA_TARGET} Configuration ------")
  message(STATUS "FASTDTOA_BUILD_SHARED           : ${FASTDTOA_BUILD_SHARED}")
  message(STATUS "FASTDTOA_VERSION                : ${FASTDTOA_VERSION}")
  message(STATUS "FASTDTOA_VERSION_TAG_HEX        : ${FASTDTOA_VERSION_TAG_HEX}")
  message(STATUS "FASTDTOA_FOLDER_PREFIX          : ${FASTDTOA_FOLDER_PREFIX}")
  message(STATUS "FASTDTOA_ENABLE_UNITY_BUILD     : ${FASTDTOA_ENABLE_UNITY_BUILD}")
  message(
    STATUS
      "FASTDTOA_ENABLE_POSITION_INDEPENDENT_CODE : ${FASTDTOA_ENABLE_POSITION_INDEPENDENT_CODE}"
  )
  message(STATUS "FASTDTOA_ENABLE_TESTS           : ${FASTDTOA_ENABLE_TESTS}")
  message(STATUS "FASTDTOA_ENABLE_EXAMPLES        : ${FASTDTOA_ENABLE_EXAMPLES}")
  message(STATUS "FASTDTOA_ENABLE_INSTALL         : ${FASTDTOA_ENABLE_INSTALL}")
  message(STATUS "------ ${FASTDTOA_TARGET} End Configuration ------")
endif()

# ───── Add dependencies ─────

if(FASTDTOA_ENABLE_TESTS)
  include(cmake/FetchGTest.cmake)
endif()

if(FASTDTOA_MAIN_PROJECT)
  include(cmake/tools.cmake)
endif()

if(${FASTDTOA_ENABLE_INSTALL})
  include(GNUInstallDirs) # For CMAKE_INSTALL_INCLUDEDIR
endif()

# ───── fastdtoa::fastdtoa ─────

if(FASTDTOA_BUILD_SHARED)
  add_library(${FASTDTOA_TARGET} SHARED)
  target_compile_definitions(${FASTDTOA_TARGET} PRIVATE -DFASTDTOA_SHARED)
else()
  add_library(${FASTDTOA_TARGET} STATIC)
  target_compile_definitions(${FASTDTOA_TARGET} PUBLIC -DFASTDTOA_STATIC)
endif()

add_library(fastdtoa::fastdtoa ALIAS ${FASTDTOA_TARGET})

target_compile_features(${FASTDTOA_TARGET} PUBLIC cxx_std_11)
target_include_directories(
  ${FASTDTOA_TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_compile_definitions(
  ${FASTDTOA_TARGET} PRIVATE -DFASTDTOA_VERSION_MAJOR=${FASTDTOA_VERSION_MAJOR}
)
target_compile_definitions(
  ${FASTDTOA_TARGET} PRIVATE -DFASTDTOA_VERSION_MINOR=${FASTDTOA_VERSION_MINOR}
)
target_compile_definitions(
  ${FASTDTOA_TARGET} PRIVATE -DFASTDTOA_VERSION_PATCH=${FASTDTOA_VERSION_PATCH}
)
target_compile_definitions(
  ${FASTDTOA_TARGET} PRIVATE -DFASTDTOA_VERSION_TAG=${FASTDTOA_VERSION_TAG}
)
target_compile_definitions(
  ${FASTDTOA_TARGET} PRIVATE -DFASTDTOA_VERSION_TAG_HEX=${FASTDTOA_VERSION_TAG_HEX}
)

if(FASTDTOA_FOLDER_PREFIX)
  set_target_properties(${FASTDTOA_TARGET} PROPERTIES FOLDER ${FASTDTOA_FOLDER_PREFIX})
endif()

if(FASTDTOA_ENABLE_UNITY_BUILD)
  set_target_properties(${FASTDTOA_TARGET} PROPERTIES UNITY_BUILD ON)
endif()

if(FASTDTOA_ENABLE_POSITION_INDEPENDENT_CODE)
  set_target_properties(${FASTDTOA_TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()

target_sources(
  ${FASTDTOA_TARGET}
  PRIVATE src/fastdtoa/fastdtoa.hpp
  PRIVATE src/fastdtoa/fastdtoa.cpp
  PRIVATE src/fastdtoa/export.hpp
  PRIVATE src/fastdtoa/version.hpp
  PRIVATE src/fastdtoa/version.cpp
)
get_target_property(FASTDTOA_SRCS ${FASTDTOA_TARGET} SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src/fastdtoa" FILES ${FASTDTOA_SRCS})

# ───── Add ✅ Tests ─────

if(FASTDTOA_ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# ───── Add 🚀 Samples ─────

if(FASTDTOA_ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

# ───── 📦️ Package Project ─────

if(FASTDTOA_ENABLE_INSTALL)

  CPMAddPackage("gh:OlivierLDff/PackageProject.cmake@1.9.0")

  packageProject(
    NAME fastdtoa
    VERSION ${PROJECT_VERSION}
    BINARY_DIR ${PROJECT_BINARY_DIR}
    INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src
    INCLUDE_DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    INCLUDE_HEADER_PATTERN "*.hpp"
    NAMESPACE fastdtoa
    COMPATIBILITY SameMinorVersion
  )

endif()

# ───── 🔊 Log dev command and info ─────

if(FASTDTOA_MAIN_PROJECT)

  message(STATUS "")
  message(STATUS "🎉 ${CMAKE_PROJECT_NAME} v${${CMAKE_PROJECT_NAME}_VERSION} Configuration Done 🎉")
  message(STATUS "")

  message(STATUS "🔨 Build Commands:")
  message(
    STATUS
      "  fastdtoa              : cmake --build . --target ${FASTDTOA_TARGET} --config ${CMAKE_BUILD_TYPE} ${PARALLEL_LEVEL}"
  )

  if(FASTDTOA_ENABLE_TESTS)
    message(STATUS "")
    message(STATUS "✅ Tests Commands:")
    message(STATUS "  Run Tests             : ctest -C ${CMAKE_BUILD_TYPE} . --verbose --progress")
  endif()

  if(TARGET ${FASTDTOA_TARGET}_tests)
    message(
      STATUS
        "  fastdtoa_tests        : cmake --build . --target ${FASTDTOA_TARGET}_tests --config ${CMAKE_BUILD_TYPE} ${PARALLEL_LEVEL}"
    )
  endif()

  if(FASTDTOA_ENABLE_TESTS)
    message(STATUS "")
    message(STATUS "🚀 Samples Commands:")
  endif()

  if(TARGET ${FASTDTOA_TARGET}_example)
    message(
      STATUS
        "  fastdtoa_example      : cmake --build . --target ${FASTDTOA_TARGET}_example --config ${CMAKE_BUILD_TYPE} ${PARALLEL_LEVEL}"
    )
  endif()

  if(FASTDTOA_ENABLE_INSTALL)
    message(STATUS "")
    message(
      STATUS
        "📦️ Install              : cmake --build . --target install --config ${CMAKE_BUILD_TYPE} "
    )
  endif()

  message(STATUS "")

endif()
