/*-----------------------------------------------------------------------------
* File Name: main.c
* Purpose:
* Creation Date: 04-06-2020
* Last Modified: Thu 04 Jun 2020 04:06:16 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include "file.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "You need to specify filename.\n");
    }

    const char* filename = argv[1];

    char* buffer = read_file(filename, 5);
    printf("Buffer content is: %s\n", buffer);

    return 0;
}
