/*-----------------------------------------------------------------------------
* File Name: snake.cpp
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sat 21 Mar 2020 02:08:57 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <cstddef>
#include "snake.h"

SnakeNode::SnakeNode(int y, int x, int dir) {
    y_pos = y;
    x_pos = x;
    next = NULL;
    direction = dir;
}

Snake::Snake(int start_y, int start_x) {
    size = 1;
    head = new SnakeNode(start_y, start_x, DOWN);
    tail = head;
}

void Snake::move() {

    int prev_dir = -1;
    for (SnakeNode *cur_node = head;
         cur_node != NULL;
         cur_node = cur_node->next) {

        switch (cur_node->direction) {
            case UP:
                cur_node->y_pos--;
                cur_node->x_pos;
                break;
            case DOWN:
                cur_node->y_pos++;
                cur_node->x_pos;
                break;
            case RIGHT:
                cur_node->y_pos;
                cur_node->x_pos++;
                break;
            case LEFT:
                cur_node->y_pos;
                cur_node->x_pos--;
                break;
            default:
                break;
        }

        int cur_direction = cur_node->direction;
        if (prev_dir != -1) {
            cur_node->direction = prev_dir;
        }
        prev_dir = cur_direction;

    }
}

void Snake::eat() {
    int new_y, new_x;
    switch (tail->direction) {
        case UP:
            new_y = tail->y_pos + 1;
            new_x = tail->x_pos;
            break;
        case DOWN:
            new_y = tail->y_pos - 1;
            new_x = tail->x_pos;
            break;
        case RIGHT:
            new_y = tail->y_pos;
            new_x = tail->x_pos - 1;
            break;
        case LEFT:
            new_y = tail->y_pos;
            new_x = tail->x_pos + 1;
            break;
        default:
            break;
    }

    SnakeNode *new_node = new SnakeNode(new_y, new_x, tail->direction);
    tail->next = new_node;
    tail = new_node;
    size++;
}

bool Snake::detect_collision() {
    bool is_collided = false;

    for (SnakeNode *cur_node = head->next;
         cur_node != NULL;
         cur_node = cur_node->next) {

        if (cur_node->y_pos == head->y_pos &&
            cur_node->x_pos == head->x_pos) {

            is_collided = true;
            break;
        }
    }

    return is_collided;
}

bool Snake::is_one_of_the_nodes(int y, int x) {
    bool is_detected = false;

    for (SnakeNode *cur_node = head;
         cur_node != NULL;
         cur_node = cur_node->next) {

        if (cur_node->y_pos == y &&
            cur_node->x_pos == x) {

            is_detected = true;
            break;
        }
    }

    return is_detected;
}
