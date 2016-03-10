#ifndef LEVEL2_H
#define LEVEL2_H
#include<allegro.h>
#include "Base.h"

class Level2: public Base
{
public:
    
virtual void load();

virtual void existance(int x, int y, int n, BITMAP *);

virtual void clear_bitmaps(int n);

};
#endif
