#pragma once
#include <iostream>
#include <SDL.h>
#include "Var.h"
#include <SDL_image.h>
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
    background = IMG_LoadTexture(renderer, "Texture/Grass1.png");
    wolfgrass = IMG_LoadTexture(renderer, "Texture/Grass2.png");
    rockpic = IMG_LoadTexture(renderer, "Texture/Rock.png");
    fox1 = IMG_LoadTexture(renderer, "Texture/Fox1.xcf");
    fox2 = IMG_LoadTexture(renderer, "Texture/Fox2.xcf");
    rab1 = IMG_LoadTexture(renderer, "Texture/Rab1.xcf");
    rab2 = IMG_LoadTexture(renderer, "Texture/Rab2.xcf");
    wolf1 = IMG_LoadTexture(renderer, "Texture/Wolf1.xcf");
    wolf2 = IMG_LoadTexture(renderer, "Texture/Wolf2.xcf");
    winpic = IMG_LoadTexture(renderer, "Texture/win.xcf");
    losepic = IMG_LoadTexture(renderer, "Texture/lose.xcf");
    menupic = IMG_LoadTexture(renderer, "Texture/menu.xcf");

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        cerr << "SDL_image error:" << IMG_GetError();


}

void Quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
}

