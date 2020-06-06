/*-----------------------------------------------------------------------------
* File Name: sigchld.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 10:55:31 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t child_exit_status = 0;

void cleanup_child_process(int signal_num) {
    /* Deleting child process */
    int status;
    wait(&status);
    /* Storing child process status in global variable */
    child_exit_status = status;
}

int main() {
    /* Handle SIGCHLD signal by calling fuction cleanup_child_process */
    struct sigaction sigchld_action;
    memset(&sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = &cleanup_child_process;
    sigaction(SIGCHLD, &sigchld_action, NULL);

    pid_t child_pid = fork();
    if (child_pid > 0) {
        sleep(3);
        if (WIFEXITED(child_exit_status)) {
            printf("The child process exited normally with exit code:"
                   " %d\n", WEXITSTATUS(child_exit_status));
        } else {
            fprintf(stderr, "The child process exited abnormally.\n");
        }
    } else {
        exit(2);
    }

    return 0;
}
