#include "multi_ensembles.h"


/* Retourne un pointeur sur le premier element de valeur val, retourne NULL si aucun �l�ment n'a la valeur val */
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
		if (!(tete = malloc(sizeof(element_t))))
			return (NULL);
		tete->valeur = val;
		tete->frequence = freq;
		tete->suivant = ensemble;
		return (tete);
	}
	return (NULL);
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

	if (ensemble != NULL && ptr != NULL)
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

element_t	*Recherche_val_trie(element_t *ensemble, int val)
{
	while (ensemble != NULL && ensemble->valeur <= val)
	{
		if (ensemble->valeur == val)
			return (ensemble);
		ensemble = ensemble->suivant;
	}
	return (NULL);
}

element_t	*Ajout_ensemble_trie(element_t *ensemble, int val, int freq) 
{
	if (ensemble->valeur > val || Recherche_val(ensemble, val) != NULL)
		return (Ajout_tete_ensemble(ensemble, val, freq));
	else
	{
		element_t *tete = ensemble;
		element_t *new;
		if (!(new = malloc(sizeof(element_t))))
			return (NULL);
		new->valeur = val;
		new->frequence = freq;
		while (ensemble->suivant->valeur > val)
			ensemble = ensemble->suivant;
		new->suivant = ensemble->suivant;
		ensemble->suivant = new;
		return (tete);
	}
	return (NULL);
}

element_t	*Supprime_total_element_ensemble_trie(element_t *ensemble, int val)
{
	element_t *ptr = Recherche_val_trie(ensemble, val);
	element_t *tete;
	tete = ensemble;

	if (ensemble != NULL && ptr != NULL)
	{
		while (ensemble != NULL && ensemble->suivant != ptr)
			ensemble = ensemble->suivant;
		ensemble->suivant = ptr->suivant;
		free(ptr);
	}
	return (tete);
}

element_t	*Supprime_element_ensemble_trie(element_t *ensemble, int val)
{
	if (Recherche_val_trie(ensemble, val) == NULL)
		return (ensemble);
	else if (Recherche_val_trie(ensemble, val)->frequence == 1)
		return (Supprime_total_element_ensemble_trie(ensemble, val));
	else
		Recherche_val_trie(ensemble, val)->frequence--;
	return (ensemble);
}

//renvoie 1 si le premier multi-ensemble est inclus dans le deuxie`me, 0 sinon
int		Inclus(element_t *e1, element_t *e2)
{
	while (e1 != NULL)
	{
		if (Recherche_val(e2, e1->valeur) == NULL || Recherche_val(e2, e1->valeur)->frequence < e1->frequence)
			return (0);
		e1 = e1->suivant;
	}
	return (1);
}

//renvoie 1 si leur intersection est vide, 0 sinon.
int		Intersection_vide(element_t *e1, element_t *e2)
{
	while (e1 != NULL)
	{
		if (!(Recherche_val_trie(e2, e1->valeur) == NULL || Recherche_val_trie(e2, e1->valeur)->frequence < e1->frequence))
			return (0);
		e1 = e1->suivant;
	}
	return (1);	
}