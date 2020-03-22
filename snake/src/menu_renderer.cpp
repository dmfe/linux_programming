/*-----------------------------------------------------------------------------
* File Name: menu_renderer.cpp
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sun 22 Mar 2020 02:14:55 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <ncurses.h>
#include "menu_renderer.h"
#include "commons.h"

MenuRenderer::MenuRenderer(Window *wnd, std::string options[], int size) {
    selected_option = 0;
    menu_size = size;
    menu_options = new std::string[size];
    for (int i = 0; i < size; i++) {
        menu_options[i] = options[i];
    }

    wnd_height = wnd->height;
    wnd_width = wnd->width;
    window = wnd;
}

void MenuRenderer::render_title() {
    std::string menu_title ("Choose your destiny!");
    window->drawString(1, (wnd_width / 2) - (menu_title.length() / 2) - 1,
                       menu_title);
    window->refresh();
}

void MenuRenderer::render_menu() {
    int cur_y = (wnd_height / 2) - (menu_size / 2) - 1;
    for (int i = 0; i < menu_size; i++) {
        int cur_x = (wnd_width / 2) - (menu_options[i].length() / 2) - 1;

        if (i == selected_option) {
            window->drawString(cur_y, cur_x, menu_options[i], A_REVERSE);
            window->refresh();
        } else {
            window->drawString(cur_y, cur_x, menu_options[i]);
            window->refresh();
        }
        cur_y++;
    }
}

void MenuRenderer::render_loop() {
    while (1) {
        render_menu();
        int choice = window->input();
        switch (choice) {
            case KEY_UP:
                if (selected_option == 0) {
                    selected_option = menu_size - 1;
                } else {
                    selected_option--;
                }
                break;
            case KEY_DOWN:
                if (selected_option == menu_size - 1) {
                    selected_option = 0;
                } else {
                    selected_option++;
                }
                break;
            default:
                break;
        }
        if (choice == 10) {
            break;
        }
    }

    switch (selected_option) {
        case 0:
            selected_option = CAN_I_PLAY_DADDY;
            break;
        case 1:
            selected_option = DONT_HURT_ME;
            break;
        case 2:
            selected_option = BRING_EM_ON;
            break;
        case 3:
            selected_option = I_AM_THE_DEATH_INCARNATE;
            break;
        default:
            break;
    }
    render_data = &selected_option;
}

void MenuRenderer::render() {
    window->clear();
    window->drawFrame();

    render_title();
    render_loop();

    window->clear();
}
