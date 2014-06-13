#include <stdio.h>
#include <stdlib.h>

int main()
{

    int colonne;
    int plateau [7][6];
    int i,j ;
    int compteur = 0;
    int joueur;
    int hauteurs[7];


    for(j=0;j<7;j++)
    {
        for(i=0;i<6;i++)
        {
            plateau [j][i]=0;
        }
        hauteurs[j]=0;
    }

    do
     {
        for(joueur=1;joueur<=2;joueur++)
        {
            do
            {
                printf("joueur %d \nEntrez une colonne (0-6) :",joueur);
                compteur++;
                scanf("%d", &colonne);
            }
            while(colonne <0 || colonne >6 || hauteurs[colonne]>=6);
            plateau[colonne][hauteurs[colonne]]=joueur;
            hauteurs[colonne]++;
            for(i=5;i>=0;i--)
            {
                printf("|");
                for(j=0;j<7;j++)
                {
                    switch (plateau[j][i])
                    {
                        case 0: printf(" ");
                        break;
                        case 1: printf("x");
                        break;
                        case 2: printf("0");
                        break;
                    }
                }

                printf("|\n");
            }
        }
     }while(compteur<42);

    return 0;
}
