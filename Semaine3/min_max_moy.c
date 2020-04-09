#include <stdio.h>
#define VAL1 2
#define VAL2 7
#define VAL3 5
#define VAL4 9


void min_max() {

}

void stats () {

}

void afficher_resultat(float moyenne, int min, int max) {
  printf("max = %d, min = %d, moy = %.2f\n",max,min,moyenne);
}

int main() {
  float moy;
  int min, max;
  
  /* vous devrez bien sur modifier les parametres d'appel de la fonction stats une fois cette derniere completee */
  stats();
  
  /* vous devrez bien sur modifier les parametres d'appel de la fonction afficher_resultat */
  afficher_resultat(0.0,0,0);
  
  return 0;
}