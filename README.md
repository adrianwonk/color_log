# color_log

`color_log` is a small C library for writing ANSI-colored log output.

The public header is `color_log.h`, and the CMake target is
`color_log::color_log`.

## Requirements

- CMake 3.15 or newer
- A C compiler with C99 support

## Install from source

```sh
cmake -S . -B build
cmake --build build
cmake --install build --prefix "$HOME/.local"
```

To install somewhere else, replace the value passed to `--prefix`:

```sh
cmake --install build --prefix /path/to/install
```

This installs the library, `color_log.h`, and CMake package files for use
with `find_package`.

## Use with FetchContent

Add this to the consuming project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    color_log
    GIT_REPOSITORY https://github.com/adrianwonk/color_log.git
    GIT_TAG main
)
FetchContent_MakeAvailable(color_log)

add_executable(my_app main.c)
target_link_libraries(my_app PRIVATE color_log::color_log)
```

When using a local checkout instead of Git, use `SOURCE_DIR`:

```cmake
FetchContent_Declare(
    color_log
    SOURCE_DIR /path/to/color_log
)
FetchContent_MakeAvailable(color_log)
```

## Use after installation

If the library was installed outside a system prefix, point CMake at the
installation prefix with `CMAKE_PREFIX_PATH`:

```sh
cmake -S . -B build \
    -DCMAKE_PREFIX_PATH=/path/to/install
```

Then link the package target from the consuming project's `CMakeLists.txt`:

```cmake
find_package(color_log CONFIG REQUIRED)

add_executable(my_app main.c)
target_link_libraries(my_app PRIVATE color_log::color_log)
```

Include the public header from C code:

```c
#include "color_log.h"

fprint_col(stdout, NUMBER, "value: %d\n", 42);
```
