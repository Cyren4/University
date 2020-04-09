#include <stdio.h>

int	compte(char *str, char c)
{
	int count = 0;

	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	affiche_occur(char *str)
{
	int i = 0, j;
 
	while (str[i])
	{
		j = 0;
		while (j < i && str[i] != str[j])
			j++;
		if (j == i)
			printf("nombre d'occurence de %c : %d\n", str[i], compte(str, str[i]));
		i++;
	}
}

int	main(int ac, char **av)
{
	int i = 0;

	while (++i < ac)
	{
		printf("mot : %d\n",i);
		affiche_occur(av[i]);
		printf("--------------------------------------------");
	}
	return (0);
}
