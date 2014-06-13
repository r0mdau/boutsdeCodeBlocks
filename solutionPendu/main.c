#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int gagne(int tableauGagne[]);
char lireCaractere();
int rechercheLettre(char lettre, char chaine[], int tableauGagne[]);

int main(int argc, char *argv[])
{
    int coups=10;
    char lettre=0;
    char chaine[] = "ROUGE";
    int i=0;
    int tableauGagne[5]={0};

    printf("Bienvenu dans le pendu !\n\n");

    while(coups>0 && !gagne(tableauGagne))
    {
        printf("\n\nIl vous reste %d coups a jouer", coups);
        printf("\nQuel est le mot secret ? ");
        for (i = 0 ; i < 5 ; i++)
        {
            if (tableauGagne[i])
                printf("%c", chaine[i]);
            else
                printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();
        if (!rechercheLettre(lettre, chaine, tableauGagne))
        {
            coups--;
        }
    }

    if (gagne(tableauGagne))
        printf("\n\nGagne ! Le mot secret etait bien : %s", chaine);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s", chaine);

        return 0;
}

int gagne(int tableauGagne[])
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < 6 ; i++)
    {
        if (tableauGagne[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char chaine[], int tableauGagne[])
{
    int i = 0;
    int bonneLettre = 0;

    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        if (lettre == chaine[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            tableauGagne[i] = 1; // On met à 1 le case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'à l'\n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}


