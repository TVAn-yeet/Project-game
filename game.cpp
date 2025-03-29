#include "SDLwr.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Class.h"
#include "Var.h"
#include "End.h"

using namespace std;
void run() {
    startTime = SDL_GetTicks();
    Uint32 settime = startTime;

    while (running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        
        Uint32 elapsedTime = currentTime - startTime; 
        int seconds = elapsedTime / 1000;
        int minutes = seconds / 60;
        seconds = seconds % 60;

       
        
        if (inMenu == true && ended == false) {
            handleMenuEvents();
            renderMenu();
        }
        else {
            if (!ended) {
                
                if (settime < elapsedTime-10000.0f) {
                    settime = elapsedTime;
                    generatewolfs(tarx, tary, wolfs);
                }
                handleGameEvents(deltaTime,foxpic);
                Checkend();
                rabmove(deltaTime);
                wolfsmove(deltaTime);
                
                renderGame();
                
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
    generateGrass();
    generateRock();
    generatewolfs(tarx, tary, wolfs);
    running = true;
    if (running) {
        run();
    }
    Quit();
    return 0;
}
