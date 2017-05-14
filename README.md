# Function Draw
Function drawing library for C++11 programming course.

The program supports the four basic operations and parentheses.

# Build
## Dependencies
The program uses [Boost](http://www.boost.org) (1.55 or newer)
and [CMake](https://cmake.org/) (3.0.2 or newer).

## Linux
The program can be built simply by running the `build.sh` script.

The project uses CMake as its build system. It can be built manually like this:
```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```
After the project is built the executable is in the `[build_dir]/exp2svg/Expression2SVG` directory.

## Windows
On Windows the project can be built with CMake and Visual Studio.
You may also need to specify the location of Boost in the `BOOST_ROOT` CMake variable.

# Usage
After running Expression2SVG you can enter as many mathematical expressions as you like. To end the list enter an empty line.
Then you can specify the range of the X axis (the range of the Y axis is calculated to fit all lines). Finally specify the size and name of the svg file to save it.

# Unit tests
The unit tests can be built by enabling the `BUILD_TESTS` CMake variable. CMake then automatically downloads the Google Test framework. After the project is built the tests can be run with the `test/UnitTest` executable.
