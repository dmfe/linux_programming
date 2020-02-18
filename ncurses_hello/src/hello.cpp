/*-----------------------------------------------------------------------------
* File Name: hello.cpp
* Purpose:
* Creation Date: 13-02-2020
* Last Modified: Wed 19 Feb 2020 01:45:05 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <ncurses.h>

int main () {

    initscr();
    cbreak();
    noecho();

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;

    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "This is my box");
    wrefresh(win);

    getch();
    getch();

    endwin();

    return 0;
}
