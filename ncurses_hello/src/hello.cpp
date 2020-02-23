/*-----------------------------------------------------------------------------
* File Name: hello.cpp
* Purpose:
* Creation Date: 13-02-2020
* Last Modified: Sun 23 Feb 2020 05:56:16 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <thread>
#include <chrono>
#include <ncurses.h>
#include "player.h"

using namespace std;

static bool finished = false;

void *moving_thread(void *value) {

    Player *p = (Player *) value;

    while (!finished) {
        this_thread::sleep_for(chrono::milliseconds(50));
        p->move();
    }

    return NULL;
}

int main () {

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW *playwin = newwin(y_max, x_max, 0, 0);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    Player *p = new Player(playwin, 1, 1, '*', '.');
    p->display();
    wrefresh(playwin);

    thread worker(moving_thread, p);
    while (p->getmv() != 'x');
    finished = true;
    worker.join();

    endwin();

    return 0;
}
