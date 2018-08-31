#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<cmath>
void digits(int k)
{
    setcolor(15);
    setlinestyle(SOLID_LINE, 1, 1);
    bgiout << "12";
    outstreamxy(300, 5);
    bgiout << "6";
    outstreamxy(300, 435);
    bgiout << "3";
    outstreamxy(510, 230);
    bgiout << "9";
    outstreamxy(80, 230);
    bgiout << "1";
    outstreamxy(400, 40);
    bgiout << "2";
    outstreamxy(480,110);
    bgiout << "4";
    outstreamxy(480, 330);
    bgiout << "5";
    outstreamxy(400, 410);
    bgiout << "7";
    outstreamxy(185, 410);
    bgiout << "11";
    outstreamxy(180, 40);
    bgiout << "8";
    outstreamxy(110, 330);
    bgiout << "10";
    outstreamxy(110, 110);
    //bgiout << "0";
    //outstreamxy(300,230);
    setcolor(3);
   circle(300,230,5);
   setcolor((k%8)+1);
   circle(300,110,20);
   setcolor((k%8)+3);
   circle(300,350,20);
   setcolor((k%8)+2);
   circle(185,230,20);
   setcolor((k%8)+4);
   circle(415,230,20);
}
void hour(int x,int y,int h,int m)
{
    setcolor(1);
    setlinestyle(SOLID_LINE, 1, 5);
    h=h%12;
    int angle;
    double ang,val=130;
    angle=h*30;
    m=m/2;
    angle+=m;
    angle=angle%359;
    ang=angle;
    ang=(ang*3.14159)/180.0;
    line(x,y,x+val*sin(ang),y-val*cos(ang));
}
void minute(int x,int y,int m)
{
    setcolor(2);
    setlinestyle(SOLID_LINE, 1, 3);
    int angle;
    double ang,val=170;
    angle=m*6;
    angle=angle%359;
    ang=angle;
    ang=(ang*3.14159)/180.0;
    line(x,y,x+val*sin(ang),y-val*cos(ang));
}
void second(int x,int y,int s)
{
    setcolor(4);
    setlinestyle(SOLID_LINE, 1, 1);
    int angle;
    double ang,val=210;
    angle=s*6;
    angle=angle%359;
    ang=angle;
    ang=(ang*3.14159)/180.0;
    line(x,y,x+val*sin(ang),y-val*cos(ang));
}
using namespace std;
int main()
{
   int m=0,gd = DETECT,gm,circle_x,circle_y,radius,sx,sy;
   circle_x=300;
   circle_y=230;
   radius=200;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   //initwindow(1000, 1000);
   //setbkcolor(11);
   while(!kbhit())
   {
       setcolor((m%3)+1);
   circle(circle_x,circle_y,radius+35);
   setcolor(((m+1)%3)+1);
   circle(circle_x,circle_y,radius+30);
   setcolor(((m+2)%3)+1);
   circle(circle_x,circle_y,radius+40);
   digits(m++);
   time_t now=time(0);
   tm *ltm=localtime(&now);
   hour(circle_x,circle_y,ltm->tm_hour,ltm->tm_min);
   minute(circle_x,circle_y,ltm->tm_min);
   second(circle_x,circle_y,ltm->tm_sec);
   delay(1000);
   cleardevice();
   }
   getch();
   closegraph();
   return 0;
}
