#include "evenement.h"

Evenement::Evenement(){
}

void Evenement::ActiveAttenteEvenement(){
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            key[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            key[event.key.keysym.sym]=0;
            break;
        case SDL_QUIT:
            quit = 1;
            break;
        default:
            break;
        }
    }
}
