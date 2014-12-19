/**
 * Projet Code::Blocks minimaliste afin de donner un projet pre configure et pret à fonctionner
 * @author Alexandre "LittleWhite" Laurent
 */

#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void cleanup()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    const unsigned int windowWidth = 640;
    const unsigned int windowHeight = 480;

    SDL_Surface* pWindowSurface = NULL; // Ecran principal
    SDL_Surface* pImage = NULL; // Logo
    char mustContinue = 1; // Indicateur boolean pour la boucle principale

    int imgFlags = IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF; // Flags pour charger le support du JPG, PNG et TIF
    const char* imagePath = "./data/logo.jpg";

    SDL_Rect blitDestination;

    TTF_Font* pFont = NULL;
    const char* fontPath = "./data/font.ttf";
    SDL_Color fontColor = {99, 140, 222};
    SDL_Surface* pFontSurface = NULL;
    SDL_Rect texteDestination;

    // Demarre SDL
    if ( SDL_Init(SDL_INIT_VIDEO) == -1 )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL\n");
        return -1;
    }

    if ( IMG_Init(imgFlags) != imgFlags )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL_image : '%s'\n",IMG_GetError());
        cleanup();
        return -1;
    }

    if ( TTF_Init() == -1 )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL_TTF : '%s'\n",TTF_GetError());
        cleanup();
        return -1;
    }

    // Creer la fenetre
    pWindowSurface = SDL_SetVideoMode(windowWidth,windowHeight,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
	if ( pWindowSurface == NULL )
	{
	    fprintf(stderr,"Erreur lors de l'ouverture de la fenetre\n");
	    cleanup();
        return -2;
	}

	pImage = IMG_Load(imagePath);
	if ( pImage == NULL )
    {
        fprintf(stderr,"Erreur de chargement de l'image %s : %s\n",imagePath,IMG_GetError());
        cleanup();
        return -3;
    }

    // Charge la police
    pFont = TTF_OpenFont(fontPath,32);
    if ( pFont == NULL )
    {
        fprintf(stderr,"Erreur de chargement de la police %s : %s\n",fontPath,TTF_GetError());
        cleanup();
        return -3;
    }

    // Genere la SDL_Surface a partir de la police
    pFontSurface = TTF_RenderText_Solid(pFont,"Developpez.com",fontColor);
    if ( !pFontSurface )
    {
        fprintf(stderr,"Erreur pour generer le texte '%s'\n",TTF_GetError());
        cleanup();
        return -4;
    }

    // Une fois l'image chargée, nous pouvons calculer une position relative à celle-ci
    // Nous centrons l'image dans la fenêtre
    blitDestination.x = windowWidth/2 - pImage->w/2;
    blitDestination.y = windowHeight/2 - pImage->h/2;
    blitDestination.w = pImage->w;
    blitDestination.h = pImage->h;

    // Nous avons notre surface pour le texte donc nous calculons la position relative
    // Le texte est à un quart de la hauteur de l'ecran
    texteDestination.x = windowWidth/2 - pFontSurface->w/2;
    texteDestination.y = windowHeight/4;
    texteDestination.w = pFontSurface->w;
    texteDestination.h = pFontSurface->h;

    // Boucle principale
	while ( mustContinue )
	{
	    // Affiche le logo au centre de la fenêtre
	    if ( SDL_BlitSurface(pImage,NULL,pWindowSurface,&blitDestination) != 0 )
        {
            fprintf(stderr,"Erreur de copie de la surface sur l'écran\n");
            mustContinue=0;
        }
        // Affiche le texte
	    if ( SDL_BlitSurface(pFontSurface,NULL,pWindowSurface,&texteDestination) != 0 )
        {
            fprintf(stderr,"Erreur de copie du texte sur l'écran\n");
            mustContinue=0;
        }
        SDL_Flip(pWindowSurface);

	    SDL_Event event;
	    SDL_WaitEvent(&event);

        // Detecte si on clique sur la croix
	    if( event.type == SDL_QUIT )
	    {
            //On quitte le programme
            mustContinue = 0;
		}
		// Detecte si une touche est appuyee
		else if( event.type == SDL_KEYDOWN )
		{
            if ( event.key.keysym.sym == SDLK_ESCAPE )
            {
                mustContinue = 0;
            }
		}
	}

    SDL_FreeSurface(pFontSurface);
    TTF_CloseFont(pFont);
    SDL_FreeSurface(pImage);
    cleanup();

    return 0;
}
