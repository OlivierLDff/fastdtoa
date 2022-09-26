set(FASTDTOA_VERSION_MAJOR 1)
set(FASTDTOA_VERSION_MINOR 0)
set(FASTDTOA_VERSION_PATCH 1)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
  execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE FASTDTOA_VERSION_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
endif()

if(NOT FASTDTOA_VERSION_TAG)
  set(FASTDTOA_VERSION_TAG 00000000)
endif(NOT FASTDTOA_VERSION_TAG)
set(FASTDTOA_VERSION_TAG_HEX 0x${FASTDTOA_VERSION_TAG})
set(FASTDTOA_VERSION ${FASTDTOA_VERSION_MAJOR}.${FASTDTOA_VERSION_MINOR}.${FASTDTOA_VERSION_PATCH})
