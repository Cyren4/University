#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define MIN 5

int	init(int tab[MAX])
{
	int i = 0;
	int taille = rand() % (MAX - MIN + 1) + MIN;

	while (i < taille)
	{
		tab[i] = rand() % 2;
		i++;
	}
	tab[taille] = -1;
	return (taille);
}

int	compress_tab(int tab_brut[], int tab_compress[])
{
	int count, i = 0;
	int ret = 0;
	while (tab_brut[i] != -1)
	{
		count = 0;
		while (tab_brut[i] == tab_brut[i + count])
			count++;
		if (count == 1)
		{
			tab_compress[ret] = tab_brut[i];
			ret++;
		}else{
			tab_compress[ret] = count;
			ret++;
			tab_compress[ret] = tab_brut[i];
			ret++;
		}
		i += count;
	}
	tab_compress[ret] = -1;
	return (ret);
}

int	decompress_tab(int tab_brut[], int tab_compress[])
{
	int i = 0;
	int count;
	int ret = 0; 

	while (tab_compress[i] != -1)
	{
		if (tab_compress[i] == 0 || tab_compress[i] == 1)
		{
			tab_brut[ret] = tab_compress[i];
			ret++;
			i++;
		}else{
			for (count = tab_compress[i]; count > 0; count--)
			{
				tab_brut[ret] = tab_compress[i + 1];
				ret++;
			}
			i += 2;
		}
	}
	tab_brut[ret] = -1;
	return (ret);
}

//return 0 si donnee brut, 1 si compresse
int	check(int tab[])
{
	while(*tab != -1)
	{
		if (!(*tab == 0 || *tab == 1))
			return (1);
		tab++;
	}
	return (0);
}

	//	printf("%d - tab1: %d  tab2: %d\n",i, tab1[i], tab2[i]);
int	compare(int tab1[], int tab2[])
{
	int i = 0;
	int new_tab[MAX];

	if (check(tab1) != check(tab2))
	{
		if (check(tab1) == 0)
		{
		compress_tab(tab1, new_tab);
		tab1 = new_tab;
		}
		else{
			compress_tab(tab2, new_tab);
			tab2 = new_tab;
		}
	}
	while (tab1[i] != -1 && tab2[i] != -1)
	{
		if (tab1[i] != tab2[i])
			return (0);
		i++;
	}
	return (1);
}


int	main()
{
	srand(time(NULL));
	int i;
	int tab_brut[MAX], tab_compress[MAX];
	
	int taille_brut  = init(tab_brut);
	printf("\033[1;31m Version Brut\n\033[0m");
	for (i = 0; i < taille_brut; i++)
		printf("%d _ ", tab_brut[i]);
	printf("\033[1;32m%d \033[0m", tab_brut[i]);
	printf("\n==>\033[0;32m%d\n\033[0m", taille_brut);
	printf("\n\n");

	int taille_comp = compress_tab(tab_brut, tab_compress);
	printf("\033[1;31m Version Compress\n\033[0m");
	for (i = 0; i < taille_comp; i++)
		printf("%d _ ", tab_compress[i]); 
	printf("\033[1;32m%d\033[0m ", tab_compress[i]); 
	printf("\n ==>\033[0;32m%d\n\033[0m", taille_comp);

	printf("\nComparaison:\n\n");
	(compare(tab_compress, tab_brut) == 1) ? printf("\033[1;32mTableaux identiques !\n") : printf("\033[0;31mTableaux differents\n"); 
	(compare(tab_brut, tab_compress) == 1) ? printf("\033[1;32mTableaux identiques !") : printf("\033[0;31mTableaux differents"); 
	return (0);
}
