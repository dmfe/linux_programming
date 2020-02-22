/*-----------------------------------------------------------------------------
* File Name: hello.cpp
* Purpose:
* Creation Date: 13-02-2020
* Last Modified: Sun 23 Feb 2020 01:24:08 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <ncurses.h>
#include <string>

using namespace std;

int main () {

    initscr();
    cbreak();
    noecho();

    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW *menu_win = newwin(6, x_max - 12, y_max - 8, 5);
    box(menu_win, 0, 0);
    refresh();
    wrefresh(menu_win);
    keypad(menu_win, true);

    string choices[3] = {"Walk", "Jog", "Run"};
    int choice;
    int highlight = 0;

    while (1) {
        for (int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(menu_win, A_REVERSE);
            mvwprintw (menu_win, i + 1, 1, choices[i].c_str());
            wattroff(menu_win, A_REVERSE);
        }
        choice = wgetch (menu_win);

        switch (choice) {
            case KEY_UP:
                highlight--;
                break;
            case KEY_DOWN:
                highlight++;
                break;
            default:
                break;
        }

        if (choice == 10) {
            break;
        }
    }

    printw ("Your choice was: %s", choices[highlight].c_str());

    getch();
    endwin();

    return 0;
}
