/*-----------------------------------------------------------------------------
* File Name: client.cpp
* Purpose:
* Creation Date: 01-02-2020
* Last Modified: Sat 01 Feb 2020 11:24:46 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main () {

    char* server_name = getenv ("SERVER_NAME");
    if (server_name == NULL) {
        server_name = "server.my-company.com";
    }

    printf ("accessing server %s\n", server_name);

    return 0;
}
