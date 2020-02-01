/*-----------------------------------------------------------------------------
* File Name: print-env.cpp
* Purpose:
* Creation Date: 01-02-2020
* Last Modified: Sat 01 Feb 2020 11:16:10 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>

extern char** environ;

int main (int argc, char* argv[]) {
    char** var;

    for (var = environ; *var != NULL; ++var) {
        printf ("%s\n", *var);
    }

    return 0;
}
