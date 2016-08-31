#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h>//
//#include<stdafx.h>

using namespace std;

//initwindow(400, 300);



void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int tailX[100],tailY[100],nTail;
bool gamestatus;
int score=0 ;
int x , y , fx,fy,sx,sy,count1=0;
int height=30 ,width=35 ;
enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction DIR;

void setup()
{

gamestatus=false;
//score=0;

//printf("%d",score);
DIR=STOP;

x=width/2;
y=rand()%29+1;
fx=rand()%34+1;
fy=rand()%29+1;
if(fx==x&&fy==y)
{
    fx=rand()%34+1;
fy=rand()%29+1;
}


}


void design()
{


//system("cls");

int i ,j ;



for(i=0;i<=height;i++)
{
    for(j=0;j<=width;j++)
    {    if(i==0)
           printf("#");
      else if(i==height)
             printf("#");
       else if(j==0)
         printf("#");
          else if(j==width)
           printf("#");

        else if(x==j&&i==y)
            {

           printf("O");

            }
     else if(fx==j&&fy==i)
         printf("X");
         else
            printf(" ");


    }


printf("\n");
}

//printf("\nSCORE=%d",score);
//gamestatus=false;


}

void input()
 {

     if(_kbhit())
     {

     switch(_getch())
     {
case 'a':
      case 'A':DIR=LEFT;
             break;
      case 'd':
      case 'D':DIR=RIGHT;
             break;

      case 'w':
        case 'W':DIR=UP;
               break;
        case 's':
            case 'S':DIR=DOWN;
                break;

case 'T':gamestatus=true;
     }


     }


 }



void logic()
 {//printf("#");

int prevx=tailX[0];
int prevy=tailY[0];
tailX[0]=x;
tailY[0]=y;
int prev2x,prev2y;
for(int i=1;i<nTail;i++)
 {
   prev2x=tailX[i];
   prev2y=tailY[i];
   tailX[i]=prevx;
   tailY[i]=prevy;
   prevx=prev2x;
   prevy=prev2y;
  }


switch(DIR)
 {

   case LEFT:x--;break;
   case RIGHT:x++;break;
   case UP:y--;break;
   case DOWN:y++;break;
   default :break;

}
if(x>=width)
    x=1;
if(x<=0)
    x=width-1;
if(y>=height)
    y=1;
if(y<=0)
    y=height-1;
if(x==fx&&y==fy)
{ nTail++;
    score+=10;
    count1++;
    if(count1==8){
           sx=rand()%34+1;
           sy=rand()%29+1;


    }

 fx=rand()%34+1;
fy=rand()%29+1;


}

if(x==sx&&y==sy)
    {
         score+=50;
         count1=0;

    }

for(int k=0;k<nTail;k++)
{
    if(tailX[k]==x&&tailY[k]==y)
        gamestatus=true;

}


//gamestatus=true;


 }



void draw()
 {

int i ,j ;


gotoxy(0,0);

for(i=1;i<height;i++)
{
     printf("\n");
    for(j=1;j<width;j++)
    {
   if(j==1)
     printf("#");
     if(x==j&&i==y)
           {
           printf("O");

           }

     else if(fx==j&&fy==i)
         printf("X");

   else if(sx==j&&sy==i&&count1==8)
         {printf("D");

          }
         else
            {   bool print=false;

                for(int k=0;k<nTail;k++)
                {

            if(tailX[k]==j&&tailY[k]==i)
                     {printf("o");
                     print=true;}

                }
                  if(!print)
                printf(" ");



            }


    }
//    gotoxy(1,i+1);






 }
printf("\n\nSCORE=%d",score);

 }




int main()
{


//setbkcolor(15);
//circle(100,100,50);
setup();
design();
while(!gamestatus)
{
//system ( "color 02" );
//system ( "color 01" );
//system ( "color 03" );


input();
Sleep(10);
 logic();
draw();
//system ( "color 04" );

//printf("sgdggggggggg");

}




return  0 ;
}
