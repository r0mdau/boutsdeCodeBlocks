/*Jeu du pendu réalisé par Romain Dauby*/

#ifndef FCT_H_INCLUDED
#define FCT_H_INCLUDED

int cpt;


char lireCaractere();
void afficherCoups(int cpt);
char proposezLettre();
void afficherMotSecret(int *table, const char *table2);
void initialiser_motTrouve(int *table, int taille);
void testLettre(char lettre, int *table1, const char *table2);
int testGagne(int *motTrouve, const char *motSecret);

#endif // FCT_H_INCLUDED
