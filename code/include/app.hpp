#pragma once

#include <SDL2/SDL.h>
#include <iostream>

/**
 * A brief history of JavaDoc-style (C-style) comments.
 *
 * This is the typical JavaDoc-style C-style comment. It starts with two
 * asterisks.
 *
 * @param theory Even if there is only one possible unified theory. it is just a
 *               set of rules and equations.
 */

class App {
    public:
        App();
        ~App();
        void init();
        void run();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool isRunning;
        void onEvent(SDL_Event *event);
        void onLoop();
        void onRender();
};