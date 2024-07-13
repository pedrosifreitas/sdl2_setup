#include <SDL_timer.h> //para usar a função SDL_Delay()
#include <stdio.h> //para usar o terminal. O terminal não tem uso prático para o jogo, então fique a vontade para por quaisquer informações que possam ser úteis
#include "game.c" //função principal do jogo

//essa parte do código pode ser ignorada
int main(int argc, char *argv[])
{
    SDL_Renderer *renderer; //pointer para o renderizador
    SDL_Window *window; //pointer para a janela
    fprintf(stderr, "Running application...");

    init(renderer, window); //inicia a aplicação (em game.c)

    while(1) //loop 
    {
        getin(); //pega o input do jogador (ao apertar uma tecla, mover o mouse ou fazer alguma coisa na janela do jogo)

        update(); //atualização lógica do jogo
        render(renderer); //atualização do frame

        SDL_Delay(FRAME_DELAY); //cria um atraso de 16 milisegundos, equivalente ao tempo entre uma atualização de frame e outra em um monitor de 59-60Hz
        //pode ser que seja preciso criar um método mais compatível para monitores com frequências diferentes de 60Hz
    }
}
