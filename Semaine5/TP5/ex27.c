#include <stdio.h>

#define TAILLE 15

int	check_space(char c)
{
	if ((c == '\t') || (c == '\n') || (c == ' ') ||
		 (c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	return (0);

}

int	nb_mot(char *str)
{
	int word = 0;
	int i = 0;

	while (str[i] && check_space(str[i]))
		i++;
	while (str[i])
	{
		if (!check_space(str[i]))
		{
			word++;
			while (str[i] && !(check_space(str[i])))
				i++;
		}
		else
			i++;

	}
	return (word);
}

int	main()
{
	char str[] = " 1 2 3 ";
	char input[TAILLE];

	printf("|%s| a : %d mots\n", str, nb_mot(str));

/*
	je pense que cela fonctionerait mieux avec les argument, le scanf ne prend pas en compte de qu'il y a apres les espaces
	on peut neanmoins essayer de faire une boucle whiel qui compte le nombre d'argument == nb_mot
	printf("rentrer phrase :  ");
	scanf("%s" , input);
	printf("votre phrase |%s| a : %d mots\n", input, nb_mot(input));
*/
	return (0);
}
