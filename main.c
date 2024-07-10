#include <SDL_timer.h>
#include <stdio.h>
#include "game.c"

//essa parte do código pode ser ignorada
int main(int argc, char *argv[])
{
    SDL_Renderer *renderer; 
    SDL_Window *window;
    fprintf(stderr, "Running application...");

    init(renderer, window);

    while(1)
    {
        getin();

        update();
        render(renderer);

        SDL_Delay(FRAME_DELAY);
    }
}