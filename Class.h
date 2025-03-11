#pragma once
#ifndef CLASS_H
#define CLASS_H
#include <SDL.h>
#include "Default.h"
class Rock {
public:
    int x, y;
    SDL_Rect rect;

    Rock(int startX, int startY) {
        x = startX;
        y = startY;
        rect = { x, y, TILE_SIZE, TILE_SIZE };
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 150, 75, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};

class Fox {
public:
    const float FOX_SPEED = 200.0f;
    float x, y;
    SDL_Rect rect;

    Fox(int startX, int startY) {
        x = startX;
        y = startY;
        rect = { (int)x, (int)y, TILE_SIZE / 2, TILE_SIZE / 2 };
    }

    void move(float dx, float dy, float deltaTime) {
        x += dx * deltaTime;
        y += dy * deltaTime;

        if (x < 0) x = WINDOW_WIDTH - rect.w;
        if (x + rect.w > WINDOW_WIDTH) x = 0;
        if (y < 0) y = WINDOW_HEIGHT - rect.h;
        if (y + rect.h > WINDOW_HEIGHT) y = 0;

        rect.x = (int)x;
        rect.y = (int)y;
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};
#endif