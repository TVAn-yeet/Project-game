#pragma once
#include <SDL.h>
#include "Var.h"


void renderMenu() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, menupic, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void handleMenuEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_RETURN: {
                inMenu = false;
                break;
            }
            case SDLK_ESCAPE: {
                running = false;
                break;
            }
            
            default:
                break;
            }
        }
    }
}
