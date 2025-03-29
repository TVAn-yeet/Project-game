#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Class.h"
#include <vector>

const int WINDOW_height = 600;
const int WINDOW_width = 800;
const int TILE_size = 40;
const int MAP_width = WINDOW_width / TILE_size;
const int MAP_height = WINDOW_height / TILE_size;
const int NUM_rock = 30;
int NUM_wolfs = 3;
const int* WINDOW_HEIGHT=&WINDOW_height;
const int* WINDOW_WIDTH=&WINDOW_width;
const int* TILE_SIZE=&TILE_size;
const int* MAP_WIDTH =&MAP_width;
const int* MAP_HEIGHT=&MAP_height;
const int* NUM_ROCK=&NUM_rock;



Fox fox;
bool foxpic;

Rabbit rab;
float nextX;
float nextY;
std::vector<bool> mov = { false,true,true,true };
int chose=0;
bool moveable = false;
bool rabpic=1;

std::vector<int> tarx, tary;
std::vector<Wolf> wolfs;




bool inMenu=true ;
bool running;
bool ended = false;
bool win;

Uint32 startTime;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* background ;
SDL_Texture* wolfgrass;
SDL_Texture* rockpic;
SDL_Texture* fox1;
SDL_Texture* fox2;
SDL_Texture* rab1;
SDL_Texture* rab2;
SDL_Texture* wolf1;
SDL_Texture* wolf2;
SDL_Texture* winpic;
SDL_Texture* losepic;
SDL_Texture* menupic;

std::vector<Rock> rocks;
int grass[20][15];

void generateGrass() {
    for (int i = 0;i < 15;++i) {
        for (int j = 0;j < 20;++j) {
            grass[j][i] = 1;
        }
    }
}

void generateRock() {

    srand(time(NULL));
    for (int i = 0; i < *NUM_ROCK; ++i) {
        int x = rand() % (*MAP_WIDTH);
        int y = rand() % (*MAP_HEIGHT);
        if (!(x == 0 && y == 0) && !(y == *MAP_HEIGHT/2 && x == *MAP_WIDTH / 2 )) {
            Rock r = Rock(x * *TILE_SIZE, y * *TILE_SIZE);
            rocks.push_back(r);
            grass[x][y] = 0;
        }
    }
}

void generatewolfs(std::vector<int>& tarx, std::vector<int>& tary, std::vector<Wolf>& wolfs) {
    int k = 0;
    srand(time(NULL));
    while(k<NUM_wolfs) {
        int x = rand() % (*MAP_WIDTH);
        int y = rand() % (*MAP_HEIGHT);
        if (grass[x][y]==1) {
            Wolf w = Wolf(x * *TILE_SIZE+10, y * *TILE_SIZE+10, false, false);
            wolfs.push_back(w);
            tarx.push_back(600);
            tary.push_back(700);
            grass[x][y] = 2;
            ++k;
        }
    }
}

