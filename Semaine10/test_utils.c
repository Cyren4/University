#include "multi_ensembles.h"


//ajout nouvel element
static void	Test_ajout(element_t *tete, int i )
{
	int val, freq, choice = 1;

	while (choice == 1)
	{
		printf("\nAjout d'un nouvel element %s?\n\t\033[1;32m1.Oui\n\t\033[1;31m2.Non\n", i == 1 ? "en tete" : "trie");
		scanf("%d", &choice);
		if (choice != 1)
			return;
		else
		{
			printf("\n\033[1;34mChoix valeur:\n");
			scanf("%d", &val);
			printf("\nChoix frequence:\n\033[0m");
			scanf("%d", &freq);
			tete = i == 1 ? Ajout_tete_ensemble(tete, val, freq) : Ajout_ensemble_trie(tete, val , freq);
			Affiche_ensemble(tete);
		}
	}
}

static void	Test_suppression(element_t *tete, int i)
{
	int val, choice = 1;

	while (choice == 1)
	{
		printf("\nSupression d'un element ?\n\t\033[1;32m1.Oui\n\t\033[1;31m2.Non\n");
		Affiche_ensemble(tete);
		scanf("%d", &choice);
		if (choice != 1)
			return;
		else
		{
			printf("\n\033[1;34mChoix valeur:\n");
			scanf("%d", &val);
			tete = i == 1 ? Supprime_element_ensemble(tete, val) : Supprime_element_ensemble_trie(tete, val) ;
			Affiche_ensemble(tete);
		}
	}
}

static void	Test_suppression_total(element_t *tete, int i)
{
	int val, choice = 1;

	while (choice == 1)
	{
		printf("\nSupression total d'un element ?\n\t\033[1;32m1.Oui\n\t\033[1;31m2.Non\n");
		Affiche_ensemble(tete);
		scanf("%d", &choice);
		if (choice != 1)
			return;
		else
		{
			printf("\n\033[1;34mChoix valeur:\n");
			scanf("%d", &val);
			tete = i == 1 ? Supprime_total_element_ensemble(tete, val) : Supprime_total_element_ensemble_trie(tete, val) ;
			Affiche_ensemble(tete);
		}
	}
}

static int		which_test(element_t *tete, int i)
{
	int choice = 1;

    while (choice != 0)
	{
		printf("\033[1;34mWhich test do you want to try?\n\033[0;m");
		printf("\t1 - Ajout element %s\n", i == 1? "en tete" : "trie");
		printf("\t2 - Supression element %s\n", i == 1 ? "" : "trie");
		printf("\t3 - Supression totale element %s\n",i == 1 ? "" : "trie");
		printf("\t4 - Display list\n");
		printf("\t5 - Else\n");
		printf("\t0 - exit\n");
		scanf("%d", &choice);
		if (choice == 1)
			Test_ajout(tete, i);
		else if (choice == 2)
			Test_suppression(tete, i);
		else if (choice == 3)
			Test_suppression_total(tete , i);
		else if (choice == 4)
			Affiche_ensemble(tete);	
		else
			return (choice);
	}
	return (choice);
}

void	test(element_t *tete)
{
	int choice = 1;

	while (choice != 0)
	{
		printf("\nIs the list sorted?\n\t\033[1;32m1.Oui\n\t\033[1;31m2.Non\n\t\033[1;35m0.exit\n");
		scanf("%d", &choice);
		if (choice == 0)
			return;
		else if (choice == 1)
			choice = which_test(tete, 2);
		else if (choice == 2)
			choice = which_test(tete, 1);
	}
}