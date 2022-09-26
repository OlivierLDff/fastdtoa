# ~~~
# Copyright (C) Olivier Le Doeuff - All Rights Reserved
# This work is licensed under the terms of the MIT license.
# For a copy, see <https://opensource.org/licenses/MIT>.
# ~~~

# ✅ fastdtoa_tests

set(FASTDTOA_TEST_TARGET ${FASTDTOA_TARGET}_tests)

message(STATUS "✅ Add Test: ${FASTDTOA_TEST_TARGET}")

add_executable(${FASTDTOA_TEST_TARGET} EXCLUDE_FROM_ALL)

target_sources(${FASTDTOA_TEST_TARGET} PRIVATE fastdtoa.tests.cpp)

get_target_property(FASTDTOA_TESTS_SRCS ${FASTDTOA_TEST_TARGET} SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${FASTDTOA_TESTS_SRCS})

target_link_libraries(
  ${FASTDTOA_TEST_TARGET}
  PRIVATE ${FASTDTOA_TARGET}
  PRIVATE gtest_main
)

set_target_properties(${FASTDTOA_TEST_TARGET} PROPERTIES FOLDER ${FASTDTOA_FOLDER_PREFIX}/Tests)
if(FASTDTOA_ENABLE_UNITY_BUILD)
  set_target_properties(${FASTDTOA_TEST_TARGET} PROPERTIES UNITY_BUILD ON)
endif()

add_test(NAME ${FASTDTOA_TEST_TARGET} COMMAND ${FASTDTOA_TEST_TARGET})
