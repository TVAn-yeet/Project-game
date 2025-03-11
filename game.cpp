#include "SDLwr.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Class.h"
#include "Var.h"
#include "End.h"
using namespace std;
void run() {
    while (running) {
        
        if (inMenu == true && ended == false) {
            handleMenuEvents();
            renderMenu();
        }
        else {
            if (!ended) {
                Uint32 currentTime = SDL_GetTicks();
                float deltaTime = (currentTime - lastTime) / 1000.0f;
                lastTime = currentTime;
                handleGameEvents(deltaTime);
                renderGame();
                Checkend();
            }
            else {
                if (win) {
                    renderWin();
                    handleEnd();
                }
                else {
                    renderLose();
                    handleEnd();
                }
            }
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
