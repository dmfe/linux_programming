/*-----------------------------------------------------------------------------
* File Name: player.h
* Purpose:
* Creation Date: 23-02-2020
* Last Modified: Sun 23 Feb 2020 03:39:46 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _PLAYER_H_
#define _PLAYER_H_

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

class Player {

    public:
        Player(WINDOW *win, int y, int x, char c, char t);

        void move();
        int getmv();
        void display();

    private:
        int x_loc, y_loc, x_max, y_max;
        char character;
        char trace;
        int direction = DOWN;
        WINDOW *curwin;

        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        void leave_trace();
        void set_direction(int dir);
};

#endif

