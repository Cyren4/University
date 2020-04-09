#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	est_deb_rec(char *s1, char *s2)
{
	int ret = 0;

	if (ft_strlen(s1) > ft_strlen(s2) || !s2)
		return (0);
	if (*s1 == '\0')
		ret++;
	else if (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		return (est_deb_rec(s1 + 1, s2 + 1));
	else
		ret = 0;
	return ret;
}

int	est_incluse(char *s1, char *s2)
{
	int ret = 0;

	if (est_deb_rec(s1,s2) == 1)
		ret++;
	else if (*s2 != '\0' && ret == 0)
		return (est_incluse(s1, s2 + 1));
	return (ret);

}


int	main()
{
	char *s1 = "alphabetqq";
	char *s2 = "alphabet";

	printf("%d", est_incluse(s1,s2));
}
