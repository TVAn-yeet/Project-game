#ifndef CLASS_H
#define CLASS_H

#include <SDL.h>

class Rock {
public:
    int x, y;
    SDL_Rect rect;

    Rock(int startX, int startY);
    void render(SDL_Renderer* renderer);
};

class Fox {
public:
    const float FOX_SPEED = 200.0f;
    float x, y;
    SDL_Rect rect;

    Fox(int startX, int startY);
    void move(float dx, float dy, float deltaTime);
    void render(SDL_Renderer* renderer);
};

#endif
