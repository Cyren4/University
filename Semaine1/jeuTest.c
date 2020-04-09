#include <stdio.h>

int alternative(int n1, int n2, int n3) {
  int res ;
	
  if (n1 > 8) {
    res = 3;
  } else {
    if (n3 == 20) {
      res = 2;
    } else {
      if ((n2 >= 10) && (n3 >= 10)) {
        res = 1;
      } else {
        res = 0;
      }
    }
  }
  
  return res;
}

int main(){
  // A compléter
  return 0;
}