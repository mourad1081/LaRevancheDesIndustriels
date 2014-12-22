#include "evenement.h"

Evenement::Evenement(){
    memset(this,0,sizeof(Evenement));
}

void Evenement::ActiveAttenteEvenement(){
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            _touches[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            _touches[event.key.keysym.sym]=0;
            break;
        case SDL_QUIT:
            _quitter = 1;
            break;
        default:
            break;
        }
    }
}
