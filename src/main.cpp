/*** include ***/
#include <iostream>
#include <SDL2/SDL.h>
#include <linked_list.hpp>

/*** define ****/
#define WIDTH 800
#define HEIGHT 600

/*** prototypes ***/
void init();
void out();
void input();
void render();

/*** global variables ***/
SDL_Window *window;
bool quit = false;

/*** main ***/
int main( int argc, char *argv[] )
{
    
    init();

    while (!quit)
    {
        input();
    }

    out();

    return EXIT_SUCCESS;
}

/*** functions ***/
void init()
{
    SDL_Init(SDL_INIT_EVERYTHING); // initialize SDL

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI); // creates the window

    if ( NULL == window ) // if the windows fails to be created
    {
        std::cout << "You done fucked up: " << SDL_GetError() << std::endl;
    }

}

void out()
{
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void input()
{
    SDL_Event event;

    if ( SDL_PollEvent( &event ) )
    {
        if (SDL_KEYDOWN == event.type)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                case SDLK_w:
                std::cout << event.key.keysym.sym;
                break;
                case SDLK_DOWN:
                case SDLK_s:
                std::cout << event.key.keysym.sym;
                break;
                case SDLK_RIGHT:
                case SDLK_d:
                std::cout << event.key.keysym.sym;
                break;
                case SDLK_LEFT:
                case SDLK_a:
                std::cout << event.key.keysym.sym;
                break;
            }
        }
        if (SDL_QUIT == event.type) quit = true; // breaks the while loop when the window is closed
    }
}