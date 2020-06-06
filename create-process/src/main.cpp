/*-----------------------------------------------------------------------------
* File Name: main.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 11:52:45 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include "process.h"

int main(int argc, char* argv[]) {

    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    create_process_system();
    create_process_fork_exec("ls", arg_list);

    printf("done with main program\n");

    return 0;
}
