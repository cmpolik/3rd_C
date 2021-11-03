#include <stdlib.h>
#include <stdio.h>
#include "include/line.h"

int cmpLine(Line a, Line b){
	if((a.start.x - a.finish.x == b.start.x - b.finish.x) && (a.start.y - a.finish.y == b.start.y - b.finish.y))
		return 1;	
	return 0;
}
