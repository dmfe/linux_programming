/*-----------------------------------------------------------------------------
* File Name: playfield.h
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sun 22 Mar 2020 01:42:44 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _PLAYFIELD_H_
#define _PLAYFIELD_H_

#include "snake.h"

struct Point {
    int x;
    int y;
};

class Playfield {

    public:
        int food_pos_y;
        int food_pos_x;
        int trail_pos_y;
        int trail_pos_x;
        bool is_food_eaten;
        Snake *snake;

        Playfield(int st_y, int st_x, int wth, int hgt);
        void reset();
        bool is_collided();
        void direct_snake(int direction);
        void tic();
        void generate_food();

    private:
        int start_y;
        int start_x;
        int width;
        int height;

        void consume_food_if_needed();
};

#endif
