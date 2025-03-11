#include <iostream>
#include <SDL.h>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include "Class.h"
#include "Default.h"
using namespace std;



class Game {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    bool inMenu;

    vector<Rock> rocks;
    Fox fox;
    Uint32 lastTime;

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

    Game() : fox(0, 0), inMenu(true) {
        running = true;
        lastTime = SDL_GetTicks();
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
            running = false;
        }
        window = SDL_CreateWindow("Cat Chit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window) {
            cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            running = false;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) {
            cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
            running = false;
        }
        generateRock();
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

    void renderMenu() {

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        SDL_Rect menuRect = { WINDOW_WIDTH / 4, WINDOW_HEIGHT / 3, WINDOW_WIDTH / 2, 100 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &menuRect);


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

    void handleMenuEvents() {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_RETURN: {
                    inMenu = false;
                    break;
                }
                case SDLK_ESCAPE: {
                    running = false;
                    break;
                }
                default:
                    break;
                }
            }
        }
    }
    void run() {
        while (running) {
            Uint32 currentTime = SDL_GetTicks();
            float deltaTime = (currentTime - lastTime) / 1000.0f;
            lastTime = currentTime;

            if (inMenu) {
                handleMenuEvents();
                renderMenu();
            }
            else {
                handleGameEvents(deltaTime);
                renderGame();
            }
            SDL_Delay(16);
        }
    }

    ~Game() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};

int main(int argc, char* argv[]) {
    Game game;

    if (game.running) {
        game.run();
    }
    return 0;
}
