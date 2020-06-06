/*-----------------------------------------------------------------------------
* File Name: process.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 11:48:11 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "process.h"

int create_process_system() {
    return system("ls -l /");
}

int create_process_fork_exec(char* program, char** arg_list) {
    pid_t child_pid;

    /* Create the copy of the current process. */
    child_pid = fork();
    if (child_pid != 0) {
        /* It is the parent process. */
        return child_pid;
    } else {
        /* Run specified programm. */
        execvp(program, arg_list);
        /* Function execvp returns some value only in case of error. */
        fprintf(stderr, "An error occured in execvp\n");
        abort();
    }
}
