// Copyright (C) Olivier Le Doeuff - All Rights Reserved
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#ifdef WIN32
#    ifdef FASTDTOA_SHARED // Shared build
#        define FASTDTOA_API_ __declspec(dllexport)
#    elif FASTDTOA_STATIC // No decoration when building staticlly
#        define FASTDTOA_API_
#    else // Link to lib
#        define FASTDTOA_API_ __declspec(dllimport)
#    endif
#else
#    define FASTDTOA_API_
#endif // WIN32
