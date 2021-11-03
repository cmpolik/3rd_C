#include <stdio.h>
#include <math.h>
#include "include/line.h"

void setLine(Line *lin){
   Coord a,b;
   setCoord(&a);
   setCoord(&b);
   lin->start = a;
   lin->finish = b;

};

void printLine(Line lin){
   printCoord(lin.start);
   printCoord(lin.finish);
};

float Length(Line lin){
  float r;
  float kv1, kv2;
  kv1 = (lin.start.x-lin.finish.x);
  kv2 = (lin.start.y-lin.finish.y);
  r = sqrt(kv1 * kv1 + kv2 * kv2);
  return r;
};

// не совсем понял для чего эта ф-ия нужна, без нее решил...

//  void move(Line b, Coord nachalo){
//	  float dx, dy;
//	  dx = (b.start.x - b.finish.x);
//    dy = (b.start.y - b.finish.y); 	
//  }





