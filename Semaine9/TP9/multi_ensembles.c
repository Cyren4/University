#include <stdio.h>
#include <stdlib.h>
#include "multi_ensembles.h"


/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun élément n'a la valeur val */
element_t	*Recherche_val(element_t *ensemble, int val)
{
	while (ensemble != NULL)
	{
		if (ensemble->valeur == val)
			return (ensemble);
		ensemble = ensemble->suivant;
	}
	return (NULL);
}

/* Ajoute l'element val en tete de l'ensemble s'il n'apparait pas dans l'ensemble, augmente sa frequence de 1 sinon */
element_t	*Ajout_tete_ensemble(element_t *ensemble, int val, int freq) 
{
	if (Recherche_val(ensemble, val) != NULL)
	{
		Recherche_val(ensemble,val)->frequence += freq;
		return(ensemble);
	}
	else
	{
		element_t *tete;
		if(!(tete = malloc(sizeof(element_t))))
			return (NULL);
		tete->valeur = val;
		tete->frequence = freq;
		tete->suivant = ensemble;
		return (tete);
	}
	return NULL;
}


/* Affche tous les elements d'un ensemble avec leur frequence */
void		Affiche_ensemble(element_t *ensemble) {
	element_t *ptr = ensemble;
	
	if (! ensemble)
		printf("l'ensemble n'existe pas \n");
	else
	{
		while (ptr != NULL) 
		{
			printf("val : \033[0;35m%d\033[0m, frequence : \033[0;035m%d\n\033[0m",ptr->valeur,ptr->frequence);
			ptr=ptr->suivant;
		}
	}
}

/* Saisie des n elements d'un ensemble */
element_t	*Creation_ensemble(int n) {
	element_t *ensemble = NULL;

	int i = 0;
	int val;

	for (i=0; i < n; i++) {
		printf("Saisie d'un entier: ");
		scanf("%d", &val);
		ensemble = Ajout_tete_ensemble(ensemble, val, 1);
	}
	return ensemble;
}

element_t	*Supprime_total_element_ensemble(element_t *ensemble, int val)
{
	element_t *ptr;
	element_t *tete;
	tete = ensemble;
	ptr = Recherche_val(ensemble, val);

	if (ensemble && ptr != NULL)
	{
		while (ensemble->suivant != ptr && ensemble != NULL)
			ensemble = ensemble->suivant;
		ensemble->suivant = ptr->suivant;
		free(ptr);
	}
	return (tete);
}

element_t	*Supprime_element_ensemble(element_t *ensemble, int val)
{
	if (Recherche_val(ensemble, val) == NULL)
		return (ensemble);
	else if (Recherche_val(ensemble, val)->frequence == 1)
		return (Supprime_total_element_ensemble(ensemble, val));
	else
		Recherche_val(ensemble, val)->frequence--;
	return (ensemble);
}
