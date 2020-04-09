#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VMIN -500 
#define VMAX 544
#define NB_VALEURS 10

//on suppose que max>min

int	valeur_aleatoire(int min, int max)
{
	return ( (rand() % (max - min + 1)) + min - 1);
}

void	pos_neg_zero(int nb, int *pos, int *neg, int *zero)
{
	if (nb > 0)
		*pos += 1;
	else if (nb < 0)
		*neg += 1;
	else
		*zero+= 1;
}

int	main()
{
	int nb;
	int i;
	int pos = 0;
	int neg = 0;
	int zero = 0;

	srand(time(NULL));
	printf("nous allons tirer %d valeurs comprises entre %d et %d:\n", NB_VALEURS, VMIN, VMAX);
	for (i = 0; i < NB_VALEURS; i++)
	{
		printf("%d\n ", (nb = valeur_aleatoire(VMIN, VMAX)));
		pos_neg_zero(nb, &pos, &neg, &zero);
		
	}
		printf("==> pos = %d , neg = %d, zero = %d \n", pos, neg, zero);
	return (0);
}

