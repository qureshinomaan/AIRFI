//this is the #include file
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int t1;
char sd[7];
int startup()
{
    rectangle(0,0,getmaxx(),getmaxy());
    char a[15];
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
    int i=0,k;
    while(1)
    {
       outtextxy(130,200,"NAME : ");
       a[i]=getch();
       if(a[i]==13)
       {
         a[i]='\0';
         strcpy(sd,a);
         cleardevice();
          break;
  }
       cleardevice();
       outtextxy(330,200,a);
       i++;
       if(i==7)
       {
         cleardevice();
          break;
        }
  }
}
void highscore()
{
  cleardevice();
  char nam[5]="NAME";
  char hsm[6]="SCORE";
  fstream fin,finm,f;
  f.open("cnt.dat",ios::in);
  f>>t1;
  f.close();
  finm.open("hsn.dat",ios::in);
  fin.open("scr.dat",ios::in);
  int scre[30],i;
  char ch;
  char nm[30][15];
  for(i=0;i<t1;i++)
  {
    fin>>scre[i];
    fin.get(ch);
    finm.getline(nm[i],80);
  }
  for(i=0;i<t1;i++)
  {
    for(int j=i+1;j<t1;j++)
    {
      if(scre[i]<scre[j])
      {
	int tmp=scre[i];
	scre[i]=scre[j];
	scre[j]=tmp;
	char temp[15];
	strcpy(temp,nm[i]);
	strcpy(nm[i],nm[j]);
        strcpy(nm[j],temp);
      }
    }
  }
  rectangle(20,40,600,450);
  outtextxy(120,50,nam);
  outtextxy(370,50,hsm);
  for(i=0;i<t1&&i<5;i++)
  {
    char tmp[30];
    itoa(scre[i],tmp,10);
   outtextxy(120,130+i*70,nm[i]);
    outtextxy(400,130+i*70,tmp);
  }
  getch();
  cleardevice();
}

void ac(int x,int y)
{
  setfillstyle(SOLID_FILL,x);
  //axis of symmetry
  line(x+10,y,x-20,y);
  //front head
  setcolor(8);
  line(x+20,y,x+10,y-10);
  line(x+20,y,x+10,y+10);
  line(x+10,y-10,x+10,y+10);
  //wing
  setcolor(8);
  line(x-10,y-50,x,y);
  line(x-10,y-50,x+4,y);
  line(x-10,y-50,x-4,y);
  line(x-10,y-50,x+8,y);
  line(x-10,y-50,x+10,y);
  line(x-10,y+50,x,y);
  line(x-10,y+50,x+4,y);
  line(x-10,y+50,x-4,y);
  line(x-10,y+50,x+8,y);
  line(x-10,y+50,x-9,y);
  line(x-10,y-50,x-10,y);
  line(x-10,y-50,x-8,y);
  line(x+10,y-10,x-10,y-50);
  line(x+10,y+10,x-10,y+50);
  line(x-10,y-50,x-10,y+50);
  setcolor(14);
  //tail
  line(x-10,y,x-20,y-10);
  line(x-10,y,x-20,y+10);
  line(x-10,y,x-20,y-8);
  line(x-10,y,x-20,y-6);
  line(x-10,y,x-20,y-4);
  line(x-10,y,x-20,y-2);
  line(x-10,y,x-20,y+2);
  line(x-10,y,x-20,y+4);
  line(x-10,y,x-20,y+6);
  line(x-10,y,x-20,y+8);
}


void obs1(int x,int y)
{
  circle(x,y,20);
  circle(x,y,10);
  circle(x,y,8);
  setcolor(rand());
  circle(x-15,y,2);
  circle(x+15,y,2);
  circle(x,y-15,2);
  circle(x,y+15,2);
  circle(x+10,y+10,2);
  circle(x-10,y+10,2);
  circle(x+10,y-10,2);
  circle(x-10,y-10,2);
}

void bullet(int x,int y)
{
  rand();
  setcolor(rand());
  circle(x,y,1);
}

//loading...
void ld()
{
  cleardevice();
  int i,l=200,t=260,r=200,b=280;
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
  char l1[30]="LOADING...";
  outtextxy(200,200,l1);
  for(i=0;i<=250;i++)
  {
    rectangle(l,t,r+i,b);
    delay(10);
  }

}

void mainscreen()
{
  rectangle(0,0,getmaxx(),getmaxy());
  char s[10]= "AIR FIGHT";
  char p[10]="PLAY";
  char i[20]="INSTRUCTIONS";
  char a[10]="HIGHSCORE";
  char e[10]="EXIT";
  int p2=0;
  int x=getmaxx()/2;
  int y=getmaxy()/2;
  settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
  outtextxy(x-150,y-200,s);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(x-60,y-70,p);
  outtextxy(x-120,y-20,i);
  outtextxy(x-100,y+30,a);
  outtextxy(x-55,y+80,e);
  //choice
  float l=x-130,t=y-72,r=x+105,b=y-32,t1=t;
  rectangle(l,t,r,b);

  for(int z=0;p2!=1;z++)
  {

    switch(getch())
    {
      //rectangle for going down
      case '2':
      {
        if(t!=t1+150)
        {
          cleardevice();
          t+=50;
          b+=50;
          rectangle(l,t,r,b);
          rectangle(0,0,getmaxx(),getmaxy());
          settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
          outtextxy(x-150,y-200,s);
          settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
          outtextxy(x-60,y-70,p);
          outtextxy(x-120,y-20,i);
          outtextxy(x-100,y+30,a);
          outtextxy(x-55,y+80,e);
        }


        break;
      }



      //rectangle for going up

      case '8':
      {
        if(t!=t1)
        {
          cleardevice();
          t-=50;
          b-=50;
          rectangle(l,t,r,b);
          rectangle(0,0,getmaxx(),getmaxy());
          settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
          outtextxy(x-150,y-200,s);
          settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
          outtextxy(x-60,y-70,p);
          outtextxy(x-120,y-20,i);
          outtextxy(x-100,y+30,a);
          outtextxy(x-55,y+80,e);
        }
        break;
      }
      //case for selecting option
      case '5':
      {
        if(t==t1)
        p2=1;
        if(t==t1+100)
        {
          highscore();
          p2=1;
        }
        if(t==t1+150)
        exit(0);

        break;
      }


    }
  }
}

