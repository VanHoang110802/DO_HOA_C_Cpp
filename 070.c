#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    initwindow(700,500,"Demo Test Phao Hoa",200,100);

    while(true)
    {
        // tạo viên pháo ở đây:

        int vtx = rand () % 500 + 100;
        for(int a=0;a<= 260;a+=5){
            setlinestyle(1,2,5);
            line(vtx,452-a,vtx,450-a);
            delay(5);
            // xóa hết viên pháo đi:
            cleardevice();
    }
     // xóa rồi thì tạo hiệu ứng nổ ở đây:
    delay(10);
    setlinestyle(1,2,1);

    for(int x =0;x<= 100;x+=10){
        setcolor(13);
        arc(vtx + 50,200,170-x,180-x,20);
        arc(vtx + 60,160,170-x,180-x,30);
        arc(vtx + 70,150,170-x,180-x,40);

        setcolor(14);
        arc(vtx + 90,200,170-x,180-x,25);
        arc(vtx + 100,200,170-x,180-x,35);
        arc(vtx + 110,200,170-x,180-x,50);

        setcolor(15);
        arc(vtx - 20,200,0+x,10+x,25);
        arc(vtx - 30,200,0+x,10+x,35);
        arc(vtx - 40,200,0+x,10+x,45);
        arc(vtx - 50,200,0+x,10+x,50);
        arc(vtx - 60,200,0+x,10+x,60);

        setcolor(13);
        arc(vtx + 50,200,170-x,180-x,60);
        arc(vtx + 60,160,170-x,180-x,70);
        arc(vtx + 70,150,170-x,180-x,100);
        setcolor(14);
        arc(vtx + 90,200,170-x,180-x,85);
        arc(vtx + 100,200,170-x,180-x,95);
        arc(vtx + 110,200,170-x,180-x,110);

        setcolor(14);
        arc(vtx - 90,200,0+x,10+x,125);
        arc(vtx - 100,200,0+x,10+x,135);
        arc(vtx - 110,200,0+x,10+x,115);
        arc(vtx - 120,200,0+x,10+x,130);
        arc(vtx - 130,200,0+x,10+x,120);

        delay(80);
        cleardevice();
    }
  }

  getch();
  closegraph();
  return 0;
}


-----------------------------------------------------------------------------------------------

/*
x,y : toa do cua vien phao hoa
vx,vy: toc do theo cac huong
v: toc do vien phao
a: goc ban phao hoa
c: mau vien phao hoa
k:loại vien phao hoa(1 phao hoa no, 2 phao hoa con)
b: vien phao hoa i co ton tai hay khong?

int x[100],y[100],vx[100],vy[100],a[100];
int c[100],k[100];
bool b[];
int nf,ns,maxx = getmaxx(),maxy = getmaxy();
float g;

procedure create(j,x1,y1,a1,c1: long);
var i,s,e: long;
begin
if j= 1 then
s= ;
e= nf;
end;

if j= 2 then
    begin
    s= nf+ 1;
    e= nf + ns;
    end;
for i= s to e do
    begin
    if not b[i] then break;
    if i = e then exit;
    end;

    k[i] = j;
    b[i] = true;
    v[i] = c1;
    x[i] = x1;
    y[i] = y1;
    vx[i] = v[i] * cos(a1*3.14/180);
    vy[i] = v[i] * sin(a1*3.14/180);
    c[i] = c1;
end;

procedure main;
var i,j: long;
begin
g 9.8;
nf = 10;
ns = 5000;
repeat
if chance(1) then create(1, rand%(500),rand%() 100 + 80,rand()%100 + 50,rand()%14);
    for i = 1 to nf+ns do if b[i] then
    begin
    if i <= nf then g=7 else g = 10
    putpoint(trunc(x[i]), truc(maxy - y[i]),0,i);
    vy[i] = vy[i] - g * 0.2;
    vx[i] = vx[i];
    x[i] = x[i] + vx[i] * 0.2;
    y[i] = y[i] + vy[i] * 0.2;
    if y[i] < 0 then b[i] = false;
    if k[i] = 1 and vy[i] < 0 then
    begin
     putpoint(trunc(x[i]), truc(maxy - y[i]),0,i);
     b[i] = false;
     for j = 1 to 500 do
     create(2,ran(trunc(x[i] - 5),trunc(x[i] + 5)),...)
     end;
     else  putpoint(trunc(x[i]), truc(maxy - y[i]),c[i],i);
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

#define round(a) int(a+0.5)
/* he so doi tu do sang radian */
#define RADS 0.017453293

