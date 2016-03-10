#include<iostream>
#include "Level2.h"
#include <allegro.h>
#include "Base.h"


BITMAP *Ahurdle[4];

void Level2::load()
     {
     Ahurdle[0]=load_bitmap("sprites/bird1.bmp",NULL);             
     Ahurdle[1]=load_bitmap("sprites/bird2.bmp",NULL);             
     Ahurdle[2]=load_bitmap("sprites/bird3.bmp",NULL);             
     Ahurdle[3]=load_bitmap("sprites/bird4.bmp",NULL);             
     } 
     
void Level2::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(Ahurdle[n],buffer,0,0,x,y,640,480);                     
     }
     
void Level2::clear_bitmaps(int n)
     {
     clear_bitmap(Ahurdle[n]);            
     }
