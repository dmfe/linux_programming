/*-----------------------------------------------------------------------------
* File Name: driver.cpp
* Purpose:
* Creation Date: 24-02-2020
* Last Modified: Sun 22 Mar 2020 02:59:47 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <ncurses.h>
#include "driver.h"
#include "renderer.h"
#include "menu_renderer.h"
#include "gameplay_renderer.h"

void Driver::run() {
    init();

    int scr_height, scr_width;
    getmaxyx(stdscr, scr_height, scr_width);
    Window *wnd = new Window(scr_height, scr_width, 0, 0, true);

    std::string menu_choices[MENU_SIZE] = {
        "Can I play, Daddy?",
        "Don't hurt me.",
        "Bring 'em on!",
        "I am a death incarnate!",
        "Exit"};

    MenuRenderer *menuRenderer = new MenuRenderer(wnd, menu_choices, MENU_SIZE);
    menuRenderer->render();
    int menu_option = *(int *)menuRenderer->get_data();
    GameplayRenderer *gameplayRenderer = new GameplayRenderer(wnd);

    while (1) {
        if (menu_option == 4) {
            break;
        }

        gameplayRenderer->delay = menu_option;
        gameplayRenderer->render();
        gameplayRenderer->reset();

        menuRenderer->selected_option = 0;
        menuRenderer->render();
        menu_option = *(int *)menuRenderer->get_data();
    }

    terminate();
}

void Driver::init() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

void Driver::terminate() {
    endwin();
}
