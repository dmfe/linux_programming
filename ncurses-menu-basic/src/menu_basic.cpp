/*-----------------------------------------------------------------------------
* File Name: menu_basic.cpp
* Purpose:
* Creation Date: 27-06-2020
* Last Modified: Sat 27 Jun 2020 06:18:02 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char *choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit"
};

int main() {

    ITEM **items;
    MENU *menu;
    ITEM *cur_item;
    int choices_num;
    int c;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    choices_num = ARRAY_SIZE(choices);
    items = (ITEM **)calloc(choices_num + 1, sizeof(ITEM *));

    for(int i = 0; i < choices_num; i++) {
        items[i] = new_item("*", choices[i]);
    }
    items[choices_num] = (ITEM *)NULL;

    menu = new_menu(items);
    mvprintw(LINES - 2, 0, "F1 to Exit");
    post_menu(menu);
    refresh();

    while ((c = getch()) != KEY_F(1)) {
        switch (c) {
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;

        }
    }

    free_item(items[0]);
    free_item(items[1]);
    free_menu(menu);
    endwin();

    return 0;
}
