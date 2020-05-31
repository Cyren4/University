#ifndef MULTI_ENSEMBLE_H
# define MULTI_ENSEMBLE_H

# include <stdio.h>
# include <stdlib.h>

typedef struct _element_t element_t;
struct _element_t{
	int valeur;
	int frequence;
	element_t *suivant;
};

void		Affiche_ensemble(element_t *ensemble);
element_t	*Creation_ensemble(int n);

element_t	*Recherche_val(element_t *ensemble, int val);
element_t	*Ajout_tete_ensemble(element_t *ensemble, int val, int freq);
element_t	*Supprime_total_element_ensemble(element_t *ensemble, int val);
element_t	*Supprime_element_ensemble(element_t *ensemble, int val);
element_t	*Recherche_val_trie(element_t *ensemble, int val);
element_t	*Ajout_ensemble_trie(element_t *ensemble, int val, int freq);
element_t	*Supprime_element_ensemble_trie(element_t *ensemble, int val);
element_t	*Supprime_total_element_ensemble_trie(element_t *ensemble, int val);
int			Inclus(element_t *e1, element_t *e2);
int			Intersection_vide(element_t *e1, element_t *e2);
element_t   *Supprime_frequence_inf_seuil(element_t *ensemble, int freq_min);

void		test(element_t *tete);
int			taille_rec(element_t *ensemble, int i);
element_t   *Supprime_frequence_inf_seuil(element_t *ensemble, int freq_min);
int			Inclus_rec(element_t *e1, element_t *e2);
element_t   *Union(element_t *e1, element_t *e2);
element_t   *Ajout_suivant(element_t *e1, int val, int freq);
element_t   *Union_trie(element_t *e1, element_t *e2);
element_t   *Intersection_trie(element_t *e1, element_t *e2);
element_t   *Difference_triee(element_t *e1, element_t *e2);

#endif
