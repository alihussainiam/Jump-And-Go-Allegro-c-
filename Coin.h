#ifndef COIN_H
#define COIN_H
#include<allegro.h>
#include "Base.h"

class Coin: public Base
{
public:
       
virtual void load();

virtual void existance(int x, int y, int n, BITMAP *);

virtual void clear_bitmaps(int n);

};

#endif
