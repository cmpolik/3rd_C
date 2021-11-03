#include <stdio.h>
#include "include/coord.h"

void setCoord(Coord *a){
   scanf("%d%d",&(a->x),&(a->y));
};

void printCoord(Coord a){
  printf("%d  %d \n",a.x,a.y);
};


