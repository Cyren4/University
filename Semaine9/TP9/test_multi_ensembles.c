#include <stdio.h>
#include "multi_ensembles.h"

int main()
{
	element_t *tete;
	int val, freq, choice = 1;

	tete = Creation_ensemble(5);
	Affiche_ensemble(tete);
	
	printf("\nTest suppression de la case 4 :\n");
	tete = Supprime_total_element_ensemble(tete, 4);
	Affiche_ensemble(tete);
	printf("\nTest frequence - 1 de la case 6 : \n");
	tete = Supprime_element_ensemble(tete, 6);
	Affiche_ensemble(tete);
	
	while (choice == 1)
	{
		printf("\nAjout d'un nouvel element ?\n\t\033[1;32m1.Oui\n\t\033[1;31m2.Non\n");
		scanf("%d", &choice);
		if (choice != 1)
			return (0);
		else
		{
			printf("\n\033[1;34mChoix valeur:\n");
			scanf("%d", &val);
			printf("\nChoix frequence:\n\033[0m");
			scanf("%d", &freq);
			tete = Ajout_tete_ensemble(tete, val, freq);
			Affiche_ensemble(tete);
		}
	}

	return 0;
}
