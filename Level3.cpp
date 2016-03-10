#include<iostream>
#include "Level3.h"
#include <allegro.h>
#include "Base.h"


BITMAP *Omorehurdle;

void Level3::load()
     {
     Omorehurdle=load_bitmap("sprites/bomb.bmp",NULL);                         
     }

void Level3::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(Omorehurdle,buffer,0,0,x,y,640,480);                     
     }

void Level3::clear_bitmaps(int n)
     {
     clear_bitmap(Omorehurdle);            
     }  
