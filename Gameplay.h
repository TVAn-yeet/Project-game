#pragma once


#include <ctime>
#include "Class.h"
#include "Var.h"

void renderGame() {
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < *MAP_HEIGHT; ++i) {
        for (int j = 0; j < *MAP_WIDTH; ++j) {            
            Grass g = Grass(j * *TILE_SIZE, i * *TILE_SIZE,false);
            g.render(renderer);
        }
    }
    for (int i = 0; i < rocks.size(); ++i) {
        rocks[i].render(renderer);
    }
    fox.render(renderer);
    rab.render(renderer);
    SDL_RenderPresent(renderer);
}


void handleGameEvents(float deltaTime) {
    SDL_Event e;
    float dx = 0, dy = 0;
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
    }
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
        inMenu = true;
    }
    else {
        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            dx = -fox.FOX_SPEED;
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            dx = fox.FOX_SPEED;
        }
        if (currentKeyStates[SDL_SCANCODE_UP]) {
            dy = -fox.FOX_SPEED;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            dy = fox.FOX_SPEED;
        }
        fox.move(dx, dy, deltaTime,rocks);
        
    }
}
void Checkend() {
    if (SDL_HasIntersection(&rab.rect, &fox.rect)) {
        ended = true;
        win = true;
    }
}
