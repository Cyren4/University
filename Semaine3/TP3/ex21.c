#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIERRE 1
#define FEUILLE  PIERRE + 1
#define CISEAUX  FEUILLE + 1
#define NBESSAIS 3
#define POINTSGAGNANTS 3

void	affichage_objet(int obj)
{
	if (obj == PIERRE)
		printf("PIERRE");
	else if (obj == FEUILLE)
		printf("FEUILLE");
	else
		printf("CISEAUX");
	printf("\n");
}

int	valeur_aleatoire(int min, int max)
{
	return  rand() % (max - min + 1) + min - 1;
}

int	choix_ordinateur()
{
	return (valeur_aleatoire(1,3));
}


int	choix_joueur()
{
	int jeu = 0;
	int essai = NBESSAIS;

	while (essai > 0 && !(jeu >= 1 && jeu <= 3))
	{
		printf("choisir un entier entre 1 et 3 : ");
		scanf("%d", &jeu);
		essai--;
		if (jeu > 3 || jeu < 1)
			printf("valeur saisie incorrecte\n nombre d'essai restant : %d\n", essai);
	}
	if (jeu > 3 || jeu < 1)
	{
		printf("la valeur a ete choisie aleatoirement\n");
		return (valeur_aleatoire(1,3));
	}
	else
		return (jeu);
}

void	score(int cpu, int joueur, int *Scpu, int *Sjoueur)
{
	if (cpu == joueur)
		return;
	else if (joueur == cpu + 1 || joueur == cpu - 2)
			*Sjoueur += 1;
	else 
		*Scpu += 1;
}
void	affichage_partie(int tour, int cpu, int joueur, int Scpu, int Sjoueur)
{
		printf("\n\nTour : %d \n", tour);
		printf("\tl'ordinateur a joue : ");
		affichage_objet(cpu);	
		printf("\n");
		printf("\tle joueur a joue : ");
		affichage_objet(joueur);
		printf("\n");
		printf("le score est de : \n");
		printf("\tcpu = %d\t\t-\t", Scpu);
		printf("joueur = %d \n", Sjoueur);
}

void	jeu()
{
	int Scpu = 0;
	int Sjoueur = 0;
	int cpu,player;
	int tour = 0;

	while (Scpu < POINTSGAGNANTS && Sjoueur < POINTSGAGNANTS)
	{
		cpu = choix_ordinateur();
		player = choix_joueur();
		score(cpu, player, &Scpu, &Sjoueur);
		affichage_partie(++tour, cpu, player, Scpu,Sjoueur);
		printf("\n");
	}
	printf("le gagnant est :    %s", Scpu > Sjoueur ? "Ordinateur" : "Joueur");
}

int main()
{
	srand(time(NULL));
	jeu();
	return (0);
}
