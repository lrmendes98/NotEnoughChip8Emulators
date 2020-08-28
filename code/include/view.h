#pragma once

#include <SDL2/SDL.h>
#include <iostream>

/**
 * 
 * View class corresponding to the MVC structure
 *
 */

 #define WINDOW_WIDTH 600
 #define WINDOW_HEIGHT 400

class View {
    public:
        View();
        ~View();

        /**
        * Inits SDL, window and renderer
        */
        void init();

        /**
        * Contains view loop, render and events
        */
        void run();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool isRunning;
        void onEvent(SDL_Event *event);
        void onLoop();
        void onRender();
        void drawSomething();
};