#include "Class.cpp"
#include "SDLwr.cpp"
#include "Menu.cpp"
#include "Gameplay.cpp"
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
bool running;
bool inMenu;


Fox fox;


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

int main(int argc, char* argv[]) {
    CheckError();
    generateRock();
    running = true;
    if (running) {
        run();
    }
    Quit();
    return 0;
}
