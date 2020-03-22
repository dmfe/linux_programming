/*-----------------------------------------------------------------------------
* File Name: gameplay_renderer.h
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sun 22 Mar 2020 03:12:31 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _GAMEPLAY_RENDERER_H_
#define _GAMEPLAY_RENDERER_H_

#include "renderer.h"
#include "playfield.h"

#define SNAKE_CHAR '*'
#define FOOD_CHAR 'o'
#define TRAIL_CHAR ' '

class GameplayRenderer: public Renderer {

    public:
        int delay;

        GameplayRenderer(Window *wnd);
        void reset();
        void render();

    protected:
        void render_loop();

    private:
        Playfield *playfield;
        bool is_food_rendered;
        bool interrupted;
        bool finished;
        bool paused;

        void draw_playfield();
        void handle_input();
        void draw_snake();
        void draw_trail();
        void draw_food();
        int get_mv();
};

#endif
