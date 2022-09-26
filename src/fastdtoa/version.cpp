// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include <fastdtoa/version.hpp>

namespace fastdtoa {

namespace details {

static const std::string VERSION_STR = std::to_string(FASTDTOA_VERSION_MAJOR) + "."
                                       + std::to_string(FASTDTOA_VERSION_MINOR) + "."
                                       + std::to_string(FASTDTOA_VERSION_PATCH);

#define xstr(s) str(s)
#define str(s) #s

static const std::string SHA_STR = xstr(FASTDTOA_VERSION_TAG_HEX);

#undef xstr
#undef str

}

std::uint8_t versionMajor()
{
    return FASTDTOA_VERSION_MAJOR;
}

std::uint8_t versionMinor()
{
    return FASTDTOA_VERSION_MINOR;
}

std::uint8_t versionPatch()
{
    return FASTDTOA_VERSION_PATCH;
}

std::uint32_t versionTag()
{
    return FASTDTOA_VERSION_TAG_HEX;
}

std::string version()
{
    return details::VERSION_STR;
}

std::string sha()
{
    return details::SHA_STR;
}

}
