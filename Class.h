#pragma once

#include <SDL.h>
#include "Var.h"
#include <vector>  

class Rock {
public:
    int x, y;
    SDL_Rect rect;

    Rock(int startX, int startY) {
        x = startX;
        y = startY;
        rect = { x, y, 40, 40 }; 
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

    Fox() : x(0), y(0), rect{ 0, 0, 20, 20 } {}

    Fox(int startX, int startY) : x(startX), y(startY), rect{ static_cast<int>(x), static_cast<int>(y), 20, 20 } {}

    void move(float dx, float dy, float deltaTime, std::vector<Rock>& rocks) {
       
        
        
        x += dx * deltaTime;
        y += dy * deltaTime;

    
        if (x < 0) x = 800 - rect.w;
        if (x + rect.w > 800) x = 0;
        if (y < 0) y = 600 - rect.h;
        if (y + rect.h > 600) y = 0;

        rect.x = static_cast<int>(x);
        rect.y = static_cast<int>(y);

        for (int i = 0; i < rocks.size(); ++i) {
            SDL_Rect rockRect = rocks[i].rect;

            if (SDL_HasIntersection(&rect, &rockRect)) {
                x -= dx * deltaTime;
                y -= dy * deltaTime;
                break;
            }
        }

        rect.x = static_cast<int>(x);
        rect.y = static_cast<int>(y);
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); 
        SDL_RenderFillRect(renderer, &rect);
    }
};

class Grass {
public:
    int x, y;
    SDL_Rect rect;
    bool active;

    Grass(int startX, int startY,bool startA) {
        x = startX;
        y = startY;
        active = startA;
        rect = { x, y, 40, 40 };
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 0, 100, 0, 0);
        SDL_RenderFillRect(renderer, &rect);
    }
};

class Rabbit {
public:
    const float RAB_SPEED = 150.0f;
    float x, y;
    SDL_Rect rect;

    Rabbit() : x(400), y(300), rect{ 400, 300, 20, 20 } {}

    Rabbit(int startX, int startY) : x(startX), y(startY), rect{ static_cast<int>(x), static_cast<int>(y), 20, 20 } {}

    void move(){
        
    }

    void render(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderFillRect(renderer, &rect);
    }
};
