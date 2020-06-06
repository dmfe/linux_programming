/*-----------------------------------------------------------------------------
* File Name: main.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 03:43:58 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <sys/wait.h>
#include "process.h"

int main(int argc, char* argv[]) {

    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    //create_process_system();
    create_process_fork_exec("ls", arg_list);

    int child_state;
    wait(&child_state);
    if (WIFEXITED(child_state)) {
        printf("The child process exited normally, with exit code:"
                " %d\n", WEXITSTATUS(child_state));
    } else {
        printf("The child process exited abnormally\n");
    }

    printf("done with main program\n");
    return 0;
}
