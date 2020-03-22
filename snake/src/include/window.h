/*-----------------------------------------------------------------------------
* File Name: window.h
* Purpose:
* Creation Date: 29-02-2020
* Last Modified: Wed 18 Mar 2020 05:31:28 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <ncurses.h>
#include <string>

class Window {

    public:
        int width;
        int height;

        Window(int width, int height, int start_y, int start_x, bool isKeypad);
        void drawFrame();
        void drawCharacter(int pos_y, int pos_x, char character);
        void drawString(int pos_y, int pos_x, std::string str);
        void drawString(int pos_y, int pos_x, std::string str, int attr);
        int input();
        void refresh();
        void set_no_delay(bool val);
        void set_no_timeout(bool val);
        void clear();

    private:
        int start_y;
        int start_x;
        WINDOW *ncWnd;
};

#endif
