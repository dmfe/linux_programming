/*-----------------------------------------------------------------------------
* File Name: file.c
* Purpose:
* Creation Date: 04-06-2020
* Last Modified: Thu 04 Jun 2020 03:45:42 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <fcntl.h>
#include <unistd.h>
#include "file.h"

char* read_file(const char* filename, size_t length) {
    char *buffer;
    int fd;
    ssize_t bytes_read;

    /* Allocate buffer */
    buffer = (char*) malloc(length);
    if (buffer == NULL) {
        return NULL;
    }

    /* Open file */
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        /* Failed to open the file */
        free(buffer);
        return NULL;
    }

    /* Data reading */
    bytes_read = read(fd, buffer, length);
    if (bytes_read != length) {
        /* Reading failed */
        free(buffer);
        close(fd);
        return NULL;
    }

    /* All good */
    close(fd);
    return buffer;
}
