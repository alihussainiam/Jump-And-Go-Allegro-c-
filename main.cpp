#include<iostream>
#include<allegro.h>
#include<fstream>
#include "Base.h"
#include "Background.h"
#include "Player.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Coin.h"
#include "Explosion.h"
 
using namespace std;

BITMAP *buffer;     

/////////////////////////////////////////////
/////INITIALIZATION
/////////////////////////////////////////////

void initial()
{
allegro_init();
install_mouse();
install_timer();
install_keyboard();
enable_hardware_cursor();
select_mouse_cursor(MOUSE_CURSOR_ARROW);
install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,0);
set_color_depth(32);
set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);    
set_window_title("JUMP n GO");   
buffer=create_bitmap(640,480);     
 
if(install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
    {
    allegro_message("Error initializing sound system");
    }
SAMPLE *sample;
    sample = load_sample("tracks/adventure_island.wav");
    if (!sample) 
    {
    allegro_message("Error reading wave file");
    }

    //play the sample with looping
    play_sample(sample, 255, 128, 1000, TRUE);
}

//////////////////////////////////////////////
/////MAIN MENU                                
//////////////////////////////////////////////

void menu(int x, int y,BITMAP *m)
{
show_mouse(buffer);

/////////////////////////////////////////
/////LOGO
/////////////////////////////////////////

BITMAP *logo=create_bitmap(x,y);
logo=load_bitmap("sprites/haha.bmp",NULL);
blit(logo, buffer, 0, 0, 0, 0, 640, 480);
blit(buffer, screen, 0, 0, 0, 0, 640, 480);
rest(2000);

//////////////////////////////////////////
/////MENU
//////////////////////////////////////////

BITMAP *menub;
menub=load_bitmap("menu/tile.bmp",NULL);
blit(menub, buffer,0, 0, 0, 0, 640, 480);
blit(buffer,screen, 0, 0, 0, 0, 640, 480);
while(1)
        {   
        if(mouse_b & 1)
        cout<<mouse_x<<" "<<mouse_y<<endl;
        if(mouse_x>=208 && mouse_x<=414 && mouse_y>=180 && mouse_y<=238  && (mouse_b & 1))
                    {
                    break;
                    }  
        if( mouse_x>=211 && mouse_x<=416 && mouse_y>=247 && mouse_y<=306 && (mouse_b & 1))
                    {
                    clear_bitmap(screen);   
                    BITMAP *how=create_bitmap(640,480);
                    menub=load_bitmap("menu/bak.bmp",NULL);
                    blit(menub, buffer,0, 0, 0, 0, 640, 480);
                    blit(buffer,screen, 0, 0, 0, 0, 640, 480);
                    readkey();
             
        //if(mouse_x>=8 && mouse_x<=150 && mouse_y>=410 && mouse_y<=462 && (mouse_b & 1))                             
                    clear_bitmap(screen);
                    BITMAP *menub=create_bitmap(640,480);
                    menub=load_bitmap("menu/tile.bmp",NULL);
                    blit(menub, buffer,0, 0, 0, 0, 640, 480);
                    blit(buffer,screen, 0, 0, 0, 0, 640, 480);
                    } 
       if(mouse_x>=459 && mouse_x<=566 && mouse_y>=380 && mouse_y<=436 && (mouse_b & 1))
                    {
                    exit(1);
                    }
       }
}

/////////////////////////////////////////////
/////LOADING
/////////////////////////////////////////////

void loading()
{
rect(screen,100,360,550,350,makecol(0,0,0));
BITMAP *buffer=create_bitmap(640,480);
BITMAP *load=create_bitmap(640,480);
load=load_bitmap("menu/loading.bmp",NULL);
blit(load,screen,0, 0, 0, 0, 640, 480);
blit(screen,buffer,0, 0, 0, 0, 640, 480);
rest(500);
clear_bitmap(load);

int i=0;
int x=100;
int y=360;
bool set=false;
while(x<560)

	{
	
		rectfill(screen,100,360,x,350,makecol(136,85,57));
		x=x+10;
        rest(40);
	}
}

///////////////////////////////////////////////
/////MAIN
///////////////////////////////////////////////

