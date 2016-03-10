#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <allegro.h>
#include "Base.h"

class Background: public Base 
{
public:

virtual void load();

virtual void existance(int x, int y, int n, BITMAP *);

virtual void clear_bitmaps(int n);      
};

#endif
