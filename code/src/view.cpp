#include "view.h"

#include <SDL2/SDL.h>
#include <iostream>


View::View() {
}

View::~View() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void View::init() {
    // Init video resources
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error("Coudn't init SDL\n");
    }

    // Create window context
    this->window = SDL_CreateWindow("Chip8-emu", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_HEIGHT, WINDOW_WIDTH,
        SDL_WINDOW_RESIZABLE);
    if(this->window == nullptr) {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        throw std::runtime_error("Coudn't create window SDL\n");
    }

    // Create renderer
    this->renderer = SDL_CreateRenderer(this->window,
        -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == nullptr) {
    	std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    	SDL_DestroyWindow(this->window);
    	SDL_Quit();
        throw std::runtime_error("Coudn't create renderer SDL\n");
    }
}

void View::run() {
    this->isRunning = true;

    SDL_Event sdlEvent;

    while(this->isRunning) {
        while(SDL_PollEvent(&sdlEvent)) {
            onEvent(&sdlEvent);
        }
        onLoop();
        onRender();
    }
}

void View::onEvent(SDL_Event *sdlEvent) {
    switch (sdlEvent->type) {
        case SDL_KEYUP: {
            if(sdlEvent->key.keysym.sym == SDLK_ESCAPE) {
                std::cout << "Quit signal was issued\n";
                this->isRunning = false;
            } else {
                std::cout << "Key: "
                    << (char) sdlEvent->key.keysym.sym
                    << " was released\n";
            }
        }
        break;
        case SDL_QUIT: {
            std::cout << "Quit signal was issued\n";
            this->isRunning = false;
        }
        break;
    default:
        break;
    }
}

void View::onLoop() {

}

void View::onRender() {
    for (unsigned int i = 0; i<20; ++i) {
        for (unsigned int j=0; j<20; ++j) {
                SDL_RenderDrawPoint(renderer, i, j);
                SDL_RenderPresent(renderer);
            }
        }
}

void View::drawSomething() {

} 
