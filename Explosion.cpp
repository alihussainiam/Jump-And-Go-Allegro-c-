#include<iostream>
#include "Explosion.h"
#include <allegro.h>
#include "Base.h"


BITMAP *explosion[5];

void Explosion::load()
     {
     explosion[0]=load_bitmap("sprites/explo1.bmp",NULL);                         
     explosion[1]=load_bitmap("sprites/explo2.bmp",NULL);                         
     explosion[2]=load_bitmap("sprites/explo3.bmp",NULL);                         
     explosion[3]=load_bitmap("sprites/explo4.bmp",NULL);                         
     explosion[4]=load_bitmap("sprites/explo5.bmp",NULL);                         
     }

void Explosion::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(explosion[n],buffer,0,0,x,y,640,480);                     
     }

void Explosion::clear_bitmaps(int n)
     {
     clear_bitmap(explosion[n]);            
     }   
