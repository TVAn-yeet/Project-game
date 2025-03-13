#include "SDLwr.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Class.h"
#include "Var.h"
#include "End.h"
using namespace std;
void run() {
    startTime = SDL_GetTicks();

    while (running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        Uint32 elapsedTime = currentTime - startTime; 
        int seconds = elapsedTime / 1000;
        int nextsec = 0;
        int minutes = seconds / 60;
        seconds = seconds % 60;
        if (inMenu == true && ended == false) {
            handleMenuEvents();
            renderMenu();
        }
        else {
            if (!ended) {
               
                
                handleGameEvents(deltaTime);
                renderGame();
                Checkend();
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
                    for (int i : mov) {
                        cout << i << " ";
                    }
                    cout <<chose<<' ';
                    cout << endl;
                }
                else {
                    
                    rab.checkmove(fox.x, fox.y, chose, mov, nextX, nextY, moveable);
                    
                }
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
