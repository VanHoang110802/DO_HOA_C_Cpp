/* Tao ra bien dang nui mot cach ngau nhien */
#include  <conio.h>
#include  <stdlib.h>
#include  <time.h>
#include <graphics.h>

void lineseg(int hpos1,int hpos2,int vpos1,int vpos2, int depth, int range);

unsigned char *screen;

int main(int argc,char *argv[])
{
  int depth, range, key = 0;
  int gr_drive = DETECT, gr_mode;

  if (argc<2)
    depth = 5;
  else
    depth = atoi(argv[1]);

  if (argc<3)
    range = 250;
  else
    range = atoi(argv[2]);

  rand();
  initgraph(&gr_drive, &gr_mode, "");

  while( key != 27)
  {
    lineseg(0, getmaxx(), getmaxy() / 2, getmaxy()/2, depth, range);

    while(! kbhit());
	  key = getch();
	  if( key >= '1' && key <= '9')
     		depth = (int)(key - '0');
    cleardevice();
  }
  closegraph();
}

void lineseg(int hpos1,int hpos2,int vpos1,int vpos2, int depth,int range)
{
  int midvpos;

  if (depth<=0)
     line(hpos1,vpos1,hpos2,vpos2);
  else {
    midvpos = (vpos1+vpos2)/2+rand()%range -range/2;
    lineseg(hpos1,(hpos1+hpos2)/2,vpos1,midvpos,depth-1,
             range/2);
    lineseg((hpos1+hpos2)/2,hpos2,midvpos,vpos2,depth-1,
             range/2);
  }
}
