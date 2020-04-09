#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NB_CASE 31
#define T_MAX 300
#define T_MIN -200

void	init_temp_for(float *tab, int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		*tab = rand() % (T_MAX - T_MIN + 1) + T_MIN - 1;
		printf("%.1f \n",*tab);
		i++;
	}
}

void	init_temp(float *tab, int len)
{
	int i = 0;

	while (i < len)
	{
		tab[i] = (rand() % (T_MAX - T_MIN + 1) + T_MIN - 1) / (float)10;
		printf("%d -- %.1f \n", i + 1 , tab[i]);
		i++;
	}
}

float	moy_temp(float *tab, int len)
{
	float res = 0;

	while (*tab)
	{
		res += *tab;
		tab++;
	}
	return (res / (float)len);
}
void	check_neg(float	*tab)
{
	int nb = 0;
	float res = 0;

	while (*tab)
	{
		if (*tab < 0)
		{
			printf("%.1f\n", *tab);
			res += *tab;
			nb++;
		}
		tab++;
	}
	if (nb == 0)
		printf("Aucune temperature en dessous de zero\n");
	else{
		printf("Moyenne des temperature negatives %.1f\n", res/(float)nb);
	}
}

int main()
{
	srand(time(NULL));
	float *tab_temp; 
	float moyenne;

	if (!(tab_temp = malloc(sizeof(float) * (NB_CASE + 1))))
		return (-1);
	tab_temp[NB_CASE] = '\0';
	init_temp(tab_temp, NB_CASE);
	moyenne = moy_temp(tab_temp, NB_CASE);
	printf("moyenne de toutes les valeurs: %.1f\n", moyenne);
	check_neg(tab_temp);
	return (0);

}
