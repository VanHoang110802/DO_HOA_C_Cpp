/* Liang-Barsky */
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#define ROUND(a) ((double)(a+0.5)
#define TRUE 1
#define FALSE 0

int cliptest(double p, double q, double *u1, double *u2)
{
  double r;
  int retVal = TRUE;

  if (p < 0.0)
  {
    r = q / p;
    if (r > *u2)
      retVal = FALSE;
    else
      if (r > *u1)
        *u1 = r;
  }
  else
    if ( p > 0.0)
    {
      r = q / p;
      if (r < *u1)
        retVal = FALSE;
      else
        if (r < *u2)
          *u2 = r;
    }
    else
    {
      if (q < 0.0)
        retVal = FALSE;
    }
  return (retVal);
}

void clipline(double x1, double y1, double x2, double y2,
       double xmin, double ymin, double xmax, double ymax)
{
  double u1 = 0.0, u2 = 1.0, dx, dy;
  double oldx1, oldy1, oldx2, oldy2;
  oldx1 = x1;
  oldy1 = y1;
  oldx2 = x2;
  oldy2 = y2;
  dx = x2 - x1;
  if (cliptest(-dx, x1 - xmin, &u1, &u2))
    if (cliptest(dx, xmax-x1, &u1, &u2))
    {
      dy = y2 - y1;
      if (cliptest(-dy, y1 - ymin, &u1, &u2))
        if (cliptest(dy, ymax - y1, &u1, &u2))
        {
          if (u2 < 1.0)
          {
            x2 = x1 + u2 * dx;
            y2 = y1 + u2 * dy;
          }
          if (u1 > 0.0)
          {
            x1 += u1 * dx;
            y1 += u1 * dy;
          }
          setcolor(WHITE);
          line(oldx1, oldy1, x1, y1);
          line(x2, y2, oldx2, oldy2);
          setcolor(YELLOW);
          line(x1, y1, x2, y2);
        }
    }
}

int main()
{
  int gr_drive = DETECT, gr_mode;
  char c;
  double x1, y1, x2, y2;

  initgraph(&gr_drive, &gr_mode, "");
  rectangle(100,50, getmaxx()-100, getmaxy()-50);
  rand();
  outtextxy(100, getmaxy()-10, "Nhan phim bat ky de sinh duong khac; ESC de thoat");
  do {
    x1 = rand() % getmaxx() / 2;
    y1 = rand() % getmaxy();
    x2 = getmaxx()/2 + rand() % getmaxx() / 2;
    y2 = rand() % getmaxy();
    clipline(x1, y1, x2, y2, 100, 50, getmaxx()-100, getmaxy()-50);
    c = getch();
  } while (c != 27);

  closegraph();
}
