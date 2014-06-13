/*Jeu du pendu réalisé par Romain Dauby*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fct.h"


int cpt=10;

int main()
{
    printf("Bienvenue dans le pendu !\n\nJoueur 1 : saisi le mot secret :\n");
    const char *motSecret;
    scanf("%s", motSecret);
    int *motTrouve;
    motTrouve=(int*) malloc (strlen(motSecret));
    initialiser_motTrouve(motTrouve, strlen(motSecret));
    char maLettre;


    do
    {

        afficherCoups(cpt);
        afficherMotSecret(motTrouve, motSecret);
        maLettre=proposezLettre();
        testLettre(maLettre, motTrouve, motSecret);

        if (testGagne(motTrouve, motSecret))
        {
            afficherMotSecret(motTrouve, motSecret);
        }
    }while(!testGagne(motTrouve, motSecret) && cpt > 0);

    if (cpt==0)
    {
        printf("\nVous avez fait plus de 10 coups, vous etes pendus !\n");
    }
    else
    {
        printf("\n\nBravo, vous avez trouve le mot secret !!!\n");
    }

    free(motTrouve);
    return 0;
}
