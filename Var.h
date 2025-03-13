#pragma once
#include <SDL.h>
#include "Class.h"
#include <vector>

const int WINDOW_height = 600;
const int WINDOW_width = 800;
const int TILE_size = 40;
const int MAP_width = WINDOW_width / TILE_size;
const int MAP_height = WINDOW_height / TILE_size;
const int NUM_rock = 30;
const int* WINDOW_HEIGHT=&WINDOW_height;
const int* WINDOW_WIDTH=&WINDOW_width;
const int* TILE_SIZE=&TILE_size;
const int* MAP_WIDTH =&MAP_width;
const int* MAP_HEIGHT=&MAP_height;
const int* NUM_ROCK=&NUM_rock;



Fox fox;



Rabbit rab;
float nextX;
float nextY;
std::vector<bool> mov = { false,true,true,true };

int chose=0;

bool moveable = false;


bool inMenu=true ;
bool running;
bool ended = false;
bool win;

Uint32 startTime;
SDL_Window* window;
SDL_Renderer* renderer;
std::vector<Rock> rocks;
void generateRock() {

    srand(time(NULL));
    for (int i = 0; i < *NUM_ROCK; ++i) {
        int x = rand() % (*MAP_WIDTH);
        int y = rand() % (*MAP_HEIGHT);
        if (!(x == 0 && y == 0) && !(y == *MAP_HEIGHT/2 && x == *MAP_WIDTH / 2 )) {
            Rock r = Rock(x * *TILE_SIZE, y * *TILE_SIZE);
            rocks.push_back(r);
        }
    }
}

