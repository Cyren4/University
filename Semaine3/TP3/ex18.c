#include <stdio.h>

void	echange(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	tri(int *a, int *b)
{
	if (*a > *b)
		echange(a, b);
}

void	tri_3(int *a, int *b, int *c)
{
	tri(a, b);
	tri(a, c);
	tri(b, c);
}

int	main()
{
	int a = 1;
	int b = 2;
	int c = 0;

	printf("avant : a = %d, b = %d\n", a , b);
	echange(&a, &b);
	printf("apres : a = %d, b = %d, c = %d\n", a , b, c);
	tri_3(&a, &b, &c);
	printf("fin : a = %d, b = %d, c = %d\n", a , b, c);

	return(0);
}
