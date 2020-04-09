#include <stdio.h>

#define NB_PLANETES 8

typedef	struct s_planete{
	char	nom[10];
	float	densite;
	float	d_sol;
	int	nb_sat;
}	planete;


void	affichePlanete(planete p)
{
	printf("Fiche planete:\t\033[0;32m %s\n\033[0m", p.nom);
	printf("- densite :\t%.1f\n", p.densite);
	printf("- distance au soleil (en km) :\t%.1f\n", p.densite);
	printf("- nombre de satellite : \t %d\n\n", p.nb_sat);
}

void	afficheToutesPlanetes(planete systemeSolaire[NB_PLANETES])
{
	int i;

	for (i = 0; i < NB_PLANETES; i++)
		affichePlanete(systemeSolaire[i]);
}

//return 0 si les 2 string identiques, leur difference sinon
int	compare(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	modifieDensite(planete systemeSolaire[NB_PLANETES])
{
	int choice, i = 0;
	char which[10];
	float new;

	printf("Voulez vous modifier les informations:\n1. Oui\n2. Non\n");
	scanf("%d", &choice);
	choice == 1 ? printf("Quelle planete?\n") : printf("\033[1;36mMerci et a bientot\033[0m\n") ;
	if (choice == 1)
	{
		scanf("%s", &which);
		while (i < NB_PLANETES && compare(systemeSolaire[i].nom, which) != 0)
			i++;
		if (i == NB_PLANETES && compare(systemeSolaire[i].nom, which) != 0)
		{
			printf("\033[0;31mCette planete n'existe pas\033[0m\n\n");
			printf("Essayez a nouveau \n");
			modifieDensite(systemeSolaire);
		}
		else
		{
			printf("la densite de la planete : \033[0;32m%s\033[0m actuelle est: %.1f \n ", systemeSolaire[i].nom, systemeSolaire[i].densite);
			printf("la nouvelle densite est :");
			scanf("%f", &new);
			systemeSolaire[i].densite = new;
			printf("\n \033[1;31m%s\t:\t%.1f\033[0m\n\n", systemeSolaire[i].nom,systemeSolaire[i].densite);
		}
		printf("\n\n\033[0;35mApres modification : \033[0m\n\n");	
		afficheToutesPlanetes(systemeSolaire);
	}
}

int main(){
	planete systemeSolaire[NB_PLANETES] = {{"Mercure", 5.42, 58, 0},
		{"Venus", 5.25, 108.2, 0},{"Terre", 5.52,149.6,1},
			{"Mars",3.94,227.9,2},{"Jupiter",1.314,778.3,16},
				{"Saturne",0.69,1427,17},{"Uranus",1.19,2869,15},
					{"Neptune",1.6,4496,2}};
	
	afficheToutesPlanetes(systemeSolaire);
	modifieDensite(systemeSolaire);
	return 0;
}
