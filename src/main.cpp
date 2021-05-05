#include <iostream>
#include <codecvt>
#include <locale>
#include <string>

#include <stdio.h>
#include <SDL2/SDL.h>

#define Int unsigned int

#include "/debug/debug.cpp"
#include "/rendering/screen.cpp"
#include "/rendering/SDL2__.cpp"


namespace
{
    SDL_Renderer *renderer;
    SDL_Window   *window;
    SDL_Event    *event;
    SDL_Texture  *texture;

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

    SDL_Init(SDL_INIT_VIDEO);
    SDL_ReInit(&window, &texture, &renderer, &WindowClass);

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }


    }

    SDL_Destroy(&window, &texture, &renderer);

    return 0;
}