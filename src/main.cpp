#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdint>

typedef unsigned int Int;

#include "../include/debug.hpp"
#include "../include/font.hpp"
#include "../include/SDL2_.hpp"
#include "../include/screen.hpp"

namespace
{
    SDL_Renderer *renderer;
    SDL_Window   *window;
    SDL_Texture  *texture;
    SDL_Event    event;

    Int CellWidth  = 10;
    Int CellHeight = 10;
    Int ScreenHeight = 800;
    Int ScreenWidth  = 800; 


    bool quit           = false;
    bool UseLockTexture = false;

    Int frames = 0;

    uint64_t start = SDL_GetPerformanceCounter();

}
int main()
{
    Screen::Window WindowClass(CellWidth, CellHeight, ScreenWidth, ScreenHeight);
    auto WindowCoords = WindowClass.GetWndCoords();
    SDL_Init(SDL_INIT_VIDEO);
    SDL::ReInit(window, texture, renderer, WindowCoords);

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }
    }

    SDL::Destroy(window, renderer, texture);

    return 0;
}