#include <stdio.h>

#define SIZE 4
void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	placeElt(int tab[], int i)
{
	int j = 0;

	while (j < i)
	{
		if (tab[j] > tab[i])
			ft_swap(&tab[i], &tab[j]);
		j++;
	}
}

int	main()
{
	int tab[SIZE] = {6,3,4,1};
	int i;

	printf("Before: \n");
	for (i = 0; i < SIZE; i++)
	{
		printf("tab[%d] : %d\n", i, tab[i]);
		placeElt(tab, i);
	}
	printf("\nAfter : \n");
	for (i = 0; i < SIZE; i++)
		printf("tab[%d] : %d \n",i, tab[i]);
	return (0);
}
