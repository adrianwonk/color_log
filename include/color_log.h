#pragma once
#include <stdarg.h>
#include <stdio.h>
enum colors{
    DEFAULT,
    HEADER,
    SUBHEADER,
    TRAILER,
    SUBTRAILER,
    SECTION,
    MEMORY,
    LABEL,
    NUMBER,
    STRING
};

void color_table(FILE* fileptr );
void fprint_col(FILE* fileptr, enum colors col, const char* format, ...);
