/*-----------------------------------------------------------------------------
* File Name: playfield.cpp
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sun 26 Jul 2020 07:27:21 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "playfield.h"

Playfield::Playfield(int st_y, int st_x, int wth, int hgt) {
    start_y = st_y;
    start_x = st_x;
    width = wth;
    height = hgt;

    snake = new Snake(start_y + height / 2, start_x + width / 2);
}

void Playfield::reset() {
    snake = new Snake(start_y + height / 2, start_x + width / 2);
}

void Playfield::consume_food_if_needed() {
    if (snake->head->x_pos == food_pos_x &&
        snake->head->y_pos == food_pos_y) {

        snake->eat();
        is_food_eaten = true;
    }
}

void Playfield::generate_food() {
    Point rand_field[width * height];

    int inx = 0;
    for (int i = start_x; i < start_x + width; i++) {
        for (int j = start_y; j < start_y + height; j++) {
            if (!snake->is_one_of_the_nodes(j, i)) {
                rand_field[inx] = {i, j};
                inx++;
            }
        }
    }

    srand(time(NULL));
    int food_point = rand() % (inx + 1);
    food_pos_x = rand_field[food_point].x;
    food_pos_y = rand_field[food_point].y;
    is_food_eaten = false;
}

bool Playfield::is_collided() {
    if (snake->detect_collision()) {
        return true;
    }

    SnakeNode *head = snake->head;
    if (head->x_pos < start_x || head->x_pos >= start_x + width) {
         return true;
    }
    if (head->y_pos < start_y || head->y_pos >= start_y + height) {
        return true;
    }

    return false;
}

void Playfield::direct_snake(int direction) {

    if (direction == KEY_UP ||
        direction == KEY_DOWN ||
        direction == KEY_LEFT ||
        direction == KEY_RIGHT) {

        if (!snake->is_opposite_direction(direction)) {
            switch (direction) {
                case KEY_UP:
                    snake->head->direction = UP;
                    break;
                case KEY_DOWN:
                    snake->head->direction = DOWN;
                    break;
                case KEY_LEFT:
                    snake->head->direction = LEFT;
                    break;
                case KEY_RIGHT:
                    snake->head->direction = RIGHT;
                    break;
                default:
                    break;
            }
        }
    }
}

void Playfield::tic() {
    trail_pos_y = snake->tail->y_pos;
    trail_pos_x = snake->tail->x_pos;

    snake->move();
    consume_food_if_needed();
}
