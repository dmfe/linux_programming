/*-----------------------------------------------------------------------------
* File Name: zombie.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 04:13:35 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main () {

    pid_t child_pid;
    child_pid = fork();
    if (child_pid > 0) {
        /* This is a parent process. */
        sleep(60);
    } else {
        /* This is a child process. */
        exit(0);
    }

    return 0;
}
