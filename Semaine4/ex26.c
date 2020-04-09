#include <stdio.h>

#define SIZE1 4
#define SIZE2 5

void	fusion_tri(float *tab1, float *tab2, int taille1, int taille2, float *tab)
{
	int i1 = 0, i2 = 0;

	while (i1 < taille1 || i2 < taille2)
	{
		if ((i2 == taille2 && i1 < taille1) ||
			 (i1 < taille1 && tab1[i1] <= tab2[i2]))
		{
			tab[i1 + i2] = tab1[i1];
			i1++;
		}
		if ((i1 == taille1 && i2 < taille2) || 
			(i2 < taille2 && tab2[i2] < tab1[i1]))
		{
			tab[i1 + i2] = tab2[i2];
			i2++;
		}
	}
}


int	main()
{
	float tab1[SIZE1] = {1, 3, 4, 5};
	float tab2[SIZE2] = {2, 6, 7, 8, 10};
	float tab[SIZE1 + SIZE2];
	int i;

	fusion_tri(tab1, tab2, SIZE1, SIZE2, tab);
	for (i = 0; i < SIZE1 + SIZE2; i++)
		printf("tab[%d] : %.1f \n",i, tab[i]);
	return (0);
}
