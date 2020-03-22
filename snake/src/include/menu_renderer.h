/*-----------------------------------------------------------------------------
* File Name: menu_renderer.h
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sun 22 Mar 2020 02:23:45 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _MENU_RENDERER_H_
#define _MENU_RENDERER_H_

#include "renderer.h"

class MenuRenderer: public Renderer {

    public:
        int selected_option;

        MenuRenderer(Window *wnd, std::string *options, int size);
        void render();

    protected:
        void render_loop();

    private:
        int menu_size;
        std::string *menu_options;

        void render_title();
        void render_menu();
};

#endif