void InitGraph()
{
    initwindow(700,500,"DEMO PHAO HOA",300,100);
}

void toquet2(int xt,int yt,int r,int colorr) // dung cho hinh tron
{
    int xmin=xt-r, ymin=yt-r, xmax=xt+r, ymax=yt+r, i, j;
    for (i=xmin; i<=xmax; i++){
        for (j=ymin; j<=ymax; j++)
        {
            if (((i-xt)*(i-xt)+(j-yt)*(j-yt))<=r*r)
            {
                putpixel(i,j,colorr);
            }
        }
    }
}

void put30pixel(int a,int b,int xt, int yt,int colorr)
{   int i;
    float x[30],y[30],grad=(3.14)/180;
    x[0]=a;
    y[0]=b;
    for(i=1; i<30; i++)
    {
        x[i]=yt*sin(i*grad)+xt*(1-cos(i*grad));
        y[i]=yt*(1-cos(i*grad))-xt*sin(i*grad);
    }
    for (i=0; i<30; i++) {
        putpixel(round(x[i]),round(y[i]),colorr);
    }
}

void put8ht(int x, int y, int xt, int yt, int colorr)
{
    toquet2(x+xt,y+yt,1,colorr);
    toquet2(y+xt,x+yt,1,colorr);
    toquet2(x+xt,-y+yt,1,colorr);
    toquet2(y+xt,-x+yt,1,colorr);
    toquet2(-x+xt,y+yt,1,colorr);
    toquet2(-y+xt,x+yt,1,colorr);
    toquet2(-x+xt,-y+yt,1,colorr);
    toquet2(-y+xt,-x+yt,1,colorr);
}

void hinhtron2(int xt, int yt, int r,int colorr) //(xt,yt) toa do tam
{
    int x=0,y=r,p=3-r;
    put8ht(x,y,xt,yt,colorr);
    while (x<=y)
    {
        if (p<0) {
            p+=4*x+6;
        }
        else
        {
           p+=4*(x-y),y--;
        }
        x++;
        if (x%8==0) {
            put8ht(x,y,xt,yt,colorr);
        }
    }
}

void phaono(int xt,int yt)
{
    int i,j;
    for(i=yt;i>=yt-80;i-=10){
        put30pixel(xt,i,xt,yt,14);
        delay(20);
        toquet2(xt,yt,90,0);
        for (i=0; i<2; i++){
            int k=15;
            if (i%2==0){
                for (j=0;j<10;j++){
                    hinhtron2(xt,yt,j*8,k);
                }
            }
            else{
                for (j=0;j<10;j++) {
                    hinhtron2(xt,yt,j*8,0);
                }
            }
            delay(20);
        }
    }
}

void phaohoa()
{
    int i,j,xt,yt;
    xt=rand()%409+109;
    yt=rand()%25+110;
    for(i=340; i>=yt+2; i-=5)
    {
        toquet2(xt,i,4,15);
        delay(10);
        toquet2(xt,i,4,0);
    }
    phaono(xt,yt);
}

void banphaohoa()
{
    while(true)
    {
        phaohoa();
    }
}

int main()
{
    InitGraph();
    banphaohoa();
    getch();
    closegraph();
    return 0;
}

----------------------------------------------------------------------------

