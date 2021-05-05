// Contains funtions for SDL2 drawing
#pragma once
#ifndef SDL2__H
#define SDL2__H

struct pixel
{
    uint8_t a,r,g,b;
};

void SDL_ReInit(SLD_Window &wnd,SDL_Texture &texture, SDL_Renderer &renderer, Screen::Window &WindowClass)
{
    const Int WindowHeight = WindowClass->GetWndCoords().first;
    const Int WindowWidth  = WindowClass->GetWndCoords().second;

    if(!*window)
    {
    *wnd = SDL_CreateWindow("Terminal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            WindowWidth, WindowHeight, 0);
    }
    else
    {
        SDL_SetWindowSize(*window, WindowWidth, WindowHeight);
    }
    if(!*renderer)
    {
        *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDER_ACCELERATED);
    }
    if(!*texture)
    {
        *texture = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_ARGB8888,
                                      SDL_TEXTUREACCESS_STATIC,
                                      WindowWidth, WindowHeight);
    }
    



}
void SDL_Destroy(SLD_Window &wnd, SLD_Renderer renderer, SDL_Texture texture)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyTexture(*texture);
    SDL_DestroyWindow(*wnd);
}

#endif // SDL2__H