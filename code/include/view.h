#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "rectangle.h"

/**
 * View class corresponding to the MVC structure
 */
 #define WINDOW_WIDTH 600
 #define WINDOW_HEIGHT 600
 

class View {
    
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool drawFlag;
        void onEvent(SDL_Event *event);
        void onLoop();
        void onRender();        
        /**
        * Draws color filled rectangles
        */
        void drawFilledRectangle(SDL_Renderer* renderer, Rectangle rect);

    public:
        View();
        ~View();
        void setDrawFlag(bool value);
        bool getDrawFlag();
        /**
        * Inits SDL, window and renderer
        */
        void init();
        /**
        * Contains view loop, render and events
        */
        void run();
        void drawFrame();
        

};