#include<iostream>
#include "Coin.h"
#include <allegro.h>
#include "Base.h"

BITMAP *coin;

void Coin::load()
     {
     coin=load_bitmap("sprites/coin.bmp",NULL);             
     }      

void Coin::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(coin,buffer,0,0,x,y,640,480);                     
     }
     
void Coin::clear_bitmaps(int n)
     {
     clear_bitmap(coin);            
     }
