/*-----------------------------------------------------------------------------
* File Name: thread-create.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sun 07 Jun 2020 12:19:29 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <pthread.h>
#include <stdio.h>

void *print_xs(void *unused) {

    while (1) {
        fputc('x', stderr);
    }
}

int main() {

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &print_xs, NULL);

    while (1) {
        fputc('o', stderr);
    }

    return 0;
}
