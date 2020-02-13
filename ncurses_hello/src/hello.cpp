/*-----------------------------------------------------------------------------
* File Name: hello.cpp
* Purpose:
* Creation Date: 13-02-2020
* Last Modified: Thu 13 Feb 2020 10:50:16 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <ncurses.h>

int main () {
    initscr();
    printw("Hello world!\n");
    refresh();
    getch();
    endwin();

    return 0;
}
