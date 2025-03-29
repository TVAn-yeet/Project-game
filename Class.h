#pragma once

#include <SDL.h>
#include "SDLwr.h"

#include "Var.h"
#include <vector>  
#include<iostream>
#include <SDL_image.h>



void renderTexture(SDL_Texture* texture, int x, int y,
    SDL_Renderer* renderer)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}



class Rock {
public:
    int x, y;
    SDL_Rect rect;

    Rock(int startX, int startY) {
        x = startX;
        y = startY;
        rect = { x, y, 40, 40 }; 
    }

    void render(SDL_Renderer* renderer, SDL_Texture* rockpic) {
        renderTexture(rockpic, x, y, renderer);
    }
};

class Fox {
public:
    const float FOX_SPEED = 250.0f;
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

    void render(SDL_Renderer* renderer, SDL_Texture* fox1, SDL_Texture* fox2, bool& foxpic) {
        if (foxpic == 0) {
            renderTexture(fox1, x-10, y-10, renderer);
        }
        else {
            renderTexture(fox2, x-10, y-10, renderer);
        }
    }
};

class Grass {
public:
    int set;
    int x, y;
    SDL_Rect rect;
    bool active;

    Grass(int startX, int startY,bool startA) {
        x = startX;
        y = startY;
        active = startA;
        rect = { x, y, 40, 40 };
    } 

    
        
};
void grassrender(SDL_Renderer* renderer,int x, int y, SDL_Texture* wolfgrass) {
    renderTexture(wolfgrass, x, y, renderer);
}


class Rabbit {
public:
    const float RAB_SPEED = 250.0f;
    float x, y;
    SDL_Rect rect;
    

    Rabbit() : x(400), y(300), rect{ 400, 300, 20, 20 } {}

    Rabbit(int startX, int startY) : x(startX), y(startY), rect{ static_cast<int>(x), static_cast<int>(y), 20, 20 } {}

    void move(float deltaTime, float foxx, float foxy,int& chose) {
        

        switch (chose) {
        case 0: { x -= RAB_SPEED * deltaTime; break;}
        case 1: { y += RAB_SPEED * deltaTime; break;}
        case 2: { x += RAB_SPEED * deltaTime; break;}
        case 3: { y -= RAB_SPEED * deltaTime; break;}
        default: break;
        }
      
        if (x < 0) x = 800 - rect.w;
        if (x + rect.w > 800) x = 0;
        if (y < 0) y = 600 - rect.h;
        if (y + rect.h > 600) y = 0;

        rect.x = static_cast<int>(x);
        rect.y = static_cast<int>(y);
        
    }

    void checkmove(float foxx, float foxy, int& chose, std::vector<bool>& mov,float& nextX,float& nextY,bool& moveable) {
       
        
        float maxDistance = -1;
        nextX = x, nextY = y;
        
        for (int i = 0;i < 4;++i) {
            float tempX = x, tempY = y;

            
            if (mov[i]==true) {
                
                switch (i) {
                case 0: tempX -= 150; break;
                case 1: tempY += 150; break;
                case 2: tempX += 150; break;
                case 3: tempY -= 150; break;
                default: break;
                }
                if (tempX < 0) tempX = tempX + 800 - rect.w;
                if (tempX + rect.w > 800) tempX = tempX + rect.w - 800;
                if (tempY < 0) tempY = tempY + 600 - rect.h;
                if (tempY + rect.h > 600) tempY = tempY + rect.h - 600;
                float dist1, dist2;
                if (tempX - foxx > 400|| tempX - foxx < -400) {
                    dist1 =800- abs(tempX - foxx) ;
                }
                else {
                    dist1 = tempX - foxx;
                }
                if (tempY - foxy > 300||tempY-foxy<-300) {
                    dist2 = 600-abs(tempY - foxy) ;
                }
                else {
                    dist2 = tempY - foxy;
                }
                float dist = dist1*dist1+dist2*dist2;
               
               
                if (dist > maxDistance ) {
                    maxDistance = dist;
                    chose = i;
                    
                    nextX = tempX;
                    nextY = tempY;
                }
            }
        }     
        for (int i = 0;i < 4;++i) {
            if (i == chose) {
                mov[i] = false;
            }
            else {
                mov[i] = true;
            }
        }
        
        moveable = true;
    }

    void render(SDL_Renderer* renderer, SDL_Texture* rab1, SDL_Texture* rab2,bool& rabpic, int&chose) {
        if (chose == 0) {
            rabpic = 0;
        }
        if (chose == 2) {
            rabpic = 1;
        }
        if (rabpic == 0) {
            renderTexture(rab1, x-10, y-10, renderer);
        }
        else {
            renderTexture(rab2, x-10, y-10, renderer);
        }
    }
};
class Wolf {
public:
    int x, y;
    bool active;
    bool death;
    SDL_Rect rect;
    float WOLF_SPEED = 400.0f;

    Wolf() : x(-1), y(-1), rect{ -40, -40, 20, 20 } {}

    Wolf(int startX, int startY, bool startA, bool startD) {
        x = startX;
        y = startY;
        active = startA;
        death = startD;
        rect = { static_cast<int>(x)+10, static_cast<int>(y)+10, 20, 20 };
    }

    void move(int &tarx, int& tary, float deltaTime, std::vector<Rock>& rocks) {
        if (abs(x - tarx) > 3 || abs(y - tary) > 3) {
            int dx = (x != tarx) ? (tarx - x) / abs(x - tarx) : 0;
            int dy = (y != tary) ? (tary - y) / abs(y - tary) : 0;
            x += dx*WOLF_SPEED * deltaTime;
            y += dy*WOLF_SPEED * deltaTime;


            if (x < 0) x = 800 - rect.w;
            if (x + rect.w > 800) x = 0;
            if (y < 0) y = 600 - rect.h;
            if (y + rect.h > 600) y = 0;

            rect.x = static_cast<int>(x);
            rect.y = static_cast<int>(y);

            for (int i = 0; i < rocks.size(); ++i) {
                SDL_Rect rockRect = rocks[i].rect;

                if (SDL_HasIntersection(&rect, &rockRect)) {
                    death = true;
                    break;
                }
            }

            rect.x = static_cast<int>(x);
            rect.y = static_cast<int>(y);
        }
        else {
            death = true;
        }
    }

    
    void render(SDL_Renderer* renderer, SDL_Texture* wolf1, SDL_Texture* wolf2, int& tarx) {
        if (x-tarx>0) {
            renderTexture(wolf1, x - 10, y - 10, renderer);
        }
        else {
            renderTexture(wolf2, x - 10, y - 10, renderer);
        }
    }
};
