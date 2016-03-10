#include<iostream>
#include "Level1.h"
#include <allegro.h>
#include "Base.h"

BITMAP *hurdle;

void Level1::load()
     {
     hurdle=load_bitmap("sprites/stone.bmp",NULL);             
     }      

void Level1::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(hurdle,buffer,0,0,x,y,640,480);                     
     }
     
void Level1::clear_bitmaps(int n)
     {
     clear_bitmap(hurdle);            
     }
