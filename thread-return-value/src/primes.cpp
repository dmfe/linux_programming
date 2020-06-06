/*-----------------------------------------------------------------------------
* File Name: primes.cpp
* Purpose:
* Creation Date: 07-06-2020
* Last Modified: Sun 07 Jun 2020 02:14:29 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *compute_prime(void *arg) {

    int candidate = 1;
    int n = *((int*) arg);

    while (1) {
        int is_prime = 1;

        for (int factor = 2; factor < candidate; ++factor) {
            if (!(candidate % factor)) {
                is_prime = 0;
                break;
            }

        }

        if (is_prime) {
            if (--n == 0) {
                return (void*) candidate;
            }
        }
        ++candidate;
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    pthread_t prime_thread;
    int prime_num = 5000;
    int prime;

    if (argc > 1) {
        prime_num = atoi(argv[1]);
    }

    pthread_create(&prime_thread, NULL, &compute_prime, &prime_num);
    pthread_join(prime_thread, (void**) &prime);

    printf("The %dth prime number is %d.\n", prime_num, prime);

    return 0;
}
