#include <stdio.h>

#define TAILLE 10
#define NBE1 6

int	indiceInsert(int *tab, int taille, int nbE1, int e1)
{
	int i = 0;

	if (taille <= nbE1)
		return (-1);
	else{
		while (i < taille  && tab[i] <= e1)
		{
			if (tab[i] == e1)
				return (-1);
			i++;
		}
	}
	return (i);
}

int	insertElt(int *tab, int taille, int nbe1, int e1)
{
	int where = indiceInsert(tab, taille, nbe1, e1);
	int tmp;

	if (where == -1)
		return (0);
	else{
		while (where < nbe1 + 1)
		{
			tmp = tab[where];
			tab[where] = e1; 
			e1 = tmp;
			where++;
		}
	}
	return (1);
}

int	main()
{
	int tab[TAILLE];
	int i;

	printf("AVANT : \n");
	for (i = 0; i < TAILLE - 1 ; i++)
	{
		tab[i] = i*i;
		printf("\t\ttab %d : %d \n", i, tab[i]);
	}
	printf("\nindice d'insertion : %d\n" , indiceInsert(tab, TAILLE, TAILLE - 1, NBE1));
	printf("%s\n\n" , insertElt(tab, TAILLE, TAILLE - 1, NBE1) ? "success" : "failure" );
	printf("AFTER:\n");
	for (i = 0; i < TAILLE; i++)
		printf("\t\ttab %d : %d \n", i, tab[i]);

	return (0);
}
