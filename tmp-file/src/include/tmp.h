/*-----------------------------------------------------------------------------
* File Name: tmp.h
* Purpose:
* Creation Date: 03-06-2020
* Last Modified: Wed 03 Jun 2020 01:46:28 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _TMP_H_
#define _TMP_H_

#include <stdlib.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(const char* buffer, size_t length);

char* read_temp_file (temp_file_handle temp_file, size_t* length);

#endif
