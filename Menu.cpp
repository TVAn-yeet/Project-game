#pragma once
#include <SDL.h>
#include "Window.h"
void renderMenu() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_Rect menuRect = { WINDOW_WIDTH / 4, WINDOW_HEIGHT / 3, WINDOW_WIDTH / 2, 100 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &menuRect);
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
