// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include <fastdtoa/export.hpp>
#include <fastdtoa/version.hpp>

namespace fastdtoa {

/*!
The format of the resulting decimal representation is similar to printf's %g
format. Returns an iterator pointing past-the-end of the decimal representation.
@note The input number must be finite, i.e. NaN's and Inf's are not supported.
@note The buffer must be large enough.
@note The result is NOT null-terminated.
@throw std::invalid_argument if value is not finite
*/
char* FASTDTOA_API_ to_chars(char* first, const char* last, double value);

/*!
The format of the resulting decimal representation is similar to printf's %g
format.
 */
std::string to_string(double value);

/*!
The format of the resulting decimal representation is similar to printf's %g
format.
 */
inline std::string to_string(float value)
{
    return to_string(static_cast<double>(value));
}

}
