
#include <string.h>
#define SIZE 10

typedef	struct point{
	int x;
	int y;
	char color[SIZE + 1];
} 		point;


typedef	struct rectangle{
	point bas_gauche;
	point haut_droit;
	char ctrait[SIZE];
	char cfond[SIZE];
}		rectangle;

void	dec_point()
{
	point mon_point;

	mon_point.x = 3;
	mon_point.y = 4;
	strcpy(mon_point.color, "red");
}

void	declaration()
{
	point p1, p2;
	rectangle mon_rectangle;

	p1.x = 100;
	p1.y = 200;
	strcpy(p1..couleur, "red");
	p2.x = 300;
	p2.y = 2;
	strcpy(p2.couleur, "red");
	mon_rectangle.bas_gauche = p1;
	mon_rectangle.haut_droit = p2;
	strcpy(mon_rectangle.ctrait, "red");
	strcpy(mon_rectangle.ctrait, "white");
}

int	points_dans_rectangle(point p, rectangle r)
{
	return ((p.x >= rec.bas_gauche.x) && (p.y >= rec.bas_gauche.y)
		&& (p.x <= rec.haut_droite.x) && (p.y<= rec.haut_droit.y));
}

int	intersection_rectangles()
{
	
}
