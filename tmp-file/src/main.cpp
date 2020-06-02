/*-----------------------------------------------------------------------------
* File Name: main.cpp
* Purpose:
* Creation Date: 03-06-2020
* Last Modified: Wed 03 Jun 2020 02:42:10 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <errno.h>
#include "tmp.h"

const char* program_name;

void print_usage(FILE* stream, int exit_code) {
    fprintf(stream, "Usage: %s options\n"
                    " -h --help   Displays this usage info.\n"
                    " -b --buffer String which goes to tmp file.\n"
                    " -f --file   File, which content goes to buffer.\n",
                    program_name);
    exit(exit_code);
}

int main(int argc, char* argv[]) {

    int next_option;

    const char* const short_options = "hb:f:";
    const struct option long_options[] = {
        { "help",   0, NULL, 'h'},
        { "buffer", 1, NULL, 'b'},
        { "file",   1, NULL, 'f'},
        { NULL,     0, NULL, 0}
    };

    const char* buffer = NULL;
    const char* file_name = NULL;

    program_name = argv[0];

    do {
        next_option = getopt_long(argc, argv, short_options,
                                  long_options, NULL);

        switch (next_option) {
            case 'h':
                print_usage(stdout, 0);
            case 'b':
                buffer = optarg;
                break;
            case 'f':
                file_name = optarg;
                break;
            case '?':
                print_usage(stderr, 1);
            case -1:
                break;
            default:
                abort();
        }
    } while (next_option != -1);

    if (!buffer && !file_name) {
        fprintf(stderr, "You should specify buffer or filename.\n");
        print_usage(stderr, 1);
    }
    if (buffer && file_name) {
        fprintf(stderr, "Not allowed to specify buffer and filename "
                       "at the same time.\n");
        print_usage(stderr, 1);
    }

    if (buffer) {
        write_temp_file(buffer, strlen(buffer));
    } else {
        int file = open(file_name, O_RDONLY);
        if (file == -1) {
            fprintf(stderr, "Unable to open the file: %s\n", strerror(errno));
            exit(1);
        }

        size_t length;
        const char* buffer = read_temp_file(file, &length);

        printf("The buffer content is:\n%s", buffer);
    }

    return 0;
}
