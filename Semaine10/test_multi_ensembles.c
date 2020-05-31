#include "multi_ensembles.h"



int main()
{
	element_t *tete;
	int nb_element;

	printf("Combien 'éléments voulez vous dans la liste ?\n");
	scanf("%d", &nb_element);
	tete = Creation_ensemble(nb_element);
	Affiche_ensemble(tete);
//	test(tete);
	tete = Supprime_frequence_inf_seuil(tete, 2);
	nb_element = taille_rec(tete, 0);
	printf("\nIl y a %d element\n", nb_element);
	printf("\n\033[1;34mSee you!");
	return (0);
}
