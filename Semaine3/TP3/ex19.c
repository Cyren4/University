#include <stdio.h>

#define VAL1 2
#define VAL2 7
#define VAL3 5
#define VAL4 9

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}


void	min_max(int *n, int *min, int *max)
{
	if (*n > *max)
		*max = *n;
	if (*n < *min)
		*min = *n;
}

int	check(n)
{
	if (n > 0)
		return (1);
	else
		return (0);
}

void	stats(int v1, int v2, int v3, int v4, int *min, int *max, float *moy)
{
	if (check(v1))
	{
		min_max(&v1, min, max);
		*moy = (float)v1;
		if (check(v2))
		{
			*moy = ((float)v1 + (float)v2)/2;
			min_max(&v2, min, max);
			if (check(v3))
			{
				*moy = ((float)v1 + (float)v2 + (float)v3)/3;
				min_max(&v3, min, max);
				if (check(v4))
				{
					min_max(&v4, min, max);
					*moy = ((float)v1 + (float)v2 + (float)v3 + (float)v4)/4;
				}
			}
		}	
		min_max(&v1, min, max);
	}else{
		*min = -1;
		*max = -1;
		*moy = -1;
	}
	printf("\n %.1f \n", *moy);
}

int		main()
{
	int min = VAL1, max = VAL1;
	int val1 = VAL1;
	int val2 = VAL2;
	int val3 = VAL3;
	int val4 = VAL4;
	float moy;

//	printf("avant : min = %d , max = %d, c = %d\n", min,max,c);
//	printf("apres : min = %d , max = %d, c = %d", min,max,c);

	printf("avant: \n VAL1 = %d, VAL2 = %d, VAL3 = %d, VAL4 = %d\n", VAL1, VAL2, VAL3, VAL4);
	printf("min : %d , max : %d , moy : %.2f\n",min, max, moy);
	stats(val1, val2, val3, val4, &min, &max, &moy);
	printf("apres: \n VAL1 = %d, VAL2 = %d, VAL3 = %d, VAL4 = %d\n", VAL1, VAL2, VAL3, VAL4);
	printf("min : %d , max : %d , moy : %.2f\n", min, max, moy);

	return (0);
}
