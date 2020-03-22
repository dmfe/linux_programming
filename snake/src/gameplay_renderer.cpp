/*-----------------------------------------------------------------------------
* File Name: gameplay_renderer.cpp
* Purpose:
* Creation Date: 01-03-2020
* Last Modified: Sun 22 Mar 2020 03:15:13 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <thread>
#include <chrono>
#include <ncurses.h>
#include "commons.h"
#include "gameplay_renderer.h"

GameplayRenderer::GameplayRenderer(Window *wnd) {
    wnd_height = wnd->height;
    wnd_width = wnd->width;
    window = wnd;

    delay = CAN_I_PLAY_DADDY;
    playfield = new Playfield(1, 1, wnd_width - 2, wnd_height - 2);
    finished = false;
    interrupted = false;
    is_food_rendered = false;
}

void GameplayRenderer::reset() {
    playfield->reset();
    finished = false;
    interrupted = false;
    is_food_rendered = false;
}

void GameplayRenderer::render() {
    window->clear();
    window->drawFrame();

    window->set_no_delay(true);
    render_loop();
    window->set_no_delay(false);

    if (finished) {
        window->clear();
        window->drawFrame();
        std::string game_over_string ("GAME OVER");
        window->drawString(wnd_height / 2, (wnd_width / 2) -
                           (game_over_string.length() / 2) - 1,
                           game_over_string);
        window->input();
    }
}

void GameplayRenderer::render_loop() {
    draw_playfield();
}

void GameplayRenderer::draw_playfield() {

    playfield->generate_food();
    draw_food();
    is_food_rendered = true;

    draw_snake();

    while (1) {

        bool enough = finished || interrupted;

        if (enough) {
            break;
        }

        handle_input();

        playfield->tic();

        if (playfield->is_collided()) {
            finished = true;
            break;
        }

        if (playfield->is_food_eaten) {
            is_food_rendered = false;
        }
        draw_trail();
        draw_snake();
        if (!is_food_rendered) {
            playfield->generate_food();
            draw_food();
            is_food_rendered = true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void GameplayRenderer::handle_input() {

    int intput = get_mv();
    if (intput == 'x') {
        interrupted = true;
    }

    playfield->direct_snake(intput);
}

void GameplayRenderer::draw_snake() {
    for (SnakeNode *snake_node = playfield->snake->head;
         snake_node != NULL;
         snake_node = snake_node->next) {

        window->drawCharacter(snake_node->y_pos,
                              snake_node->x_pos,
                              SNAKE_CHAR);
    }

    window->refresh();
}

void GameplayRenderer::draw_trail() {
    window->drawCharacter(playfield->trail_pos_y,
                          playfield->trail_pos_x,
                          TRAIL_CHAR);
    window->refresh();
}

void GameplayRenderer::draw_food() {
    window->drawCharacter(playfield->food_pos_y,
                          playfield->food_pos_x,
                          FOOD_CHAR);
    window->refresh();
}

int GameplayRenderer::get_mv() {
    return window->input();
}
