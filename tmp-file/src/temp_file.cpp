/*-----------------------------------------------------------------------------
* File Name: temp_file.cpp
* Purpose:
* Creation Date: 13-02-2020
* Last Modified: Thu 13 Feb 2020 12:21:38 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <unistd.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(char* buffer, size_t lenght) {
    char temp_file_name[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_file_name);
    unlink(temp_file_name);

    write (fd, &lenght, sizeof(lenght));
    write (fd, buffer, lenght);

    return fd;
}

char* read_temp_file (temp_file_name temp_file, size_t* lenght) {
    char* buffer;
    int fd = temp_file;

    lseek (fd, 0, SEEK_SET);
    read (fd, lenght, sizeof (*lenght));
    buffer = (char*) malloc (*lenght);
    read (fd, buffer, *lenght);

    close(fd);
    return buffer;
}
