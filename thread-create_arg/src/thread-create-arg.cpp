/*-----------------------------------------------------------------------------
* File Name: thread-create-arg.cpp
* Purpose:
* Creation Date: 07-06-2020
* Last Modified: Sun 07 Jun 2020 01:00:58 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <pthread.h>
#include <stdio.h>

struct char_print_params {
    char character;
    int count;
};

void *char_print(void *params) {
    struct char_print_params *p = (struct char_print_params*) params;

    for (int i = 0; i < p->count; ++i) {
        fputc(p->character, stderr);
    }

    return NULL;
}

int main() {

    pthread_t thread_one_id;
    struct char_print_params thread_one_params = {'x', 100};
    pthread_create(&thread_one_id, NULL, &char_print, &thread_one_params);

    pthread_t thread_two_id;
    struct char_print_params thread_two_params = {'o', 200};
    pthread_create(&thread_two_id, NULL, &char_print, &thread_two_params);

    pthread_join(thread_one_id, NULL);
    pthread_join(thread_two_id, NULL);

    return 0;
}
