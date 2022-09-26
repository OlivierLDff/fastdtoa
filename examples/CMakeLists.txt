# ~~~
# Copyright (C) Olivier Le Doeuff - All Rights Reserved
# This work is licensed under the terms of the MIT license.
# For a copy, see <https://opensource.org/licenses/MIT>.
# ~~~

set(FASTDTOA_EXAMPLE_TARGET ${FASTDTOA_TARGET}_example)
message(STATUS "🚀 Add Example: ${FASTDTOA_EXAMPLE_TARGET}")
add_executable(${FASTDTOA_EXAMPLE_TARGET} EXCLUDE_FROM_ALL fastdtoa_example.cpp)
target_link_libraries(${FASTDTOA_EXAMPLE_TARGET} PRIVATE ${FASTDTOA_TARGET})
set_target_properties(
  ${FASTDTOA_EXAMPLE_TARGET} PROPERTIES FOLDER ${FASTDTOA_FOLDER_PREFIX}/Examples
)
