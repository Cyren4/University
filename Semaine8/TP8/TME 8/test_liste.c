#include "liste_entiers.h"

#define VAL 5

int main() {
	cellule_t *ma_liste=creerListe(5);

	printf("\naffichons la liste 1: \n");
	AfficherListeInt(ma_liste);

	printf("nombres d'occurences de %d : %d\n", VAL, nb_occurences(VAL, ma_liste));

	printf("tous les elements sont plus grand que %d : %s\n", VAL, tous_plus_grand(VAL, ma_liste) == 1 ? "oui" : "non");

	printf("maximum : %d\n", Maximum(ma_liste)->donnee);

	printf("le %deme element est : %d\n", VAL, Renvoyer_val_element_pos(VAL, ma_liste));

	printf("la valeur maximum est presente : %d fois\n", nb_maximum(ma_liste));

	printf("\ncreation liste 2 : \n");
	cellule_t *ma_liste2=creerListe(5);
	printf("\naffichons la liste : \n");
	AfficherListeInt(ma_liste2);
	printf("\naffichons la concatenation de la liste 1 et 2 :\n");
	AfficherListeInt(Concatener_it(ma_liste, ma_liste2));
	
	return 0;
}
