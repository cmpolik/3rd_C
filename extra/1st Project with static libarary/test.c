#include <stdio.h>
#include <stdlib.h>
#include "include/line.h"

int main(){

  Line a, b; 
  setLine(&a); 
  setLine(&b); 
  
  printf("lin=%0.2f\n",Length(a));
  printf("lin=%0.2f\n",Length(b));
	
  printLine(a);
  printLine(b);
  
  printf("%d \n", cmpLine(a, b));
	
  return 0;
}
