#ifndef PLAYER_H
#define PLAYER_H
#include<allegro.h>
#include "Base.h"

class Player: public Base
{
public:

virtual void load();

virtual void existance(int x, int y, int n, BITMAP *);

virtual void clear_bitmaps(int n);

};
#endif
