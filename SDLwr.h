#pragma once
#include <iostream>
#include <SDL.h>
#include "Var.h"
using namespace std;
Uint32 lastTime;

void CheckError() {

    lastTime = SDL_GetTicks();
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;

    }
    window = SDL_CreateWindow("Cat Chit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, *WINDOW_WIDTH, *WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;

    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;

    }

}

void Quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

