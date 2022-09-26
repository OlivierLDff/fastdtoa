// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include <fastdtoa/export.hpp>
#include <cstdint>
#include <string>

namespace fastdtoa {

std::uint8_t FASTDTOA_API_ versionMajor();
std::uint8_t FASTDTOA_API_ versionMinor();
std::uint8_t FASTDTOA_API_ versionPatch();
std::uint32_t FASTDTOA_API_ versionTag();
std::string FASTDTOA_API_ version();
std::string FASTDTOA_API_ sha();

}
