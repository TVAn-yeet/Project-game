#pragma once
void handleEnd(){
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_RETURN: {
                rocks.clear();
                generateRock();
                fox.x = 0;
                fox.y = 0;
                
                fox.rect.x = 0;
                fox.rect.y = 0;
                
                rab.rect.x = 400;
                rab.rect.y = 300;
                rab.x = 400;
                rab.y = 300;
               
                chose = 0;
               
                inMenu = true;
                ended = false;
                mov = { false,true,true,true };
                break;
            }
            default:
                break;
            }
        }
    }
}
void renderWin(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_Rect menuRect = { *WINDOW_WIDTH / 4, *WINDOW_HEIGHT / 3, *WINDOW_WIDTH / 2, 100 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &menuRect);
    SDL_RenderPresent(renderer);
}
void renderLose(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_Rect menuRect = { *WINDOW_WIDTH / 4, *WINDOW_HEIGHT / 3, *WINDOW_WIDTH / 2, 100 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &menuRect);
    SDL_RenderPresent(renderer);
}
