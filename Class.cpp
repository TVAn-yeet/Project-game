#include "Class.h"

Rock::Rock(int startX, int startY) {
    x = startX;
    y = startY;
    rect = { x, y, 40, 40 };
}

void Rock::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 150, 75, 0, 255); 
    SDL_RenderFillRect(renderer, &rect);
}

Fox::Fox(int startX, int startY) {
    x = startX;
    y = startY;
    rect = { (int)x, (int)y, 20, 20 };  
}

void Fox::move(float dx, float dy, float deltaTime) {
    x += dx * deltaTime;
    y += dy * deltaTime;

    if (x < 0) x = 0;
    if (x + rect.w > 800) x = 800 - rect.w;
    if (y < 0) y = 0;
    if (y + rect.h > 600) y = 600 - rect.h;

    rect.x = (int)x;
    rect.y = (int)y;
}

void Fox::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
