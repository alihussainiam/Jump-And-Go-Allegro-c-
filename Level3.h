#ifndef LEVEL3_H
#define LEVEL3_H
#include<allegro.h>
#include "Base.h"

class Level3: public Base
{
public:

virtual void load();

virtual void existance(int x, int y, int n, BITMAP *);

virtual void clear_bitmaps(int n);


};
#endif
