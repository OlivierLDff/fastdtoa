// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include <fastdtoa/fastdtoa.hpp>
#include <gtest/gtest.h>
#include <limits>

namespace fastdtoa {
namespace tests {

TEST(fastdtoa, to_string)
{
    ASSERT_EQ(fastdtoa::to_string(12.), "12");
    ASSERT_EQ(fastdtoa::to_string(-12.), "-12");
    ASSERT_EQ(fastdtoa::to_string(12.1), "12.1");
    ASSERT_EQ(fastdtoa::to_string(-12.1), "-12.1");
    ASSERT_EQ(fastdtoa::to_string(0.123100034), "0.123100034");
    ASSERT_EQ(fastdtoa::to_string(1000000000000000000.), "1e+18");
    ASSERT_EQ(fastdtoa::to_string(std::numeric_limits<double>::quiet_NaN()), "NaN");
    ASSERT_EQ(fastdtoa::to_string(std::numeric_limits<double>::infinity()), "Inf");
}

}
}
