#include "../liste_entiers.h"

cellule_t	*Creer_cellule(int nb)
{
	cellule_t *cell; 
	cell = malloc(sizeof(cellule_t));
	cell->donnee = nb;
	cell->suivant = NULL;
	return(cell);
}


void	Afficher_liste_int(cellule_t *liste)
{
	/* Affiche les champs donnee des elements de la liste */
	cellule_t *cell = liste; while (cell != NULL) {
		printf("%d ", cell->donnee);
		cell = cell->suivant;
	}
	printf("\n");
}

/*int main()
{
	cellule_t *tete;

	tete = Creer_cellule(1);
	tete->suivant = Creer_cellule(2);
	tete = tete->suivant;
	tete->suivant = Creer_cellule(3);
	
	Afficher_liste_int(tete);
	return (0);
}



int	main() 
{
	cellule_t *nCell1=NULL, *nCell2=NULL, *nCell3=NULL;
	nCell1 = Creer_cellule(1);
	nCell2 = Creer_cellule(2);
	nCell3 = Creer_cellule(3);

	nCell1->suivant = nCell2;
	nCell2->suivant = nCell3;
	
	Afficher_liste_int(nCell1);
	nCell1->suivant = nCell3;
	Afficher_liste_int(nCell1);
//	nCell3->suivant = nCell2;
//	Afficher_liste_int(nCell1);
	return 0;
}*/
