/*-----------------------------------------------------------------------------
* File Name: snake.h
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sat 21 Mar 2020 02:10:08 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _SNAKE_H_
#define _SNAKE_H_

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

class SnakeNode {
    public:
        int y_pos;
        int x_pos;
        int direction;
        SnakeNode *next;

        SnakeNode(int y, int x, int dir);
};

class Snake {
    public:
        SnakeNode *head;
        SnakeNode *tail;

        Snake(int start_y, int start_x);
        void move();
        void eat();
        bool detect_collision();
        bool is_one_of_the_nodes(int y, int x);

    private:
        int size;
};

#endif
