/*-----------------------------------------------------------------------------
* File Name: temp_file.cpp
* Purpose:
* Creation Date: 13-02-2020
* Last Modified: Tue 02 Jun 2020 04:07:54 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(char* buffer, size_t length) {
    /* Filename and the file itself creation. Sequence XXXXXX
       will be substitude with symbols, which will make
       name of temp file unique. */
    char temp_file_name[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_file_name);

    /* Deleting of the file link. By doing this file will
       deleted just after the descriptor of the file will be closed. */
    //unlink(temp_file_name);

    /* First the number, which determines the size of the buffer,
       is written */
    write (fd, &length, sizeof(length));
    /* Now write the data itself. */
    write (fd, buffer, length);

    /* Return file descriptor. */
    return fd;
}

char* read_temp_file (temp_file_handle temp_file, size_t* length) {
    char* buffer;

    /* This is the descriptor of the temp file. */
    int fd = temp_file;

    /* Go to the begging of the file. */
    lseek (fd, 0, SEEK_SET);
    /* Determine the size of the data, which is in temp file. */
    read (fd, length, sizeof(*length));
    buffer = (char*) malloc (*length);
    read (fd, buffer, *length);

    /* Closing temp file, which will lead to destroying the file. */
    close(fd);
    return buffer;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        fprintf(stderr, "You need to provide data to write to temp file.\n");
        exit(1);
    }

    char* buffer = argv[1];

    write_temp_file(buffer, strlen(buffer));
}
