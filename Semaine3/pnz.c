#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 50
#define VMIN -20
#define VMAX 20

int valeur_aleatoire(int min, int max)
{
  return rand();
}

int main(){
  
  /* initialisation du g�n�rateur de nombres al�atoires */
  srand(time(NULL));
    
  return 0;
}