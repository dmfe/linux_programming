/*-----------------------------------------------------------------------------
* File Name: renderer.h
* Purpose:
* Creation Date: 24-02-2020
* Last Modified: Wed 18 Mar 2020 05:19:26 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "window.h"

class Renderer {

    public:
        virtual void render() = 0;
        void * get_data() { return render_data; }

    protected:
        int wnd_height;
        int wnd_width;
        Window *window;
        void *render_data;

        virtual void render_loop() = 0;
};

#endif
