#include "view.h"


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
    SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear( this->renderer );
    
    // //Render red filled quad
    // SDL_Rect fillRect = { WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    // SDL_SetRenderDrawColor( this->renderer, 0xFF, 0x00, 0x00, 0xFF );        
    // SDL_RenderFillRect( this->renderer, &fillRect );

    // //Render green outlined quad
    // SDL_Rect outlineRect = { WINDOW_WIDTH / 6, WINDOW_HEIGHT / 6, WINDOW_WIDTH * 2 / 3, WINDOW_HEIGHT * 2 / 3 };
    // SDL_SetRenderDrawColor( this->renderer, 0x00, 0xFF, 0x00, 0xFF );
    // SDL_RenderDrawRect( this->renderer, &outlineRect );

    // //Draw vertical line of yellow dots
    // SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0x00, 0xFF );
    // for( int i = 0; i < WINDOW_HEIGHT; i += 4 ) {
    //     SDL_RenderDrawPoint( this->renderer, WINDOW_WIDTH / 2, i );
    // }

    Coord pos = {20, 20};
    Color red = {0xFF, 0x00, 0x00, 0x00};
    Rectangle rectangle1 = Rectangle(pos, red, 100, 50);

    drawFilledRectangle(this->renderer, rectangle1);

    //Update screen
    SDL_RenderPresent(this->renderer);
}

void View::drawFilledRectangle(SDL_Renderer* renderer, Rectangle rect) {
    SDL_Rect sdlRect = { rect.getPosition().x, rect.getPosition().y, 
        rect.getWidth(), rect.getHeight() };

    SDL_SetRenderDrawColor(this->renderer, rect.getColor().r, rect.getColor().g, 
        rect.getColor().b, rect.getColor().a);

    SDL_RenderFillRect(this->renderer, &sdlRect);
} 
