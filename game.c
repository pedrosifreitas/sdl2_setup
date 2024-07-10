#include <SDL.h> //bibliteca central do SDL
#include <stdio.h>
#include "src/src.h" //todos os arquivos fonte inclusos em src.h

#define NAME "Game" //nome do jogo ao abrir a janela (ah, vá)

#define FRAME_DELAY 16 //atraso em milisegundos para cada atualização de quadros

#define SCREEN_WIDTH 1280 //largura da janela
#define SCREEN_HEIGHT 720 //altura da janela

//Lógica de inicialização
void init(SDL_Renderer *renderer, SDL_Window *window)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) //verifica se o video foi inicializado
    {
        fprintf(stderr, "Não pôde inicializar o SDL: %s\n", SDL_GetError()); //gera mensagem de erro
        exit(1); //sai do programa com código de erro 1
    }

    window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); //cria janela

    if (!window) //verifica se a janela foi criada
    {
        fprintf(stderr, "Não foi possível abrir a janela: %s\n", SDL_GetError()); //gera mensagem de erro
        exit(1); //sai do programa com código de erro 1
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) //verifica se o renderizador foi criado
    {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError()); //gera mensagem de erro
        exit(1); //sai do programa com código de erro 1
    }

    //...
}

//Pega o input do jogador e executa uma ação
void getin(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) //verifica quais eventos o SDL registrou
    {
        switch (event.type)
        {
            case SDL_QUIT: //fecha o jogo quando o jogador clica no botão X da janela
                exit(0);
                break;

            case SDL_KEYDOWN : //lê se uma tecla foi pressionada
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE : //fecha o jogo se o jogador apertar ESC
                        exit(0);
                        break;

                    default : break;
                }
                break;
            
            case SDL_KEYUP : //lê se uma tecla foi solta, para desativar comandos que requerem que o jogador segure uma tecla 
                switch(event.key.keysym.sym)
                {
                    default: break;
                }
                break;

            default: break;
        }
    }
}


//Atualiza certos parâmetros
void update(void)
{
    //...
}

//renderiza o jogo
void render(SDL_Renderer *renderer)
{

    //...

    //limpa a janela do jogo (é necessário fazer isso antes de desenha o próximo frame, para não ficar um frame sobreposto ao outro)
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255); 
    SDL_RenderClear(renderer);
}