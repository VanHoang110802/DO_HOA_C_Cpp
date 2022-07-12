/*- Chuong trinh ve duong ham so y = sin(x) */
#include <conio.h>
#include <graphics.h>
#include <math.h>

/* he so doi tu do sang radian */
#define RADS 0.017453293
#define K 150

void ham1()
{
   double xmax, yc, x = 0.0, y;

   xmax = getmaxx();
   yc = getmaxy() / 2;
   while (x<xmax)
   {
      y = K * sin(x * RADS);
      putpixel(x, yc + y, YELLOW);
      x += 0.1;
   }
}

int main()
{
  int gr_drive = DETECT, gr_mode;

  initgraph(&gr_drive, &gr_mode, "");
  ham1();
  getch();
  closegraph();
}
