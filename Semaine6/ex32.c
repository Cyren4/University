
#include <stdio.h>

#define N 7

int	search_it(int *tab, int element, int taille)
{
	int i = 0;

	while(i < taille)
	{
		if (tab[i] == element)
			return (1);
		i++;
	}
	return (0);
}

int	search_rec(int *tab, int element, int taille)
{
	int ret = 0;

	if (0 >= taille)
		return (0);
	else if (*tab == element)
	{
		ret++;
		return ret;
	}
	else
		return(search_rec((tab + 1), element, taille-1));
	return (ret);
}

int	main()
{
	int tab[N] = {1,2,3,4,5,6,7};

	printf("%d", search_rec(tab, 0, N));

	return (0);
}
