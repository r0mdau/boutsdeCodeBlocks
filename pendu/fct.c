/*Jeu du pendu réalisé par Romain Dauby*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "fct.h"


char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'à l'\n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu

}

void afficherCoups(int cpt)
{
    printf("\nIl vous reste %d coups a jouer\n", cpt);
}

char proposezLettre()
{
    char maLettre;
    printf("\nProposez une lettre : ");
    maLettre = lireCaractere();
    return maLettre;
}

void afficherMotSecret(int *table, const char *table2)
{
    int i;
    printf("Quel est le mot secret ? ");
    for (i=0; i<strlen(table2); i++)
    {
        if(table[i]==1)
        printf("%c", table2[i]);
        else
        printf("*");
    }
}

void initialiser_motTrouve(int *table, int taille)
{
    int i;
    for (i=0; i<taille; i++)
    {
        table[i]=0;
    }
}

void testLettre(char lettre, int *table1, const char *table2)
{
    int i, j=0;
    for (i=0; i<strlen(table2); i++)
    {
        if(lettre==table2[i])
        {
            table1[i]=1;
            j=1;
        }
    }
    if (j==0)
    {
        cpt--;
    }
}

int testGagne(int *table, const char *motSecret)
{
    int i;
    int gagne=1;
    for (i=0; i<strlen(motSecret); i++)
    {
        if (table[i]==0)
        {
            gagne=0;
        }
    }
    return gagne;
}

