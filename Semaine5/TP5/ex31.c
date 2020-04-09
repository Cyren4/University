#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_TIRAGE 10000

#define SIZE 4
#define V1 17
#define V2 28
#define V3 50
#define V4 5

void	calcule_borne_sup(int *tab)
{
	int i = 0;

	tab[i] -= 1;
	while (tab[i] < 99)
	{
		i++;
		tab[i] = tab[i - 1] + tab[i];
	}
}

int	tire_non_equi(int tab_borne[SIZE])
{
	int tirage = rand() % 100;
	int i = 0;	

	while (tirage > tab_borne[i] && i < SIZE)
		i++;
	return (i);
}

void	init(int tab[SIZE])
{
	int i = 0;

	while (i < SIZE)
	{
		tab[i] = 0;
		i++;
	}
}

int	main()
{
	srand(time(NULL));
	int i, res;
	int tab[SIZE] = {V1, V2, V3, V4};
	int ret[SIZE];

	init(ret);
	calcule_borne_sup(tab);
	for (i = 0; i < 4; i++)
		printf("%d\n",tab[i]);
	

	for (i = 0; i < NB_TIRAGE; i++)
	{
		res = tire_non_equi(tab);
		ret[res]++;
	}
	printf("\n\n");
	for (i = 0; i < 4; i++)
		printf("%d\n",ret[i]);

	return (0);
}
