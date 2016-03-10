#include<iostream>
#include "Background.h"
#include <allegro.h>
#include "Base.h"

BITMAP *back[13];

void Background::load()
     {
     back[0]=load_bitmap("sprites/back.bmp",NULL);
     back[1]=load_bitmap("sprites/back2.bmp",NULL);
     back[2]=load_bitmap("sprites/back3.bmp",NULL);
     back[3]=load_bitmap("sprites/back4.bmp",NULL);
     back[4]=load_bitmap("sprites/back5.bmp",NULL);
     back[5]=load_bitmap("sprites/back6.bmp",NULL);
     back[6]=load_bitmap("sprites/back7.bmp",NULL);
     back[7]=load_bitmap("sprites/back8.bmp",NULL);
     back[8]=load_bitmap("sprites/back9.bmp",NULL);
     back[9]=load_bitmap("sprites/back10.bmp",NULL);
     back[10]=load_bitmap("sprites/back11.bmp",NULL);
     back[11]=load_bitmap("sprites/back12.bmp",NULL);
     back[12]=load_bitmap("sprites/back13.bmp",NULL);             
     }      

void Background::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(back[n],buffer,0,0,x,y,640,480);                 
     }

void Background::clear_bitmaps(int n)
     {
     clear_bitmap(back[n]);            
     } 
