# fastdtoa

<p align="left">
    <a href="https://isocpp.org/">
        <img src="https://img.shields.io/badge/language-C%2B%2B17-blue.svg">
    </a>
    <a href="https://gitmoji.dev/">
        <img src="https://img.shields.io/badge/gitmoji-%20😜%20😍-FFDD67.svg?style=flat-square">
    </a>
    <a href="https://github.com/OlivierLDff/fastdtoa/actions/workflows/unit-tests.yml">
        <img src="https://github.com/OlivierLDff/fastdtoa/actions/workflows/unit-tests.yml/badge.svg">
    </a>
</p>

Implements the Grisu2 algorithm for binary to decimal floating-point conversion.
This project source code is copied from [simdkson/.../to_chars.cpp](https://github.com/simdjson/simdjson/blob/master/src/to_chars.cpp). It is extracted into a standalone a library for convenience.

### ✨ Features


## 🚀 Usage

```cpp
#include <fastdtoa/fastdtoa.hpp>

int main(int argc, char* argv[])
{
    std::cout << "12 = " << fastdtoa::to_string(12.) << std::endl;
    std::cout << "-12.1 = " << fastdtoa::to_string(-12.1) << std::endl;
    std::cout << "0.123100034 = " << fastdtoa::to_string(0.123100034) << std::endl;
    std::cout << "1000000000000000000 = " << fastdtoa::to_string(1e+18) << std::endl;
}

// Output:
// 12 = 12
// -12.1 = -12.1
// 0.123100034 = 0.123100034
// 1000000000000000000 = 1e+18
```

> Example can be found in [examples/fastdtoa_example.cpp](./examples/fastdtoa_example.cpp).

## 🔨 Build

```bash
# ⬇️ Download project from Github
git clone https://github.com/OlivierLDff/fastdtoa
cd fastdtoa

# 🔧 Configure project
cmake -E make_directory build
cmake \
  -DFASTDTOA_ENABLE_TESTS=ON   `# ✅ Enable Tests (fastdtoa_tests)` \
  -DFASTDTOA_ENABLE_EXAMPLES=ON `# 🚀 Enable Examples (fastdtoa_example)` \
  -DFASTDTOA_ENABLE_INSTALL=ON `# 📦️ Enable Install` \
  -B build -S .

# 🔨 Build:
cmake --build build --target fastdtoa --config Release -j12
cmake --build build --target fastdtoa_tests --config Release -j12
cmake --build build --target fastdtoa_example --config Release -j12

# ✅ Run Unit Tests:
cd build
ctest -C Release . --verbose --progress
cd ..

# 📦️ Install library (You can control installation path with -DCMAKE_INSTALL_PREFIX=mypath)
cmake --build . --target install
```

### Extra flags

* `CPM_SOURCE_CACHE`: Share CPM download with multiple build. [More info.](https://github.com/cpm-cmake/CPM.cmake#CPM_SOURCE_CACHE)
* `USE_CCACHE`: Enable ccache for faster build/rebuild. [More info.](https://github.com/TheLartians/Ccache.cmake#ccachecmake)
* `USE_SANITIZER`: Sanitizers are tools that perform checks during a program’s runtime and returns issues, and as such, along with unit testing, code coverage and static analysis, is another tool to add to the programmers toolbox. [More info](https://github.com/StableCoder/cmake-scripts#sanitizer-builds-sanitizerscmake)
* `USE_STATIC_ANALYZER`: clang-tidy, include-what-you-use, cppcheck [More info](https://github.com/StableCoder/cmake-scripts#tools-toolscmake)
* `USE_FORMAT`: Enable format target [More info](https://github.com/TheLartians/Format.cmake#formatcmake)
* `CMAKE_INSTALL_PREFIX`: Select where installation should happen. [More info](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html)

### Use in your project

#### CPM

When using CPM, adding `fastdtoa` to your project is as simple as:

```cmake
CPMAddPackage(
  NAME fastdtoa
  GIT_REPOSITORY "https://github.com/OlivierLDff/fastdtoa"
  GIT_TAG "v1.0.0"
)
target_link_libraries(mytarget PRIVATE fastdtoa::fastdtoa)
```

#### find_package

One the library is installed you can simply:

```cmake
find_package(fastdtoa)
target_link_libraries(mytarget PRIVATE fastdtoa::fastdtoa)
```

Complete example can be found in [examples/install](./examples/install/CMakeLists.txt).

## 💅 Format

* [clang-format](https://github.com/llvm/llvm-project/releases/tag/llvmorg-12.0.1) : format cpp
* [cmake-format](https://github.com/cheshirekow/cmake_format) : format cmake

## 👥 Authors

* [Olivier Le Doeuff](olivier.ldff@gmail.com)
