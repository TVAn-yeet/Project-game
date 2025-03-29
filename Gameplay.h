#pragma once


#include <ctime>
#include "Class.h"
#include "Var.h"

void renderGame() {
   
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderClear(renderer);

    
    
    SDL_RenderCopy(renderer, background, NULL, NULL);

    for (int i = 0; i < *MAP_HEIGHT; ++i) {
        for (int j = 0; j < *MAP_WIDTH; ++j) {  
            
            if (grass[j][i] == 2) {
                Grass g = Grass(j * *TILE_SIZE, i * *TILE_SIZE, true);
                grassrender(renderer,g.x,g.y,wolfgrass);
            }
        }
    }
    for (int i = 0; i < rocks.size(); ++i) {
        rocks[i].render(renderer,rockpic);
    }
    fox.render(renderer,fox1,fox2,foxpic);
    rab.render(renderer,rab1, rab2, rabpic, chose);
    for (int i = 0;i < wolfs.size();++i) {
        if (wolfs[i].active) {
            wolfs[i].render(renderer, wolf1, wolf2, tarx[i]);
        }
    }
    SDL_RenderPresent(renderer);
}


void handleGameEvents(float deltaTime, bool& foxpic) {
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
            foxpic = 0;
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            dx = fox.FOX_SPEED;
            foxpic = 1;
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
    for (int i = 0;i < wolfs.size();++i) {
        if (SDL_HasIntersection(&wolfs[i].rect, &fox.rect)) {
            ended = true;
            win = false;
            break;
        }
    }
}
void rabmove(float deltaTime) {
    if (moveable) {

                    rab.move(deltaTime, fox.x, fox.y, chose);
                    if (chose ==1||chose==3) {
                        if((nextY - rab.y) < 6 && (nextY - rab.y) > -6)
                            moveable = false;

                        
                    }
                    else {
                        if ((nextX - rab.x) < 6 && (nextX - rab.x) > -6)
                            moveable = false;
                    }
                    
    }
    else {
                    
                    rab.checkmove(fox.x, fox.y, chose, mov, nextX, nextY, moveable);
                    
    }
}
void wolfsmove(float deltaTime) {
    for (int i = 0;i < wolfs.size();++i) {
       
        if (wolfs[i].active) {
            wolfs[i].move(tarx[i],tary[i],deltaTime,rocks);
            
        }
        else {
            if (abs(fox.x - wolfs[i].x-10) < 160 && abs(fox.y - wolfs[i].y-10) < 3) {
                tarx[i] = fox.x;
                tary[i] = fox.y;
                wolfs[i].active = true;
                grass[wolfs[i].x/40][wolfs[i].y/40] = 1;
            }
            if (abs(fox.x - wolfs[i].x) < 3 && abs(fox.y - wolfs[i].y) < 160) {
                tarx[i] = fox.x;
                tary[i] = fox.y;
                wolfs[i].active = true;
                grass[wolfs[i].x/40][wolfs[i].y/40] = 1;
            }
        }
        
    }
    int i = 0;
    int d = wolfs.size();
    while (i < d) {
        if (wolfs[i].death) {
            
            tarx.erase(tarx.begin() + i);
            tary.erase(tary.begin() + i );
           
            wolfs.erase(wolfs.begin() + i);
            d = wolfs.size();
            
        }
        else {
            ++i;
        }
        
    }
   
}
