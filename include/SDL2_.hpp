#pragma once
#ifndef SDL2_HPP
#define SDL2_HPP

#include "../include/screen.hpp"
#include <SDL2/SDL.h>

namespace SDL {

    struct pixel {
        uint8_t a, r, g, b;
    };

    void ReInit(SDL_Window *window, SDL_Texture *texture, SDL_Renderer *renderer,
                            std::pair<Int, Int> WindowDimensions) {
        const Int WindowWidth = WindowDimensions.first;
        const Int WindowHeight = WindowDimensions.second;

        if (window == nullptr) {
            window = SDL_CreateWindow("Terminal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      WindowWidth, WindowHeight, 0);
        } else {
            SDL_SetWindowSize(window, WindowWidth, WindowHeight);
        }
        if (!renderer) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
        if (!texture) {
            texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                        SDL_TEXTUREACCESS_STATIC,
                                        WindowWidth, WindowHeight);
        }
    }

    void Destroy(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
    }
}
#endif // SDL2_HPP