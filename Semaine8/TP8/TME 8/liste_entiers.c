#include <stdio.h>
#include <stdlib.h>
#include "liste_entiers.h"

cellule_t	*creerListe(int n) {
	/* cree une liste de n entiers saisi par l'utilisateur
	   renvoie l'adresse du premier element de la liste */
	int i;
	int val;

	cellule_t *tete=NULL;
	cellule_t *ptr;
	printf("Saisie des %d elements de la liste\n",n);

	for (i = 0; i < n; i++) 
	{
		printf("Element %d :",i+1);
		scanf("%d",&val);
		ptr=malloc(sizeof(cellule_t));
		ptr->donnee = val;
		ptr->suivant = tete;
		tete = ptr;
	}
	return tete;
}

void	AfficherListeInt(cellule_t *liste)
{
	while (liste != NULL)
	{
		printf("%d\t", liste->donnee);
		liste = liste->suivant;
	}
	printf("\n");
}

int	nb_occurences(int val, cellule_t *liste)
{
	int count = 0;

	while (liste != NULL)
	{
		if (liste->donnee == val)
			count++;
		liste = liste->suivant;
	}
	return (count);
}

int	tous_plus_grand(int val, cellule_t *liste)
{
	while (liste != NULL)
	{
		if (liste->donnee < val)
			return (0);
		liste = liste->suivant;
	}
	return (1);
}

cellule_t	*Maximum(cellule_t *liste)
{
	int val_max = liste->donnee;
	cellule_t *ptr_max = liste;

	while (liste != NULL)
	{
		if (liste->donnee > val_max)
		{
			val_max = liste->donnee;
			ptr_max = liste;
		}
		liste = liste->suivant;
	}
	return (ptr_max);
}

int	Renvoyer_val_element_pos(int pos, cellule_t *liste)
{
	int i;

	while (i < pos && liste != NULL)
	{

		liste = liste->suivant;
		i++;
	}
	return (liste->donnee);
}

cellule_t	*Concatener_it(cellule_t *liste1, cellule_t *liste2)
{
	cellule_t *tete = liste1;

	if (liste1 == NULL && liste2 == NULL)
		return (NULL);
	while (liste1->suivant != NULL)
		liste1 = liste1->suivant;
	liste1->suivant = liste2;
	return (tete);
}

int		nb_maximum(cellule_t *liste)
{
	int count = 1;
	int val_max = liste->donnee;
	liste = liste->suivant;

	while (liste != NULL)
	{
		if (liste->donnee == val_max)
			count++;
		else if (liste->donnee > val_max)
		{
			val_max = liste->donnee;
			count = 1;
		}
		liste = liste->suivant;
	}
	return (count);
}
