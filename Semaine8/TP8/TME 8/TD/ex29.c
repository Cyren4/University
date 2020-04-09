#include "../liste_entiers.h"

#define VAL 2
#define VAL2 5

int 	len(cellule_t *liste)
{
	int i = 0;

	while (liste != NULL)
	{
		liste = liste->suivant;
		i++;
	}
	return (i);
}

int	existe(cellule_t *liste, int val)
{
	while(liste != NULL)
	{
		if( liste->donnee == val)
			return (1);
		liste = liste->suivant;
	}
	return (0);
}

cellule_t	*Renvoyer_element_debut(cellule_t *liste, int val)
{
	while(liste != NULL)
	{
		if( liste->donnee == val)
			return (liste);
		liste = liste->suivant;
	}
	return (NULL);	
}

cellule_t	*Renvoyer_element_fin(cellule_t *liste, int val)
{
	cellule_t *stock = NULL;

	while(liste != NULL)
	{
		if( liste->donnee == val)
			stock = liste;
		liste = liste->suivant;
	}
	if (stock == NULL)
		return (NULL);
	else
		return (stock);
}

void	Modifier_element(int val, int pos, cellule_t *liste)
{
	int count = 0;

	while (liste != NULL && count <= pos)
	{
		if (count == pos)
			liste->donnee = val;
		liste = liste->suivant;
		count++;
	}
}




int main()
{
	cellule_t *tete;

	tete = Creer_cellule(1);
	tete->suivant = Creer_cellule(2);
	tete->suivant->suivant = Creer_cellule(3);
	tete->suivant->suivant->suivant = Creer_cellule(2);

	Afficher_liste_int(tete);
	printf("\n est de len : %d\n", len(tete));
	printf("La valeur %d %s dans la liste\n", VAL, existe(tete, VAL) == 1 ? "est" : "n'est pas");
	printf("La valeur %d %s dans la liste\n", VAL2, existe(tete, VAL2) == 1 ? "est" : "n'est pas");

	printf("\ntest fonction: renvoyer_valeur_debut :\n");
	if (existe(tete,VAL) == 1)
		Renvoyer_element_debut(tete,VAL)->donnee == VAL ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
	else
		Renvoyer_element_debut(tete,VAL) == NULL ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");

	if (existe(tete,VAL2) == 1)
		Renvoyer_element_debut(tete,VAL2)->donnee == VAL2 ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
	else
		Renvoyer_element_debut(tete,VAL2) == NULL ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
	
	printf("\ntest fonction: renvoyer_valeur_fin :\n");
	if (existe(tete, VAL) == 1)
	{
		if (nb_occurences(VAL, tete) > 1)
			((Renvoyer_element_fin(tete,VAL)->donnee == VAL) && (Renvoyer_element_fin(tete,VAL)!= Renvoyer_element_debut(tete,VAL))) ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
		else
			Renvoyer_element_fin(tete,VAL)->donnee == VAL ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
	}
	else
		Renvoyer_element_fin(tete,VAL) == NULL ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");

	if (existe(tete,VAL2) == 1)
	{
		if (nb_occurences(VAL2, tete) > 1)
			((Renvoyer_element_fin(tete,VAL2)->donnee == VAL2) && (Renvoyer_element_fin(tete,VAL2)!= Renvoyer_element_debut(tete,VAL2))) ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
		else
			Renvoyer_element_fin(tete,VAL2)->donnee == VAL2 ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
	}
	else
		Renvoyer_element_fin(tete,VAL2) == NULL ? printf("la fonction marche\n") : printf("la fonction ne marche pas\n");
	
	printf("\nAVANT : \n");
	Afficher_liste_int(tete);
	Modifier_element(4 , 3, tete);
	printf("\nAPRES : \n");
	Afficher_liste_int(tete);
	return (0);
}
