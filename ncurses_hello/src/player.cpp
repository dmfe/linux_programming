/*-----------------------------------------------------------------------------
* File Name: palayer.cpp
* Purpose:
* Creation Date: 23-02-2020
* Last Modified: Sun 23 Feb 2020 04:41:02 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <pthread.h>
#include <ncurses.h>
#include "player.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

Player::Player(WINDOW *win, int y, int x, char c, char t) {
    curwin = win;
    x_loc = x;
    y_loc = y;

    getmaxyx(curwin, y_max, x_max);
    keypad(curwin, true);

    character = c;
    trace = t;
}

void Player::move() {
    pthread_mutex_lock(&mutex);

    switch (direction) {
        case UP:
            mvup();
            break;
        case DOWN:
            mvdown();
            break;
        case LEFT:
            mvleft();
            break;
        case RIGHT:
            mvright();
            break;
        default:
            break;
    }

    display();

    pthread_mutex_unlock(&mutex);
}

void Player::mvup() {
    leave_trace();
    if (y_loc > 1) {
        y_loc--;
    }
}

void Player::mvdown() {
    leave_trace();
    if (y_loc < y_max - 2) {
        y_loc++;
    }
}

void Player::mvleft() {
    leave_trace();
    if (x_loc > 1) {
        x_loc--;
    }
}

void Player::mvright() {
    leave_trace();
    if (x_loc < x_max - 2) {
        x_loc++;
    }
}

int Player::getmv() {
    int choice = wgetch(curwin);

    switch (choice) {
        case KEY_UP:
            set_direction(UP);
            break;
        case KEY_DOWN:
            set_direction(DOWN);
            break;
        case KEY_LEFT:
            set_direction(LEFT);
            break;
        case KEY_RIGHT:
            set_direction(RIGHT);
            break;
        default:
            break;
    }

    return choice;
}

void Player::display() {
    mvwaddch(curwin, y_loc, x_loc, character);
    wrefresh(curwin);
}

void Player::leave_trace() {
    mvwaddch(curwin, y_loc, x_loc, trace);
}

void Player::set_direction(int dir) {
    pthread_mutex_lock(&mutex);

    direction = dir;

    pthread_mutex_unlock(&mutex);
}

