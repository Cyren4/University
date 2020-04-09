#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_AMIS 4 
#define NB_JOURS 7

int	val(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int	price(void)
{
	return (val(30, 50));
}


void	init(float tab[NB_JOURS][NB_AMIS])
{
	int jour = 0, ami = 0;

	while (jour < NB_JOURS)
	{
		ami = 0;
		while (ami < NB_AMIS)
		{
			tab[jour][ami] = 0;
			ami++;
		}
		jour++;
	}
}

void	fullfill(float tab[NB_AMIS])
{
	int i = 0;
	float total = price();
	float share = -(float)total/(float)NB_AMIS; 
	int khalas = rand() % NB_AMIS;
	
	printf("%d  paye %.1f\n",khalas, total);
	while (i < NB_AMIS)
	{
		tab[i] = share;
		i++;
	}
	tab[khalas] = (float)total + share;
}

void	affichage(float tab[NB_JOURS][NB_AMIS])
{
	int ami = 0;
	int jour;

	printf("\t|");
	for(jour = 0; jour < NB_JOURS; jour++)
		printf("\t%d", jour);
	printf("\n---------------------------------------------------------------------\n");

	while (ami < NB_AMIS)
	{
		printf("%d\t|\t", ami);
		jour = 0;
		while (jour < NB_JOURS)
		{
			printf("%.2f\t", tab[jour][ami]);
			jour++;
		} 
		printf("\n");
		ami++;
	}
}

int	main()
{
	srand(time(NULL));
	float tab[NB_JOURS][NB_AMIS];
	int jours = 0;

	init(tab);
	for (jours = 0; jours < NB_JOURS; jours++)
	{
		printf("jour %d : ", jours);
		fullfill(tab[jours]);
	}
	affichage(tab);
	return (0);
}
