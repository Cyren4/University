#include <stdio.h>
#include <math.h>

#define A 1
#define B 1
#define C 1

int	nb_racines(int a, int b, int c)
{
	int dis = b * b - 4 * a * c;

	if (dis > 0)
		return (2);
	if (dis == 0)
		return (1);
	else
		return (0);

}

int	nb_racines_delta(int a, int b, int c, int *delta)
{
	int dis = b * b - 4 * a * c;

	*delta = dis; 
	if (dis > 0)
		return (2);
	if (dis == 0)
		return (1);
	else
		return (0);

}

int	racines(int a, int b, int c, int delta, int *x1, int *x2)
{
	int sol;
	
	if ((sol = nb_racines(a, b, c)))
	{
		*x1 = (-b + sqrt(delta))/(2*a);
		*x2 = (-b - sqrt(delta))/(2*a);
	}
	else 
	{
		*x1 =(int)NULL;
		*x2 = (int)NULL;
	}
	return (nb_racines(a,b,c));
}

int	main()
{
	int delta;
	int nbr;
	int x1, x2;

	nbr = nb_racines_delta(A, B, C, &delta);
	racines(A, B, C, delta, &x1, &x2);
	printf("discriminant = %d\n", delta);
	if (!nbr)
		printf("il n'y a pas de solutions");
	else if(nbr == 1)
		printf("il y a une racine double : %d\n",x1);
	else
		printf("il y a %d racines :\n x1 = %d, x2 = %d\n", nbr,x1,x2);
	return (0);
}