/*
x,y : toa do cua vien phao hoa
vx,vy: toc do theo cac huong
v: toc do vien phao
a: goc ban phao hoa
c: mau vien phao hoa
k:loại vien phao hoa(1 phao hoa no, 2 phao hoa con)
b: vien phao hoa i co ton tai hay khong?

int x[100],y[100],vx[100],vy[100],a[100];
int c[100],k[100];
bool b[];
int nf,ns,maxx = getmaxx(),maxy = getmaxy();
float g;

procedure create(j,x1,y1,a1,c1: long);
var i,s,e: long;
begin
if j= 1 then
s= ;
e= nf;
end;

if j= 2 then
    begin
    s= nf+ 1;
    e= nf + ns;
    end;
for i= s to e do
    begin
    if not b[i] then break;
    if i = e then exit;
    end;

    k[i] = j;
    b[i] = true;
    v[i] = c1;
    x[i] = x1;
    y[i] = y1;
    vx[i] = v[i] * cos(a1*3.14/180);
    vy[i] = v[i] * sin(a1*3.14/180);
    c[i] = c1;
end;

procedure main;
var i,j: long;
begin
g 9.8;
nf = 10;
ns = 5000;
repeat
if chance(1) then create(1, rand%(500),rand%() 100 + 80,rand()%100 + 50,rand()%14);
    for i = 1 to nf+ns do if b[i] then
    begin
    if i <= nf then g=7 else g = 10
    putpoint(trunc(x[i]), truc(maxy - y[i]),0,i);
    vy[i] = vy[i] - g * 0.2;
    vx[i] = vx[i];
    x[i] = x[i] + vx[i] * 0.2;
    y[i] = y[i] + vy[i] * 0.2;
    if y[i] < 0 then b[i] = false;
    if k[i] = 1 and vy[i] < 0 then
    begin
     putpoint(trunc(x[i]), truc(maxy - y[i]),0,i);
     b[i] = false;
     for j = 1 to 500 do
     create(2,ran(trunc(x[i] - 5),trunc(x[i] + 5)),...)
     end;
     else  putpoint(trunc(x[i]), truc(maxy - y[i]),c[i],i);
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include<time.h>

#define round(a) int(a+0.5)
/* he so doi tu do sang radian */
#define RADS 0.017453293

void InitGraph()
{
    initwindow(700,500,"DEMO PHAO HOA",300,100);
}

void dda(int x1, int y1, int x2, int y2, int c)
{
    float x=x1,y=y1,m;
    if (x1!=x2)
    {
        m=float(y2-y1)/(x2-x1);
        putpixel(x,round(y),c);
        if ( m>-1 && m<1)
        {
            if (x1<x2)
            {
                for (x=x1; x<=x2; x++)
                {
                    y+=m,putpixel(x,round(y),c);
                }
            }
            if (x1>x2)
            {
                for (x=x1; x>=x2; x--)
                {
                    y-=m,putpixel(x,round(y),c);
                }
            }
        }
        if (m<=-1 || m>=1)
        {
            if (y1<y2)
            {
                for (y=y1; y<=y2; y++)
                {
                     x+=1/m,putpixel(round(x),y,c);
                }

            }
            if (y1>y2)
            {
                for (y=y1; y>=y2; y--)
                {
                    x-=1/m,putpixel(round(x),y,c);
                }
            }
        }
    }
    else
    {
        for (int i=y1; i<=y2; i++)
        {
            putpixel(x1,i,c);
        }
    }

}

void toquet2(int xt,int yt,int r,int colorr) // dung cho hinh tron
{
    int xmin=xt-r, ymin=yt-r, xmax=xt+r, ymax=yt+r, i, j;
    for (i=xmin; i<=xmax; i++)
    {
        for (j=ymin; j<=ymax; j++)
        {
            if (((i-xt)*(i-xt)+(j-yt)*(j-yt))<=r*r)
            {
                putpixel(i,j,colorr);
            }
        }
    }
}

