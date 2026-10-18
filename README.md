# color_log

`color_log` is a small C library for writing ANSI-colored log output.
It notably has an auto line drawer for HEADER, TRAILER, and SECTION.

It provides the fprint_col(FILE*, struct color, char *format, ...);
function, using ANSI escape codes to beautify log statements.

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

The simplest way to use `color_log` is via CMake.

Add this to the project's `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.15)
project(ProjectName)

include(FetchContent)

FetchContent_Declare(
    color_log
    GIT_REPOSITORY https://github.com/adrianwonk/color_log.git
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(color_log)

add_executable(main main.c)
target_link_libraries(main PRIVATE color_log::color_log)
```

## Use after installation

```c
#include "color_log.h"
int main(){
fprint_col(stdout, HEADER, "the %dth header limited to 20 chars", 1);
fprint_col(stderr, STRING, "hi, this is my string.\n");
fprint_col(stdout, SECTION, "section 1");
fprint_col(stderr, LABEL, "value of my x variable: ");
fprint_col(stderr, NUMBER, "%d", 42);
fprint_col(stdout, TRAILER, "end. Limited to 20 chars");
return 0;
}
```
