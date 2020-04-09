#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NBTOURS 10
#define NBLANCERS 2
#define NBQUILLES 10
#define ESSAI 3
#define NBTOUR 10

/* Il sera probablement nécessaire de modifier les parametres et valeur de retour des fonctions 
  lancer, lancer_aleatoire, score et jeu */

/* Les declarations actuelles permettent de compiler et d'executer le programme */

int	lancer_aleatoire(int nbquilles) 
{
	return rand() % (nbquilles + 1);
}

int	lancer(int nbquilles)
{
	int mq = -1;
	int try = ESSAI;

	while ((mq < 0 || mq > nbquilles) && --try > 0)
	{
		printf("nb de quilles restantes %d rentrer le nombres de quilles renversees : ", nbquilles);
		scanf("%d", &mq);
		if (mq < 0 || mq > nbquilles)
			printf("valeur saisie incorrecte\n nombre d'essai restant : %d \n", try);
	}
	if (mq < 0 || mq > nbquilles)
		return (lancer_aleatoire(nbquilles));
	return (mq);
}

void	score(int *res, int nbquilles, int *spare, int *strike1, int *strike2)
{
	*res += nbquilles;
	if (*strike2)
	{
		*res += nbquilles;
		*strike2 = 0;
	}
	if (*strike1)
	{
		*res += nbquilles;
		*strike1 = 0;
		*strike2 = 1;
	}else if (*spare)
	{
		*res += nbquilles;
		*spare = 0;
	}
}

void	tour(int *res, int *spare, int *strike1, int *strike2)
{
	int nbquilles = 10;
	int fallen;

//	fallen = lancer(nbquilles);
	fallen = lancer_aleatoire(nbquilles);
	printf("Quilles renversees : %d\n", fallen);
	nbquilles -= fallen;
	score(res, fallen, spare, strike1, strike2);
	if (nbquilles == 0)
	{
		*strike1 = 1;
		printf("score incomplet : strike en cours\n");
	}else{
//		fallen = lancer(nbquilles);
		fallen = lancer_aleatoire(nbquilles);
		printf("Quilles renversees : %d\n",fallen);
		nbquilles -= fallen;
		score(res, fallen, spare, strike1, strike2);
		if (nbquilles == 0)
		{
			*spare = 1;
			printf("score incomplet : spare en cours\n");
		}
	}
}

void	toursup(int *res, int *spare)
{
	int nbquilles = 10;
	int fallen;

//	fallen = lancer(nbquilles);
	fallen = lancer_aleatoire(nbquilles);
	printf("Quilles renversees : %d\n", fallen);
	nbquilles -= fallen;
	*res += fallen;	
}	

int	jeu()
{
	int res = 0;
	int spare = 0, strike1 = 0, strike2 = 0;
	int i;

	for (i = 1; i <= NBTOUR; i++)
	{
		printf("TOUR %d\n", i);
		tour(&res, &spare, &strike1, &strike2); 
		printf("resultat %d : %d\n",i,  res);
		printf("________________________________________________________\n");
	}
	if (spare || strike1)
	{
		printf("TOUR SUPPLEMENTAIRE: \n");
		if (strike1)
			tour(&res, &spare, &strike1, &strike2); 
		else
			toursup(&res, &spare); 
	}
	return (res);
}

int	main() 
{
	int res;
 	srand(time(NULL));

 	res = jeu();
	printf("\n ===> \t\t resultat finale : %d", res); 
 	return (0);
}
