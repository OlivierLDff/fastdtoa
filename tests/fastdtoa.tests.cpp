// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include <fastdtoa/fastdtoa.hpp>
#include <gtest/gtest.h>

namespace fastdtoa {
namespace tests {

TEST(fastdtoa, add)
{
    ASSERT_EQ(add(4, 8), 12);
}

}
}
