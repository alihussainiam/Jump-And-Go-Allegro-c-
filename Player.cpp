#include<iostream>
#include "Player.h"
#include <allegro.h>
#include "Base.h"

BITMAP *player[9]; 

void Player::load()
     {
     player[0]=load_bitmap("sprites/1.bmp",NULL);
     player[1]=load_bitmap("sprites/2.bmp",NULL);
     player[2]=load_bitmap("sprites/3.bmp",NULL);
     player[3]=load_bitmap("sprites/2.bmp",NULL);
     player[4]=load_bitmap("sprites/4.bmp",NULL);
     player[5]=load_bitmap("sprites/5.bmp",NULL);
     player[6]=load_bitmap("sprites/6.bmp",NULL);
     player[7]=load_bitmap("sprites/7.bmp",NULL);
     player[8]=load_bitmap("sprites/1.bmp",NULL);
     }
     
void Player::existance(int x, int y, int n, BITMAP *buffer)
     {
     masked_blit(player[n],buffer,0,0,x,y,640,480);                 
     }

void Player::clear_bitmaps(int n)
     {
     clear_bitmap(player[n]);            
     }
