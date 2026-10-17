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

## Use as a Git dependency with FetchContent

The simplest way to use `color_log` is to let the consuming CMake project
download and build it. Pin `GIT_TAG` to a release tag (or a commit) so builds
remain reproducible:

Add this to the consuming project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    color_log
    GIT_REPOSITORY https://github.com/adrianwonk/color_log.git
    GIT_TAG v0.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(color_log)

add_executable(my_app main.c)
target_link_libraries(my_app PRIVATE color_log::color_log)
```

The `color_log::color_log` target exposes the public include directory and
requires C99. No separate installation step is needed.

For a local checkout, use `SOURCE_DIR` instead of `GIT_REPOSITORY` and
`GIT_TAG`:

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
