#pragma once

#include <SDL2/SDL.h>
#include <iostream>

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