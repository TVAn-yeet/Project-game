#pragma once

#include "Class.h"
#include "Window.h"
#include <vector>
#include <ctime>
std::vector<Rock> rocks;
void generateRock() {

    srand(time(NULL));
    for (int i = 0; i < NUM_ROCK; ++i) {
        int x = rand() % (MAP_WIDTH);
        int y = rand() % (MAP_HEIGHT);
        if (x != 0 && x != MAP_WIDTH - 1 && y != 0 && y != MAP_HEIGHT - 1) {
            Rock r = Rock(x * TILE_SIZE, y * TILE_SIZE);
            rocks.push_back(r);
        }
    }
}

void renderGame() {
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            SDL_Rect tile = { j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            SDL_RenderFillRect(renderer, &tile);
        }
    }
    for (int i = 0; i < rocks.size(); ++i) {
        rocks[i].render(renderer);
    }
    fox.render(renderer);
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
        fox.move(dx, dy, deltaTime);
    }
}
