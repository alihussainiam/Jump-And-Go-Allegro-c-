#ifndef LEVEL1_H
#define LEVEL1_H
#include<allegro.h>
#include "Base.h"

class Level1: public Base
{
public:

       
virtual void load();

virtual void existance(int x, int y, int n, BITMAP *);

virtual void clear_bitmaps(int n);


};

#endif
