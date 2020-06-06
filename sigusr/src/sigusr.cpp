/*-----------------------------------------------------------------------------
* File Name: sigusr.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 12:48:28 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler(int signal_number) {
    ++sigusr1_count;
}

int main() {

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    sigaction(SIGUSR1, &sa, NULL);

    while (sigusr1_count < 3) {
        sleep(1);
    }

    printf("SIGUSR1 was raised %d times\n", sigusr1_count);
    return 0;
}
