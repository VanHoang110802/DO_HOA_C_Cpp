/*- pie */
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

/* he so doi tu do sang radian */
#define RADS 0.017453293
#define RADIUS 100

static int fill [13] = {0};
static int color[16] = {0};

int main()
{
  int gr_drive = DETECT, gr_mode;
  int mang[5], ifill, icolor;
  int angle = 0, i, sum = 0, xc, yc, congdon = 0;

  initgraph(&gr_drive, &gr_mode, "");
  xc = getmaxx() / 2;
  yc = getmaxy() / 2;
  rand();

  for (i=0; i<5; i++)
  {
    mang[i] = rand()%81 + 20;
    sum += mang[i];
  }
  for (i=0; i<5; i++)
  {
    do {
      ifill = rand()% 11+1;
      icolor = rand()%15 + 1;
    } while (fill[ifill] == 1 || color[icolor] == 1);
    setfillstyle(ifill, icolor);
    fill[ifill] = 1;
    color[icolor] = 1;
    congdon += mang[i];
    pieslice(xc, yc, 360 * angle / sum, congdon * 360 / sum, RADIUS);
    angle = congdon;
  }

  getch();
  closegraph();
}
