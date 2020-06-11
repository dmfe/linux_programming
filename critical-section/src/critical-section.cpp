/*-----------------------------------------------------------------------------
* File Name: critical-section.cpp
* Purpose:
* Creation Date: 11-06-2020
* Last Modified: Thu 11 Jun 2020 10:16:12 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <pthread.h>
#include <stdio.h>
#include <string.h>

float *account_balances;

int process_transaction(int from_acc, int to_acc, float ammount) {
    int old_state;

    if (account_balances[from_acc] < ammount) {
        return 1;
    }

    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_state);

    account_balances[to_acc] += ammount;
    account_balances[from_acc] -= ammount;

    pthread_setcancelstate(old_state, NULL);
}

int main() {

    return 0;
}
