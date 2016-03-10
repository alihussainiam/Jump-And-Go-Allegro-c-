#ifndef BASE_H
#define BASE_H
#include<allegro.h>

class Base
{
public:
   
   virtual void load()=0;
   virtual void existance(int, int, int, BITMAP*)=0;      
   virtual void clear_bitmaps(int)=0;
   
};

#endif
