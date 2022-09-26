// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include <fastdtoa/fastdtoa.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "12 = " << fastdtoa::to_string(12.) << std::endl;
    std::cout << "-12.1 = " << fastdtoa::to_string(-12.1) << std::endl;
    std::cout << "0.123100034 = " << fastdtoa::to_string(0.123100034) << std::endl;
    std::cout << "1000000000000000000 = " << fastdtoa::to_string(1e+18) << std::endl;
}