void put30pixel(int a,int b,int xt, int yt,int colorr)
{
    int i;
    float x[30],y[30],grad=(3.14)/180;
    x[0]=a;
    y[0]=b;
    for(i=1; i<30; i++)
    {
        x[i]=yt*sin(i*grad)+xt*(1-cos(i*grad));
        y[i]=yt*(1-cos(i*grad))-xt*sin(i*grad);
    }
    for (i=0; i<30; i++)
    {

        putpixel(round(x[i]),round(y[i]),colorr);
    }
}

void put8ht(int x, int y, int xt, int yt, int colorr)
{
    toquet2(x+xt,y+yt,1,colorr);
    toquet2(y+xt,x+yt,1,colorr);
    toquet2(x+xt,-y+yt,1,colorr);
    toquet2(y+xt,-x+yt,1,colorr);
    toquet2(-x+xt,y+yt,1,colorr);
    toquet2(-y+xt,x+yt,1,colorr);
    toquet2(-x+xt,-y+yt,1,colorr);
    toquet2(-y+xt,-x+yt,1,colorr);
}

void hinhtron2(int xt, int yt, int r,int colorr) //(xt,yt) toa do tam
{
    int x=0,y=r,p=3-r;
    put8ht(x,y,xt,yt,colorr);
    while (x<=y)
    {
        if (p<0)
        {
            p+=4*x+6;
        }
        else
        {
           p+=4*(x-y),y--;
        }
        x++;
        if (x%8==0) {

            put8ht(x,y,xt,yt,colorr);
        }

    }
}

void tiaphao(int xt, int yt,int c)
{
    toquet2(xt,yt,2,c);
    dda(xt,yt,xt,yt+10,c);
    dda(xt,yt+10,xt-2,yt,c);
    dda(xt,yt+10,xt+2,yt,c);
    for(int i=0;i<5;i++)
    {
        putpixel(xt,yt+10+2*i,c);
    }
}

void phaono(int xt,int yt)
{
    int i,j;
    for(i=yt;i>=yt-80;i-=10)
    {
        put30pixel(xt,i,xt,yt,14);
        //delay(2);
    }
    toquet2(xt,yt,85,0);
    for (i=0; i<10; i++)
    {
        int k=rand()%14+1;
        if (i%2==0)
        {
            for (j=0;j<10;j++)
            {
               // delay(1);
                hinhtron2(xt,yt,j*8,k);
            }
        }
        else
        {
            cleardevice();
        }
        delay(2);
    }
}

void phaohoa()
{
    int i,j,xt,yt,chon;
    chon=rand()%5+1;
    switch(chon)
    {
        case 1:
        {
            xt=rand()%108+1;
            yt=rand()%110+130;
            for(i=289; i>=yt+2; i--)
            {
                tiaphao(xt,i,14);
                tiaphao(xt,i,0);
            }
            phaono(xt,yt);
            break;
        }
        case 2:
        {
            xt=rand()%107+109;
            yt=rand()%25+110;
            for(i=340; i>=yt+2; i--)
            {   tiaphao(xt,i,14);
                tiaphao(xt,i,0);
            }
            phaono(xt,yt);
            break;
        }
        case 3:
        {
            xt=rand()%107+227;
            yt=rand()%25+110;
            for(i=255; i>=yt+2; i--)
            {
                tiaphao(xt,i,14);
                tiaphao(xt,i,0);
            }
            phaono(xt,yt);
            break;
        }
        case 4:
        {
            xt=rand()%128+401;
            yt=rand()%25+110;
            for(i=240; i>=yt+2; i--)
            {
                tiaphao(xt,i,14);
                tiaphao(xt,i,0);
            }
            phaono(xt,yt);
            break;
        }
        case 5:
        {
            xt=rand()%108+530;
            yt=rand()%110+110;
            for(i=289; i>=yt+2; i--)
            {
                tiaphao(xt,i,14);
                tiaphao(xt,i,0);
            }
            phaono(xt,yt);
            break;
        }
    }
}

void banphaohoa()
{
    while (1) phaohoa();
}

int main()
{
    srand(time(0));
    InitGraph();
    banphaohoa();
    getch();
    closegraph();
    return 0;
}