void mainscreen(char a1)
{
  rectangle(0,0,getmaxx(),getmaxy());
  char s[10]= "AIR FIGHT";
  char p[10]="RESUME";
  char i[20]="INSTRUCTIONS";
  char a[10]="HIGHSCORE";
  char e[10]="EXIT";
  int p2=0;
  int x=getmaxx()/2;
  int y=getmaxy()/2;
  settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
  outtextxy(x-150,y-200,s);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(x-80,y-70,p);
  outtextxy(x-120,y-20,i);
  outtextxy(x-100,y+30,a);
  outtextxy(x-55,y+80,e);
  //choice
  float l=x-130,t=y-72,r=x+105,b=y-32,t1=t;
  rectangle(l,t,r,b);

  for(int z=0;p2!=1;z++)
  {

    switch(getch())
    {
      //rectangle for going down
      case '2':
      {
        if(t!=t1+150)
        {
          cleardevice();
          t+=50;
          b+=50;
          rectangle(l,t,r,b);
          rectangle(0,0,getmaxx(),getmaxy());
          settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
          outtextxy(x-150,y-200,s);
          settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
          outtextxy(x-80,y-70,p);
          outtextxy(x-120,y-20,i);
          outtextxy(x-100,y+30,a);
          outtextxy(x-55,y+80,e);
        }


        break;
      }



      //rectangle for going up

      case '8':
      {
        if(t!=t1)
        {
          cleardevice();
          t-=50;
          b-=50;
          rectangle(l,t,r,b);
          rectangle(0,0,getmaxx(),getmaxy());
          settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
          outtextxy(x-150,y-200,s);
          settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
          outtextxy(x-80,y-70,p);
          outtextxy(x-120,y-20,i);
          outtextxy(x-100,y+30,a);
          outtextxy(x-55,y+80,e);
        }
        break;
      }
      //case for selecting option
      case '5':
      {
        if(t==t1)
        p2=1;

        if(t==t1+100)
        {
           highscore();
           p2=1;
}
        if(t==t1+150)
        exit(0);

        break;
      }


    }
  }
}


void obs2(int x,int y)
{
  circle(x,y,10);
  circle(x,y,5);
  circle(x,y,4);
  circle(x-15,y,1);
  circle(x+15,y,1);
  circle(x,y-15,1);
  circle(x,y+15,1);
  circle(x+10,y+10,1);
  circle(x-10,y+10,1);
  circle(x+10,y-10,1);
  circle(x-10,y-10,1);
}
//level clear
void lcl(char *scrd,int l)
{
  int i=0,a=2;
  char lv[10];
  int lvl=300+100*l;
  itoa(lvl,lv,10);
  while(!kbhit())
  {
    rectangle(0,0,getmaxx(),getmaxy());
    char s[100]= "LEVEL CLEARED";
    char t[100]="LEVEL BONUS :";
    char p[100]="TOTAL SCORE :";
    char p1[30]="PRESS ANY KEY";
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
    outtextxy(40,150,s);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(160,250,t);
    outtextxy(485,250,lv);
    outtextxy(160,300,p);
    outtextxy(485,300,scrd);
    if(i%2==0)
    outtextxy(145,350,p1);
    delay(250);
    i++;
    cleardevice();
  }
  for(i=0;i<70;i++)
  {
    cleardevice();
    obs2(30,getmaxy()/2 -200);
    obs2(30,getmaxy()/2 +200);
    obs1(150,getmaxy()/2 -200);
    obs1(150,getmaxy()/2 +200);
    obs2(270,getmaxy()/2 -200);
    obs2(270,getmaxy()/2 +200);
    obs1(390,getmaxy()/2 +200);
    obs1(390,getmaxy()/2 -200);
    obs2(510,getmaxy()/2 -200);
    obs2(510,getmaxy()/2 +200);
    obs1(630,getmaxy()/2 -200);
    obs1(630,getmaxy()/2 +200);
    ac(10*i,getmaxy()/2);
    delay(10);
  }

}
void gmov(char *scrd,int sc)
{
  int i=0;
  char p[100]="TOTAL SCORE :";
  char p1[30]="PRESS ANY KEY";
  char t[100]="GAME OVER";
  fstream fillout,f,t3;
  t3.open("hsn.dat",ios::app);
  f.open("cnt.dat",ios::in);
  t3<<sd<<'\n';
  t3.close();
  f>>t1;
  f.close();
  t1++;
  f.open("cnt.dat",ios::out);
  f<<t1;
  f.close();
  fillout.open("scr.dat",ios::app);
  fillout<<sc<<'\n';
  fillout.close();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  outtextxy(130,250,p);
  outtextxy(435,250,scrd);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
  outtextxy(105,130,t);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  outtextxy(145,360,p1);
  getch();
  exit(0);

}
//453 lines of include file
//thanks
