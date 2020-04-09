#include <stdio.h>

void	affiche(char *str)
{
	while(*str)
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
			printf("%c", *str);
		str++;
	}
}

char	*alpha_only(char *str)
{
	char *s_alpha;

	while (*str)
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
		{
			*s_alpha = *str;
			s_alpha++;
		}
		str++;
	}
	return (s_alpha);
}

int	main()
{
	char *s = "qwertyu 2345678 asdfgh1";
	affiche(s);
	return (0);
}
