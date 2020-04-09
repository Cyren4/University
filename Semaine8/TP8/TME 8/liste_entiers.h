#ifndef LISTE_ENTIERS_H
# define LISTE_ENTIERS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _cellule_t cellule_t;
struct _cellule_t {
	int donnee;
	cellule_t *suivant;
};


cellule_t	*creerListe(int n);
void		AfficherListeInt(cellule_t *liste);
int		nb_occurences(int val, cellule_t *liste);
int		tous_plus_grand(int val, cellule_t *liste);
cellule_t	*Maximum(cellule_t *liste);
int		Renvoyer_val_element_pos(int pos, cellule_t *liste);
cellule_t	*Concatener_it(cellule_t *liste1, cellule_t *liste2);
int		nb_maximum(cellule_t *liste);

void		Afficher_liste_int(cellule_t *liste);
cellule_t	*Creer_cellule(int n);
int		len(cellule_t *liste);
int		existe(cellule_t *liste, int val);
cellule_t	*Renvoyer_element_debut(cellule_t *liste, int val);
cellule_t	*Renvoyer_element_fin(cellule_t *liste, int val);
void		Modifier_element(int val, int pos, cellule_t *liste);

#endif
