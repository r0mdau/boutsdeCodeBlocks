#include <iostream>
#include <string>
#include "personnage.h"
#include "arme.h"

using namespace std;

int main()
{
    Personnage david, goliath("Epée aiguisée", 20);
 // Création de 2 objets de type Personnage : david et goliath

    goliath.attaquer(david); // goliath attaque david
    david.boirePotionDeVie(20); // david boit une potion de vie qui lui rapporte 20 de vie
    goliath.attaquer(david); // goliath réattaque david
    david.attaquer(goliath); // david contre-attaque... c'est assez clair non ? ^^
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    goliath.attaquer(david);

    cout << "David" << endl;
    david.afficherEtat();
    cout << endl << "Goliath" << endl;
    goliath.afficherEtat();

    return 0;
}
