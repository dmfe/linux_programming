/*-----------------------------------------------------------------------------
* File Name: tsd.cpp
* Purpose:
* Creation Date: 13-06-2020
* Last Modified: Sat 13 Jun 2020 09:14:44 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <malloc.h>
#include <pthread.h>
#include <stdio.h>

/* The key, which links journal file pointer with the current thread. */
static pthread_key_t thread_log_key;

/* Writes message to the journal file ot the current thread. */
void write_to_thread_log(const char *message) {
    FILE *thread_log = (FILE*) pthread_getspecific(thread_log_key);
    fprintf(thread_log, "%s\n", message);
}

/* Closes the journal file of the particular thread. */
void close_thread_log(void *log) {
    FILE *thread_log = (FILE*) log;
    fprintf(thread_log, "Closing thread log...\n");
    fclose(thread_log);
}

void* thread_function(void *args) {
    char thread_log_filename[20];
    FILE *thread_log;

    /* Creating the name of the journal file of the particular thread. */
    sprintf(thread_log_filename, "thread%d.log", (int) pthread_self());

    /* Opening of the journal file.  */
    thread_log = fopen(thread_log_filename, "w");

    /* Saving the pointer of the journal file to the thread data area.  */
    pthread_setspecific(thread_log_key, thread_log);

    char log_msg[50];
    sprintf(log_msg, "Thread %d starting...", (int) pthread_self());
    write_to_thread_log(log_msg);

    return NULL;
}

int main() {

    pthread_t threads[5];

    /* Creation of the key, which will link journal files pointers with
       the thread data area. Function 'close_thread_log' will close all
       the journal files.
    */
    pthread_key_create(&thread_log_key, &close_thread_log);

    /* Threads creation */
    for (int i = 0; i < 5; ++i) {
        pthread_create(&(threads[i]), NULL, &thread_function, NULL);
    }

    /* Waiting for all the threads. */
    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
