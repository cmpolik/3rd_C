#include <stdio.h>
#include <math.h>
#include "include/coord.h"

int cmpCoord(Coord a, Coord b){
   if(a.x == b.x && a.y == b.y)
     return 1;
   return 0;
};
