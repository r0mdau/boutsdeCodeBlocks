#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int continuer=1;

void pause ()
{
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type) /* On teste le type d'évènement */
        {
            case SDL_QUIT: /* Si c'est un évènement QUITTER */
                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            case SDL_KEYDOWN: /* Si appui d'une touche */
                continuer = 0;
                break;

        }

    }
}

int main(int argc, char *argv[])
{



    SDL_Surface *ecran = NULL, *zozor=NULL;
 /* Cette variable servira plus tard à gérer les évènements */


    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);

    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));

    /* On centre zozor à l'écran */
    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;

    SDL_BlitSurface(zozor, SDL_Rect positionZozor, NULL, 0);
    pause();
    SDL_Quit();

    return EXIT_SUCCESS;
}
