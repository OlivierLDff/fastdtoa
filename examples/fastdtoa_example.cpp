// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include <fastdtoa/fastdtoa.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "1 + 2 = " << fastdtoa::add(1, 2) << std::endl;
}
