//this is the main project
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<graphics.h>
#include<math.h>
#include<airfi.h>
#include<stdlib.h>
#include<string.h>

int afo[10]={1,1,1,1,1,1,1,1,1,1};
int life=3;
char scrd[20];

void main()
{
  int spaceshipspeed=10;
  int gd=DETECT,gm=0;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  float obx=520,oby=300,obyt=oby,obx1=obx+20,oby1=oby-100;
  int l1=1;//variable for level
  float mvx=4,mvy=4,l=1;
  float bs=0,bx,by;
  int sc=0;
  int x=20,y=getmaxy()/2,r=20;
  startup();
  mainscreen();
  ld();
  obs1(obx,oby);
  ac(x,y);
  char level[10];

  for(int i=0;;i++)
  {
    while(!kbhit())
    {
      cleardevice();
      ac(x,y);
      itoa(sc,scrd,10);
      setcolor(15);
      rectangle(0,0,getmaxx(),getmaxy());
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
      outtextxy(590,0,scrd);
      itoa(l,level,10);
      outtextxy(250,0,"LEVEL : ");
      outtextxy(350,0,level);
      for(i=0;i<life;i++)
      {
        setfillstyle(1,4);
        setcolor(3);
        circle(15*(i)+10,7,5);
        floodfill(15*(i)+10,7,3);
      }
      //object 1
      if(afo[1]==1)
      {
        obs1(obx,oby);
        obx-=mvx;
        oby+=mvy;
      }
      //obstacle 2
      if(afo[2]==1)
      {
        obs2(obx1,oby1) ;
        obx1-=mvx;
        oby1-=mvy;
      }


      //moving obstacle
      if(oby>obyt+100)
      mvy=-mvy;

      if(oby<obyt-100)
      mvy=-mvy;

      //moving bullets
      if(bs==1)
      {
        bullet(bx,by);
        bx+=30;
      }

      //ending obstacle
      if((bx>obx-20)&&(bx<obx+20)&&(by>oby-20)&&(by<oby+20))
      {
        obx=obx+300;
        oby-=5;
        l1++;
        bx=0;
        sc+=10;
      }

      if((bx>obx1-20)&&(bx<obx1+20)&&(by>oby1-20)&&(by<oby1+20))
      {

        oby+=5;
        obx1=obx1+500;
        l1++;
        if(l1>=5)
        {
          mvx++;
        }
        bx=0;
        sc+=10;
      }

      //life ending!!!!
      int x1=90;
      if(obx<-20)
      {
        obx+=550;
        life--;
        x1-=30;
      }
      if(obx1<-20)
      {
        obx1+=500;
        life--;
        x1-=30;
      }

      if(life==0)
      {
        cleardevice();
        gmov(scrd,sc);
        cleardevice();
        getch();
        mainscreen();
        life=3;
        l1=0;
      }

      //level cleared
      if(l1==9)
      {
        cleardevice();
        l++;
	mvx+=1;
        spaceshipspeed+=1;
        sc=sc+300+100*l;
        l1=0;
        itoa(sc,scrd,10);
        lcl(scrd,l);
        getch();
      }

      delay(100);

    }


    switch(getch())
    {

      case'2' :
      {
        cleardevice();
        y+=spaceshipspeed;
        break;
      }

      case'8' :
      {
        y-=spaceshipspeed;

        break;
      }

      case' ':{
        bs=1;
        bx=x+10;
        by=y;
        break;
      }

      case 'p':
      {
        cleardevice();
        mainscreen('p');
        break;
      }

      case'e':
      {
        exit(0);
      }

    }
    //end of switch
  }
  //end of loop

  getch();


}
