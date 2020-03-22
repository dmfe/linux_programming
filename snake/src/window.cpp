/*-----------------------------------------------------------------------------
* File Name: window.cpp
* Purpose:
* Creation Date: 29-02-2020
* Last Modified: Wed 18 Mar 2020 05:31:46 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include "window.h"

Window::Window(int h, int w, int sy, int sx, bool isKp) {
    width = w;
    height = h;
    start_y = sy;
    start_x = sx;

    ncWnd = newwin(height, width, start_y, start_x);
    if (isKp) {
        keypad(ncWnd, true);
    }
}

void Window::drawFrame() {
    box(ncWnd, 0, 0);
}

void Window::drawCharacter(int pos_y, int pos_x, char character) {
    mvwaddch(ncWnd, pos_y, pos_x, character);
}

void Window::drawString(int pos_y, int pos_x, std::string str) {
    mvwprintw(ncWnd, pos_y, pos_x, str.c_str());
}

void Window::drawString(int pos_y, int pos_x, std::string str, int attr) {
    wattron(ncWnd, attr);
    drawString(pos_y, pos_x, str);
    wattroff(ncWnd, attr);
}

int Window::input() {
    return wgetch(ncWnd);
}

void Window::refresh() {
    wrefresh(ncWnd);
}

void Window::set_no_delay(bool val) {
    nodelay(ncWnd, val);
}

void Window::set_no_timeout(bool val) {
    notimeout(ncWnd, val);
}

void Window::clear() {
    wclear(ncWnd);
}
