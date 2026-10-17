#include "color_log.h"
#include <string.h>

void color_table(FILE* fileptr ){
    for (int i = 0; i < 108; i++){
        if (i % 9 == 0 && i != 0)
            fprintf(fileptr, "\n");
        fprintf(fileptr, "\033[%dm %3d\033[m", i, i);
    }
    fprintf(fileptr, "\n");
}

void fprint_col(FILE* fileptr, enum colors col, const char* format, ...){
    int i = 0;
    switch(col) {
        case DEFAULT:
        i=90;
        break;
        case SECTION:
        i=90;
        break;
        case HEADER:
        i=0;
        break;
        case TRAILER:
        i=3;
        break;
        case MEMORY:
        i=93;
        break;
        case LABEL:
        i=94;
        break;
        case NUMBER:
        i=92;
        break;
        case STRING:
        i=95;
    }
    fprintf(fileptr, "\033[%dm", i);

    va_list args;
    va_start(args, format);
    if (col == HEADER){
        char buf[21];
        vsnprintf(buf, 20, format, args);
        buf[20] = '\0';
        int size = strcspn(buf,"\0");

        fprintf(fileptr, "===");

        fprintf(fileptr, "%s",buf);
        fprintf(fileptr, " ");

        int i;
        for (i=0; i<20-size; i+=3) fprintf(fileptr, "===");
        fprintf(fileptr,
        "=================================\n");
    } else if (col == TRAILER) {
        char buf[21];
        vsnprintf(buf, 20, format, args);
        buf[20] = '\0';
        int size = strcspn(buf,"\0");

        fprintf(fileptr, "...");
        fprintf(fileptr, "%s",buf);
        fprintf(fileptr, " ");

        int i;
        for (i=0; i<20-size; i++) fprintf(fileptr, ".");
        fprintf(fileptr,
        ".................................\n");
    }else if (col == SECTION) {
        char buf[21];
        vsnprintf(buf, 20, format, args);
        buf[20] = '\0';
        int size = strcspn(buf,"\0");

        fprintf(fileptr, "***");
        fprintf(fileptr, "%s", buf);

        fprintf(fileptr, " ");
        int i;
        for (i=0; i<20-size; i+=1) fprintf(fileptr, "*");
        fprintf(fileptr, 
        "********************\n");
    } else {
        vfprintf(fileptr, format, args);
    }
    va_end(args);

    fprintf(fileptr, "\033[m");
}
