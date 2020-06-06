/*-----------------------------------------------------------------------------
* File Name: process.h
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 11:53:21 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _PROCESS_H_
#define _PROCESS_H_

int create_process_system();
int create_process_fork_exec(char* program, char** arg_list);

#endif
