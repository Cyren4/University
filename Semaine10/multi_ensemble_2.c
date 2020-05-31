#include "multi_ensembles.h"

//calcule la taille d'une liste en recursion
int     taille_rec(element_t *ensemble, int i)
{
    if (ensemble != NULL)
        return (taille_rec(ensemble->suivant, i + ensemble->frequence));
    return (i);
}




element_t   *Supprime_frequence_inf_seuil(element_t *ensemble, int freq_min)
 {
    element_t *tete;
    tete = ensemble;
    while (ensemble != NULL)
    {
        if (ensemble->frequence < freq_min)
        {
            ensemble = Supprime_total_element_ensemble(ensemble, ensemble->valeur);
            tete = ensemble;
        }
        ensemble = ensemble->suivant;
    }
    return (tete);
 }

 int		Inclus_rec(element_t *e1, element_t *e2)
{
	if (e1 != NULL)
	{
		if (Recherche_val_trie(e2, e1->valeur) == NULL || Recherche_val_trie(e2, e1->valeur)->frequence < e1->frequence)
			return (0);
		Inclus_rec(e1->suivant, e2);
	}
	return (1);
}

static int     min(int n1, int n2)
{
    return (n1 < n2 == 1 ? n1 : n2 );
}

static int     max(int n1, int n2)
{
    return (n1 > n2 == 1 ? n1 : n2 );
}

element_t   *Union(element_t *e1, element_t *e2)
{
    element_t *uni = malloc(sizeof(element_t));

    uni = NULL;
    if (Inclus_rec(e1, e2) == 1|| Inclus_rec(e2, e1) == 1)
        return (Inclus_rec(e1, e2) == 1 ? e1 : e2);
    else
    {
        while (e1 != NULL )
        {
            if (Recherche_val_trie(e2, e1->valeur) != NULL)
                uni = Ajout_tete_ensemble(uni, e1->valeur, min(e1->frequence, Recherche_val_trie(e2, e1->valeur)->frequence));
            e1 = e1->suivant; 
        }
    }
    return (uni);
}

element_t   *Ajout_suivant(element_t *e1, int val, int freq)
{
	element_t *new;

	if (!(new = malloc(sizeof(element_t))))
		return (NULL);
	new->suivant = e1->suivant;
	new->valeur = val;
	new->frequence = freq;
    e1->suivant = new;
	return (new);
}

element_t   *Union_trie(element_t *e1, element_t *e2)
{
    element_t *uni = malloc(sizeof(element_t));
    element_t *tete;

    uni = NULL;
    tete = uni;
    if (Inclus_rec(e1, e2) == 1|| Inclus_rec(e2, e1) == 1)
        return (Inclus_rec(e1, e2) == 1 ? e1 : e2);
    else
    {
        while (e1 != NULL)
        {
            if (Recherche_val_trie(e2, e1->valeur) != NULL)
            {
                if (uni == NULL)
                {
                    uni = Ajout_tete_ensemble(uni, e1->valeur, min(e1->frequence, Recherche_val_trie(e2, e1->valeur)->frequence));
                    tete = uni;
                }
                else
                    uni = Ajout_suivant(uni,e1->valeur, min(e1->frequence, Recherche_val_trie(e2, e1->valeur)->frequence));
            }
            e1 = e1->suivant; 
        }
    }
    return (tete);
}

element_t   *Intersection_trie(element_t *e1, element_t *e2)
{
    element_t *inter = malloc(sizeof(element_t));
    element_t *tete;

    tete = e1;
    inter = NULL;
    while (e1 != NULL)
    {
        if (Recherche_val_trie(e2, e1->valeur) == NULL)
            inter = Ajout_ensemble_trie(inter, e1->valeur, e1->frequence);
        else
            inter = Ajout_ensemble_trie(inter, e1->valeur, max(Recherche_val_trie(e2, e1->valeur)->frequence, e1->frequence));
        e1 = e1->suivant;
    }
    e1 = tete;
    tete = e2;
    while (e2 != NULL)
    {
        if (Recherche_val_trie(e1, e2->valeur) == NULL)
            inter = Ajout_ensemble_trie(e1, e2->valeur, e2->frequence);
        e2 = e2->suivant; 
    }
    return (inter);
}

element_t   *Difference_triee(element_t *e1, element_t *e2)
{
    element_t *dif = malloc(sizeof(element_t));
 
    dif = NULL;
    if (Inclus_rec(e1, e2) == 1)
        return (dif);
    else
    {
        while (e1 != NULL)
        {
            if (Recherche_val_trie(e2, e1->valeur) == NULL)
                dif = Ajout_ensemble_trie(dif, e1->valeur, e1->frequence);
            else if (Recherche_val_trie(e2, e1->valeur)->frequence < e1->frequence)
                dif = Ajout_ensemble_trie(dif, e1->valeur, e1->frequence - Recherche_val_trie(e2, e1->valeur)->frequence);
            e1 = e1->suivant;
        }
    }
    return (dif); 
}

element_t   *Xor_triee(element_t e1, element_t e2)
{
    element_t *Xor = Difference_triee(e1, e2);

}
