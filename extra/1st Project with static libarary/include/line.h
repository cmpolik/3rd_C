#include "coord.h"

typedef struct{
  Coord start; 
  Coord finish; 
}Line;

void setLine(Line*);

void printLine(Line);

float Length(Line);

int cmpLine(Line, Line);

void move(Line, Coord);