int main (int argc, char ** argv)
{
initial();
menu(640,480,buffer);
loading();
ofstream fout;
fout.open("gamescore.txt",ios::out|ios::app);

/////CREATING OBJECTS OF EACH CLASS
Base *ptr,*ptr1,*ptr2, *ptr3, *ptr4, *ptr5, *ptr6;

ptr = new Background;
ptr1 = new Player;
ptr2 = new Level1;
ptr3 = new Level2;
ptr4 = new Level3;
ptr5 = new Explosion;
ptr6 = new Coin;

ptr->load();
ptr1->load();
ptr2->load();
ptr3->load();
ptr4->load();
ptr5->load();
ptr6->load();

///////////////////
/////VARIABLES/////
///////////////////

int keypress=1;
int var=420;
int x1=260,y1=440;
int n=0,m=0,o=0,p=0,q=0,r=0;
int xPlayer=240,yPlayer=380;
int velx=0,vely=0;
int xStone=640,yStone=420;
int xBird=640, yBird=280;
int xBomb=640, yBomb=0;
int xCoin=600, yCoin=300;
int groundheight=380,skyheight=260;
int level1=0,level2=0,level3=0;
int x=280,y=480;
int birdcol=380;
int coincol=380;
int score=0;
const int gravity=10;

///////////////////
/////LOOP BODY/////
///////////////////
textout_ex(screen,font,"PRESS ANY KEY TO BEGIN",250,240,makecol(0,0,0),-1);
readkey();
BITMAP *over;
over=load_bitmap("sprites/over.bmp",NULL);


while(1)
{
        cout<<mouse_x<<" "<<mouse_y;
if(key[KEY_ESC])

                {
                exit(1);                    
                }
else
                {
                
                /////IF SPRITES OF PLAYER ARE FINISHED, START FROM BEGINNING
                
                if(n==8)
                        {
                        n=0;                    
                        }
                
                /////IF SPRITES OF BACKGROUND ARE FINISHED, START FROM BEGINNING
                
                if(m==12)
                        {
                        m=0;                        
                        }
                
                /////IF SPRITES OF BACKGROUND ARE FINISHED, START FROM BEGINNING
                
                if(p==3)
                        {
                        p=0;        
                        }
                
                /////IF SPRITES OF Explosions ARE FINISHED, START FROM BEGINNING
                if(r==4)
                        {
                        r=0;        
                        }
                
                /////BACKGROUND LOOP
                                
                if(key[KEY_SPACE] && y==groundheight)
                {
                    if(keypress>11)
                                  {
                                  birdcol=280;                   
                                  }
                    yPlayer=300;
                    coincol=300;
                    keypress++;              
                    vely=-50;
                    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
                        {
                        allegro_message("Error initializing sound system");
                        }
                    SAMPLE *jump ;
                    jump = load_sample("tracks/jump.wav");
                    if (!jump) 
                        {
                        allegro_message("Error reading wave file");
                         } 
                    play_sample(jump, 300, 128, 1000, TRUE);
                    rest(100);
                    stop_sample(jump);
                    n=2;
                }              
                yPlayer=yPlayer+10;   
                if(yPlayer>380)
                               {
                               yPlayer=380;       
                               }
                
                vely+=gravity;
                x+=velx;
                y+=vely;
                
                if(y >= groundheight)
                     {
                     y=groundheight;
                     }
                
                if(y==groundheight) // Moving Only on groundheight
                     {
                     n++;
                     }
                
                /////BACKGROUND LOOP
                
                ptr->existance(0,0,m,buffer);
                
                /////PLAYER LOOP
                
                ptr1->existance(x,y,n,buffer);
                
                /////COIN LOOP
                
                ptr6->existance(xCoin,yCoin,0,buffer);
                xCoin=xCoin-20;
                if(xCoin==0)
                            {
                            xCoin=640;                   
                            }
                blit(buffer,screen,0,0,0,0,640,480);
                
                if(xCoin==xPlayer && yCoin==coincol)
                                  {
                                  score++;
                                  //ptr6->clear_bitmaps(0);
                                  }
                
                /////STONE LOOP
                
                ptr2->existance(xStone, yStone, o,buffer);
                xStone=xStone-20;
                if(xStone==0)
                              {
                              xStone=640;    
                              }
                blit(buffer,screen,0,0,0,0,640,480);
                
                if(xPlayer==xStone && yPlayer+40==yStone)
                       {
                       fout<< "Your score is: " << score << "\n";
                       fout.close();
                       blit(over,buffer,0,0,0,0,640,480);
                       blit(buffer,screen,0,0,0,0,640,480);
                       rest(2000);
                       system("gamescore.txt");
                       rest(4000);
                       exit(1);
                       }
                
                /////BIRD LOOP
                
                if(keypress>5)
                {            
                ptr3->existance(xBird, yBird, p,buffer);
                blit(buffer,screen,0,0,0,0,640,480);
                xBird=xBird-20;
                p++;
                if(xBird==0)
                            {
                            xBird=640;                        
                            }
                
                if(xBird==xPlayer && yBird==birdcol)
                           {
                           fout<< "Your score is: " << score << "\n";
                           fout.close();
                           blit(over,buffer,0,0,0,0,640,480);
                           blit(buffer,screen,0,0,0,0,640,480);
                           rest(2000);
                           exit(1);
                           }
                }      
                 /////BOMB LOOP
                
                if(keypress>10)
                {
                ptr4->existance(xBomb, yBomb, q,buffer);
                blit(buffer,screen,0,0,0,0,640,480);
                xBomb=xBomb-20;
                yBomb=yBomb+20;
                if(xBomb==0)
                              {
                              xBomb=640;    
                              }
                if(yBomb==420)
                              {
                              if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
                              {
                              allegro_message("Error initializing sound system");
                              }
                              SAMPLE *explode;
                              explode = load_sample("tracks/explosion-01.wav");
                              if (!explode) 
                              {
                              allegro_message("Error reading wave file");
                              } 
                              play_sample(explode, 300, 128, 1000, TRUE);
                              while(r!=4)
                                         {
                                         
                                         ptr5->existance(xBomb, yBomb-60, r,buffer);
                                         blit(buffer,screen,0,0,0,0,640,480);
                                         r++;           
                                         }
                              yBomb=0; 
                              }
                if(xBomb==xPlayer && y==yPlayer)
                                  {
                                  fout<< "Your score is: " << score << "\n";
                                  fout.close();
                                  blit(over,buffer,0,0,0,0,640,480);
                                  blit(buffer,screen,0,0,0,0,640,480);
                                  rest(2000);
                                  exit(1);
                                  }
                            
                
                
                
                }
if(key[KEY_P])
                              {
                              textout_ex(screen,font,"PAUSE",280,240,makecol(0,0,0),-1);
                              readkey();         
                              }               
rest(100);
clear_bitmap(buffer);
m++;
clear_keybuf();
}
}

/////CLEARING ALL THE BITMAPS

ptr->clear_bitmaps(m);
ptr1->clear_bitmaps(n);
ptr2->clear_bitmaps(o);
ptr3->clear_bitmaps(p);
ptr4->clear_bitmaps(q);
ptr5->clear_bitmaps(r);
ptr6->clear_bitmaps(0);
return 0;
}
END_OF_MAIN();
