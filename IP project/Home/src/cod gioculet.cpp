#include <iostream>
#include <graphics.h>
#include <cmath>
#include <vector>

using namespace std;

int a[7][7], ok;

/// backend :(

void matrix()
{
    a[1][1] = 2;
    a[1][5] = 2;
    a[3][3] = 2;
    a[5][1] = 2;
    a[5][5] = 2;
}

void clearmatrix()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            a[i][j] = 0;
}

int OKMatrix(int newx, int newy)
{
    newx -= 130;
    newx = newx / 160 + 1;
    newy -= 130;
    newy = newy / 160 + 1;
    return a[newx][newy];
}

int scanmatrix(int x)
{
    int k = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (a[i][j] == 2)
                k++;
    if (k == x)
        return 1;
    return 0;
}

/// frontend <3

void playfield()
{
    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 5);
    setfillstyle(SOLID_FILL, RGB(0, 172, 79));
    rectangle(50, 50, 850, 850);
    floodfill(150, 150, GREEN);
}

void circlesandsquares()
{
    ///vizuinele
    setlinestyle(SOLID_LINE, 0, 3);
    setcolor(RGB(69, 50, 20));
    setfillstyle(SOLID_FILL, RGB(69, 50, 20));
    circle(130, 130, 60);
    floodfill(130, 130, RGB(69, 50, 20));
    circle(770, 770, 60);
    floodfill(770, 770, RGB(69, 50, 20));
    circle(770, 130, 60);
    floodfill(770, 130, RGB(69, 50, 20));
    circle(130, 770, 60);
    floodfill(130, 770, RGB(69, 50, 20));
    circle(450, 450, 60);
    floodfill(450, 450, RGB(69, 50, 20));
    setcolor(WHITE);
    for (int x = 50; x <= 800; x += 320)
        for (int y = 50; y <= 800; y += 320)
            rectangle(x, y, x + 160, y + 160);
}

void circles()
{
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    for (int x = 130; x <= 800; x += 160)
        for (int y = 130; y <= 800; y += 160)
        {

            circle(x, y, 50);
            floodfill(x, y, GREEN);
        }
}

void rabbit(int x, int y)
{
    setcolor(RGB(159, 98, 5));
    setfillstyle(SOLID_FILL, RGB(159, 98, 5));
    circle(x, y, 30);
    floodfill(x, y, RGB(159, 98, 5));
    /// nose
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y, 8);
    floodfill(x, y, RGB(85, 27, 49));
    /// under-nose
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 6, y + 6, 6);
    floodfill(x + 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 6, y + 6, 6);
    floodfill(x - 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y + 4, 4);
    floodfill(x, y + 4, RGB(85, 27, 49));
    /// white stuff
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 6, y + 4, 5);
    floodfill(x - 6, y + 4, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 6, y + 4, 5);
    floodfill(x + 6, y + 4, WHITE);
    /// mustati
    setcolor(RGB(85, 27, 49));
    setlinestyle(SOLID_LINE, 2, 1);
    line(x - 6, y + 4, x - 25, y + 8);
    line(x + 6, y + 4, x + 25, y + 8);
    line(x - 6, y + 2, x - 25, y + 3);
    line(x + 6, y + 2, x + 25, y + 3);
    line(x - 6, y + 1, x - 25, y);
    line(x + 6, y + 1, x + 25, y);
    /// eyes
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 13, y - 13, 4);
    floodfill(x - 13, y - 13, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 13, y - 13, 4);
    floodfill(x + 13, y - 13, RGB(85, 27, 49));
    /// above-eye dots
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 12, y - 22, 3);
    floodfill(x - 12, y - 22, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 12, y - 22, 3);
    floodfill(x + 12, y - 22, WHITE);
}

void HIGHLrabbit(int x, int y)
{
    setcolor(RGB(159, 98, 5));
    setfillstyle(SOLID_FILL, RGB(159, 98, 5));
    circle(x, y, 30);
    floodfill(x, y, RGB(159, 98, 5));
    /// nose
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y, 8);
    floodfill(x, y, RGB(85, 27, 49));
    /// under-nose
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 6, y + 6, 6);
    floodfill(x + 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 6, y + 6, 6);
    floodfill(x - 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y + 4, 4);
    floodfill(x, y + 4, RGB(85, 27, 49));
    /// white stuff
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 6, y + 4, 5);
    floodfill(x - 6, y + 4, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 6, y + 4, 5);
    floodfill(x + 6, y + 4, WHITE);
    /// mustati
    setcolor(RGB(85, 27, 49));
    setlinestyle(SOLID_LINE, 2, 1);
    line(x - 6, y + 4, x - 25, y + 8);
    line(x + 6, y + 4, x + 25, y + 8);
    line(x - 6, y + 2, x - 25, y + 3);
    line(x + 6, y + 2, x + 25, y + 3);
    line(x - 6, y + 1, x - 25, y);
    line(x + 6, y + 1, x + 25, y);
    /// eyes
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 13, y - 13, 4);
    floodfill(x - 13, y - 13, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 13, y - 13, 4);
    floodfill(x + 13, y - 13, RGB(85, 27, 49));
    /// above-eye dots
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 12, y - 22, 3);
    floodfill(x - 12, y - 22, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 12, y - 22, 3);
    floodfill(x + 12, y - 22, WHITE);
    /// highlight
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);
    circle(x, y, 35);
}

void rabbit1(int x, int y)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 30);
    floodfill(x, y, WHITE);
    /// nose
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y, 8);
    floodfill(x, y, RGB(85, 27, 49));
    /// under-nose
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 6, y + 6, 6);
    floodfill(x + 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 6, y + 6, 6);
    floodfill(x - 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y + 4, 4);
    floodfill(x, y + 4, RGB(85, 27, 49));
    /// white stuff
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 6, y + 4, 5);
    floodfill(x - 6, y + 4, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 6, y + 4, 5);
    floodfill(x + 6, y + 4, WHITE);
    /// mustati
    setcolor(RGB(85, 27, 49));
    setlinestyle(SOLID_LINE, 2, 1);
    line(x - 6, y + 4, x - 25, y + 8);
    line(x + 6, y + 4, x + 25, y + 8);
    line(x - 6, y + 2, x - 25, y + 3);
    line(x + 6, y + 2, x + 25, y + 3);
    line(x - 6, y + 1, x - 25, y);
    line(x + 6, y + 1, x + 25, y);
    /// eyes
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 13, y - 13, 4);
    floodfill(x - 13, y - 13, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 13, y - 13, 4);
    floodfill(x + 13, y - 13, RGB(85, 27, 49));
    /// above-eye dots
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 12, y - 22, 3);
    floodfill(x - 12, y - 22, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 12, y - 22, 3);
    floodfill(x + 12, y - 22, WHITE);
}

void HIGHLrabbit1(int x, int y)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 30);
    floodfill(x, y, WHITE);
    /// nose
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y, 8);
    floodfill(x, y, RGB(85, 27, 49));
    /// under-nose
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 6, y + 6, 6);
    floodfill(x + 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 6, y + 6, 6);
    floodfill(x - 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y + 4, 4);
    floodfill(x, y + 4, RGB(85, 27, 49));
    /// white stuff
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 6, y + 4, 5);
    floodfill(x - 6, y + 4, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 6, y + 4, 5);
    floodfill(x + 6, y + 4, WHITE);
    /// mustati
    setcolor(RGB(85, 27, 49));
    setlinestyle(SOLID_LINE, 2, 1);
    line(x - 6, y + 4, x - 25, y + 8);
    line(x + 6, y + 4, x + 25, y + 8);
    line(x - 6, y + 2, x - 25, y + 3);
    line(x + 6, y + 2, x + 25, y + 3);
    line(x - 6, y + 1, x - 25, y);
    line(x + 6, y + 1, x + 25, y);
    /// eyes
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 13, y - 13, 4);
    floodfill(x - 13, y - 13, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 13, y - 13, 4);
    floodfill(x + 13, y - 13, RGB(85, 27, 49));
    /// above-eye dots
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 12, y - 22, 3);
    floodfill(x - 12, y - 22, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 12, y - 22, 3);
    floodfill(x + 12, y - 22, WHITE);
    /// highlight
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);
    circle(x, y, 35);
}

void rabbit2(int x, int y)
{
    setcolor(RGB(167, 169, 172));
    setfillstyle(SOLID_FILL, RGB(167, 169, 172));
    circle(x, y, 30);
    floodfill(x, y, RGB(167, 169, 172));
    /// nose
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y, 8);
    floodfill(x, y, RGB(85, 27, 49));
    /// under-nose
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 6, y + 6, 6);
    floodfill(x + 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 6, y + 6, 6);
    floodfill(x - 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y + 4, 4);
    floodfill(x, y + 4, RGB(85, 27, 49));
    /// white stuff
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 6, y + 4, 5);
    floodfill(x - 6, y + 4, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 6, y + 4, 5);
    floodfill(x + 6, y + 4, WHITE);
    /// mustati
    setcolor(RGB(85, 27, 49));
    setlinestyle(SOLID_LINE, 2, 1);
    line(x - 6, y + 4, x - 25, y + 8);
    line(x + 6, y + 4, x + 25, y + 8);
    line(x - 6, y + 2, x - 25, y + 3);
    line(x + 6, y + 2, x + 25, y + 3);
    line(x - 6, y + 1, x - 25, y);
    line(x + 6, y + 1, x + 25, y);
    /// eyes
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 13, y - 13, 4);
    floodfill(x - 13, y - 13, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 13, y - 13, 4);
    floodfill(x + 13, y - 13, RGB(85, 27, 49));
    /// above-eye dots
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 12, y - 22, 3);
    floodfill(x - 12, y - 22, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 12, y - 22, 3);
    floodfill(x + 12, y - 22, WHITE);
}

void HIGHLrabbit2(int x, int y)
{
    setcolor(RGB(167, 169, 172));
    setfillstyle(SOLID_FILL, RGB(167, 169, 172));
    circle(x, y, 30);
    floodfill(x, y, RGB(167, 169, 172));
    /// nose
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y, 8);
    floodfill(x, y, RGB(85, 27, 49));
    /// under-nose
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 6, y + 6, 6);
    floodfill(x + 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 6, y + 6, 6);
    floodfill(x - 6, y + 6, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x, y + 4, 4);
    floodfill(x, y + 4, RGB(85, 27, 49));
    /// white stuff
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 6, y + 4, 5);
    floodfill(x - 6, y + 4, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 6, y + 4, 5);
    floodfill(x + 6, y + 4, WHITE);
    /// mustati
    setcolor(RGB(85, 27, 49));
    setlinestyle(SOLID_LINE, 2, 1);
    line(x - 6, y + 4, x - 25, y + 8);
    line(x + 6, y + 4, x + 25, y + 8);
    line(x - 6, y + 2, x - 25, y + 3);
    line(x + 6, y + 2, x + 25, y + 3);
    line(x - 6, y + 1, x - 25, y);
    line(x + 6, y + 1, x + 25, y);
    /// eyes
    setcolor(RGB(85, 27, 49));
    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x - 13, y - 13, 4);
    floodfill(x - 13, y - 13, RGB(85, 27, 49));

    setfillstyle(SOLID_FILL, RGB(85, 27, 49));
    circle(x + 13, y - 13, 4);
    floodfill(x + 13, y - 13, RGB(85, 27, 49));
    /// above-eye dots
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 12, y - 22, 3);
    floodfill(x - 12, y - 22, WHITE);

    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 12, y - 22, 3);
    floodfill(x + 12, y - 22, WHITE);
    /// highlight
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);
    circle(x, y, 35);
}

void HIGHLfox(int x1, int y1, int x2, int y2){
    ///legs
    setcolor(RGB(226,104,30));
    setfillstyle(SOLID_FILL, RGB(226,104,30));
    circle(x1+25, y1-30, 15);
    floodfill(x1+25,y1-30,RGB(226,104,30));
    circle(x1+25, y1+30, 15);
    floodfill(x1+25,y1+30,RGB(226,104,30));

    circle(x2-20, y1-27, 15);
    floodfill(x2-20,y1-27,RGB(226,104,30));
    circle(x2-20, y1+27, 15);
    floodfill(x2-20,y1+27,RGB(226,104,30));
    //tail
    setcolor(RGB(243,111,33));
    setfillstyle(SOLID_FILL, RGB(243,111,33));
    int r1=30;
    for(int i=x2+20; i<=x2+50; i+=2)
    {
        circle(i, y1, r1--);
        floodfill(i, y1, RGB(243,111,33));
    }
    ///body
    ///RGB(226,104,30)
    setcolor(RGB(226,104,30));
    setfillstyle(SOLID_FILL, RGB(226,104,30));
    for(int i=x1+30; i<=x2-30; i++)
    {   
        circle(i, y1, 36);
        floodfill(i,y1,RGB(226,104,30));
    }
    ///head
    ///RGB(243,111,33)
    setcolor(RGB(243,111,33));
    setfillstyle(SOLID_FILL, RGB(243,111,33));
    circle(x1, y1, 30);
    floodfill(x1,y1,RGB(243,111,33));
    ///nose
    int r=30;
    for(int i=x1-10; i>=x1-60; i-=2)
    {   
        circle(i, y1, r--);
        if(r>0)
            floodfill(i, y1, RGB(243,111,33));
    }
    setcolor(WHITE);///white nose fur
    setlinestyle(SOLID_LINE, 0,5);
    line(x1-20,y1-26,x1-60, y1-5);
    line(x1-20,y1+26,x1-60, y1+5);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x1-60, y1, 6);
    floodfill(x1-60, y1,BLACK);
    ///eyes
    circle(x1-40, y1-10, 3);
    circle(x1-40, y1+10, 3);
    ///ears
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0,3);
    arc(x1+10, y1-15, 270, 140, 10);
    arc(x1+10, y1-15, 270, 140, 4);
    arc(x1+10, y1+15, 200, 80, 10);
    arc(x1+10, y1+15, 200, 80, 4);
    ///dreptunghi inconjurator
    line(x1-70,y1+60, x1-70, y1-60);
    line(x1-70,y1+60, x2+70, y2+60);
    line(x1-70,y1-60, x2+70, y2-60);
    line(x2+70,y1-60, x2+70, y2+60);
}

void fox(int x1, int y1, int x2, int y2){
    ///legs
    setcolor(RGB(226,104,30));
    setfillstyle(SOLID_FILL, RGB(226,104,30));
    circle(x1+25, y1-30, 15);
    floodfill(x1+25,y1-30,RGB(226,104,30));
    circle(x1+25, y1+30, 15);
    floodfill(x1+25,y1+30,RGB(226,104,30));

    circle(x2-20, y1-27, 15);
    floodfill(x2-20,y1-27,RGB(226,104,30));
    circle(x2-20, y1+27, 15);
    floodfill(x2-20,y1+27,RGB(226,104,30));
    //tail
    setcolor(RGB(243,111,33));
    setfillstyle(SOLID_FILL, RGB(243,111,33));
    int r1=30;
    for(int i=x2+20; i<=x2+50; i+=2)
    {
        circle(i, y1, r1--);
        floodfill(i, y1, RGB(243,111,33));
    }
    ///body
    ///RGB(226,104,30)
    setcolor(RGB(226,104,30));
    setfillstyle(SOLID_FILL, RGB(226,104,30));
    for(int i=x1+30; i<=x2-30; i++)
    {   
        circle(i, y1, 36);
        floodfill(i,y1,RGB(226,104,30));
    }
    ///head
    ///RGB(243,111,33)
    setcolor(RGB(243,111,33));
    setfillstyle(SOLID_FILL, RGB(243,111,33));
    circle(x1, y1, 30);
    floodfill(x1,y1,RGB(243,111,33));
    ///nose
    int r=30;
    for(int i=x1-10; i>=x1-60; i-=2)
    {   
        circle(i, y1, r--);
        if(r>0)
            floodfill(i, y1, RGB(243,111,33));
    }
    setcolor(WHITE);///white nose fur
    setlinestyle(SOLID_LINE, 0,5);
    line(x1-20,y1-26,x1-60, y1-5);
    line(x1-20,y1+26,x1-60, y1+5);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x1-60, y1, 6);
    floodfill(x1-60, y1,BLACK);
    ///eyes
    circle(x1-40, y1-10, 3);
    circle(x1-40, y1+10, 3);
    ///ears
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0,3);
    arc(x1+10, y1-15, 270, 140, 10);
    arc(x1+10, y1-15, 270, 140, 4);
    arc(x1+10, y1+15, 200, 80, 10);
    arc(x1+10, y1+15, 200, 80, 4);
}

void mushroom(int x, int y)
{
    a[y][x] = 1;
    x = 130 + 160 * (x - 1);
    y = 130 + 160 * (y - 1);

    setcolor(RGB(237, 28, 36));
    setfillstyle(SOLID_FILL, RGB(237, 28, 36));
    circle(x, y, 60);
    floodfill(x, y, RGB(237, 28, 36));
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 25, y - 25, 10);
    floodfill(x - 25, y - 25, WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 30, y + 15, 10);
    floodfill(x - 30, y + 15, WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 10);
    floodfill(x, y, WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 25, y + 25, 10);
    floodfill(x + 25, y + 25, WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 30, y - 15, 10);
    floodfill(x + 30, y - 15, WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x + 5, y - 35, 10);
    floodfill(x + 5, y - 35, WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x - 5, y + 35, 10);
    floodfill(x - 5, y + 35, WHITE);
}

void cover(int px, int py)
{
    if (px == 130 && py == 130 || px == 770 && py == 770 || px == 130 && py == 770 || px == 770 && py == 130 || px == 450 && py == 450)
    {
        setcolor(RGB(69, 50, 20));
        setfillstyle(SOLID_FILL, RGB(69, 50, 20));
        int hexagon[] = {px - 60, py, px - 40, py + 45, px + 40, py + 43, px + 55, py, px + 40, py - 45, px - 40, py - 45};
        fillpoly(6, hexagon);
    }
    else
    {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        int hexagon[] = {px - 45, py, px - 35, py + 35, px + 35, py + 35, px + 45, py, px + 35, py - 35, px - 35, py - 35};
        fillpoly(6, hexagon);
    }
}

void specialcover(int px, int py)
{
    if (px == 130 && py == 130 || px == 770 && py == 770 || px == 130 && py == 770 || px == 770 && py == 130 || px == 450 && py == 450)
    {
        setcolor(RGB(69, 50, 20));
        setfillstyle(SOLID_FILL, RGB(69, 50, 20));
        int hexagon[] = {px - 60, py, px - 40, py + 45, px + 40, py + 43, px + 55, py, px + 40, py - 45, px - 40, py - 45};
        fillpoly(6, hexagon);
        a[(py - 130) / 160 + 1][(px - 130) / 160 + 1] = 2;
    }
    else
    {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        int hexagon[] = {px - 45, py, px - 35, py + 35, px + 35, py + 35, px + 45, py, px + 35, py - 35, px - 35, py - 35};
        fillpoly(6, hexagon);
        a[(py - 130) / 160 + 1][(px - 130) / 160 + 1] = 0;
    }
}

void foxcover(int px1, int py1, int px2, int py2){
    setcolor(RGB(0, 172, 79));
    setfillstyle(SOLID_FILL, RGB(0, 172, 79));
    rectangle(px1+80,py1+75,px1-80,py1-75);
    floodfill(px1,py1,RGB(0, 172, 79));
    rectangle(px2+75,py2+75,px2-80,py2-75);
    floodfill(px2,py2,RGB(0, 172, 79));
    floodfill(px2+70,py1-60,RGB(0, 172, 79));
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    circle(px1, py1, 50);
    floodfill(px1, py1, GREEN);
    circle(px2, py2, 50);
    floodfill(px2, py2, GREEN);
}

void congrats1()
{
    initwindow(1050, 591, "CONGRATS");
    readimagefile("lvl1done.bmp", 50, 50, 1050, 591);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(70, 250, "Congrats on clearing level 1!");
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(70, 300, "(press any key to continue)");
    getch();
    closegraph();
}

void congrats2()
{
    initwindow(800, 450, "CONGRATS");
    readimagefile("lvl2done.jpg", 50, 50, 800, 450);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(50, 225, "Congrats on clearing level 2!");
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(50, 275, "(press any key to continue)");
    getch();
    closegraph();
}

void congrats3()
{
    initwindow(600, 700, "Congrats!");
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(1, 1, YELLOW);
    setlinestyle(SOLID_LINE, 0, 5);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(300, 300, 200);
    circle(225, 250, 30); /// eye
    floodfill(225, 250, BLACK);
    circle(375, 250, 30); /// eye
    floodfill(375, 250, BLACK);
    circle(300, 400, 50); /// mouth
    floodfill(300, 400, BLACK);

    // Add the message
    setcolor(WHITE);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(80, 550, "Congrats on clearing level 3!");
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(110, 600, "(press any key to continue)");
    getch();
    closegraph();
}

void congrats4()
{
    initwindow(600, 700, "Congrats!");
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(1, 1, YELLOW);
    setlinestyle(SOLID_LINE, 0, 5);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(300, 300, 200);
    /// heart eyes
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    circle(200, 225, 30);
    floodfill(200, 225, RED);
    circle(240, 225, 30);
    floodfill(240, 225, RED);
    setlinestyle(SOLID_LINE, 0, 4);
    line(171, 236, 220, 290);
    line(265, 240, 220, 290);
    floodfill(220, 280, RED);

    circle(360, 225, 30);
    floodfill(360, 225, RED);
    circle(400, 225, 30);
    floodfill(400, 225, RED);
    setlinestyle(SOLID_LINE, 0, 4);
    line(331, 236, 380, 290);
    line(425, 240, 380, 290);
    floodfill(380, 280, RED);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(300, 400, 40);
    floodfill(300, 400, BLACK);

    // Add the message
    setcolor(WHITE);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(80, 550, "Congrats on clearing level 4!");
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(110, 600, "(press any key to continue)");
    getch();
    closegraph();
}

void congrats5()
{
    initwindow(600, 700, "Congrats!");
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(1, 1, YELLOW);
    setlinestyle(SOLID_LINE, 0, 5);
    setcolor(WHITE);
    // Add the message
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(50, 250, "Congratulations!");
    delay(2000);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(60, 350, "YOU FINISHED THE GAME!");
    settextstyle(4, HORIZ_DIR, 2);
    delay(2000);
    outtextxy(350, 580, "Credits:");
    outtextxy(350, 610, "Radu Dan-Stefan");
    ///outtextxy(350, 640, "Nunu Cristiano");
    getch();
    closegraph();
}

/// backend :(

void movement1(int x1, int y1)
{
    x1 = 130 + 160 * (x1 - 1);
    y1 = 130 + 160 * (y1 - 1);
    char key;
    int px1 = x1, py1 = y1;
    /// Draw rabbit
    rabbit(x1, y1);
    a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
    key = getch(); // Get the key
    do
    {
        if (key == '1')
        {
            while (ok != 1)
            {
                HIGHLrabbit(x1, y1);
                int new_x1 = x1;
                int new_y1 = y1;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y1 - 160, new_x1) && OKMatrix(new_y1 - 160, new_x1) != 2)
                    {
                        new_y1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y1 + 160, new_x1) && OKMatrix(new_y1 + 160, new_x1) != 2)
                    {
                        new_y1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y1, new_x1 - 160) && OKMatrix(new_y1, new_x1 - 160) != 2)
                    {
                        new_x1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y1, new_x1 + 160) && OKMatrix(new_y1, new_x1 + 160) != 2)
                    {
                        new_x1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 += 160;
                    }
                    break;
                }
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x1 >= 130 && new_x1 <= 780 && new_y1 >= 130 && new_y1 <= 780)
                {
                    // Updating the position
                    if (x1 != new_x1 || y1 != new_y1)
                    {
                        x1 = new_x1;
                        y1 = new_y1;
                        HIGHLrabbit(x1, y1);
                        a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
                        /// deleting the old position
                        specialcover(px1, py1);
                        px1 = x1;
                        py1 = y1;
                        if (scanmatrix(4) == 1)
                        {
                            ok = 1;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 1
            cover(px1, py1);
            rabbit(x1, y1);
        }
        if (ok == 1)
            break;
    } while (key != 27); // Continue until the ESC key is pressed or the rabbit reaches the hole
    delay(1000);
}

void movement2(int x1, int y1, int x2, int y2)
{
    x1 = 130 + 160 * (x1 - 1);
    y1 = 130 + 160 * (y1 - 1);
    x2 = 130 + 160 * (x2 - 1);
    y2 = 130 + 160 * (y2 - 1);
    int radius = 40;
    char key;
    int px1 = x1, py1 = y1, px2 = x2, py2 = y2, ok1 = 0, ok2 = 0;

    // Draw rabbit
    rabbit(x1, y1);
    rabbit1(x2, y2);
    a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
    a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 4;
    key = getch(); // Get the key
    do
    {
        if (key == '1')
        {
            while (ok != 2)
            {
                HIGHLrabbit(x1, y1);
                int new_x1 = x1;
                int new_y1 = y1;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y1 - 160, new_x1) && OKMatrix(new_y1 - 160, new_x1) != 2)
                    {
                        new_y1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y1 + 160, new_x1) && OKMatrix(new_y1 + 160, new_x1) != 2)
                    {
                        new_y1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y1, new_x1 - 160) && OKMatrix(new_y1, new_x1 - 160) != 2)
                    {
                        new_x1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y1, new_x1 + 160) && OKMatrix(new_y1, new_x1 + 160) != 2)
                    {
                        new_x1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 += 160;
                    }
                    break;
                }
                if (key == '2')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x1 >= 130 && new_x1 <= 780 && new_y1 >= 130 && new_y1 <= 780)
                {
                    // Updating the position
                    if (x1 != new_x1 || y1 != new_y1)
                    {
                        ok1 = 0;
                        x1 = new_x1;
                        y1 = new_y1;
                        HIGHLrabbit(x1, y1);
                        a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
                        /// deleting the old position
                        specialcover(px1, py1);
                        px1 = x1;
                        py1 = y1;
                        if (OKMatrix((y1 - 130) / 160 + 1, (x1 - 130) / 160 + 1) == 2)
                        {
                            ok1 = 1;
                        }
                        if (ok1 == ok2 && ok1 == 1)
                        {
                            ok = 2;
                        }
                    }
                }
            }
            /// deselect the rabbit 1
            cover(px1, py1);
            rabbit(x1, y1);
        }
        else if (key == '2')
        {
            while (ok != 2)
            {
                ok2 = 0; /// it makes 0 sense for the OK to be here BUT THE CODE WORKS NOW
                HIGHLrabbit1(x2, y2);
                int new_x2 = x2;
                int new_y2 = y2;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y2 - 160, new_x2) && OKMatrix(new_y2 - 160, new_x2) != 2)
                    {
                        new_y2 -= 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_y2 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y2 + 160, new_x2) && OKMatrix(new_y2 + 160, new_x2) != 2)
                    {
                        new_y2 += 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_y2 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y2, new_x2 - 160) && OKMatrix(new_y2, new_x2 - 160) != 2)
                    {
                        new_x2 -= 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_x2 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y2, new_x2 + 160) && OKMatrix(new_y2, new_x2 + 160) != 2)
                    {
                        new_x2 += 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_x2 += 160;
                    }
                    break;
                }
                if (key == '1')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x2 >= 130 && new_x2 <= 780 && new_y2 >= 130 && new_y2 <= 780)
                {
                    // Update the position
                    if (x2 != new_x2 || y2 != new_y2)
                    {
                        x2 = new_x2;
                        y2 = new_y2;
                        HIGHLrabbit(x2, y2);
                        a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 4;
                        specialcover(px2, py2);
                        px2 = x2;
                        py2 = y2;
                        if (OKMatrix((y2 - 130) / 160 + 1, (x2 - 130) / 160 + 1) == 2)
                        {
                            ok2 = 1;
                        }
                        if (ok1 == ok2 && ok1 == 1)
                        {
                            ok = 2;
                        }
                    }
                }
            }
            /// deselect the rabbit 2
            cover(px2, py2);
            rabbit1(x2, y2);
        }
        if (ok == 2)
            break;
    } while (key != 27); // Continue until the ESC key is pressed or the rabbit reaches the hole
    delay(1000);
}

void movement3(int x1, int y1, int x2, int y2, int x3, int y3)
{
    x1 = 130 + 160 * (x1 - 1);
    y1 = 130 + 160 * (y1 - 1);
    x2 = 130 + 160 * (x2 - 1);
    y2 = 130 + 160 * (y2 - 1);
    x3 = 130 + 160 * (x3 - 1);
    y3 = 130 + 160 * (y3 - 1);
    char key;
    int px1 = x1, py1 = y1, px2 = x2, py2 = y2, ok1 = 0, ok2 = 0, ok3 = 0, px3 = x3, py3 = y3;
    /// Draw rabbit
    rabbit(x1, y1);
    rabbit1(x2, y2);
    rabbit2(x3, y3);
    a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
    a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 4;
    a[(y3 - 130) / 160 + 1][(x3 - 130) / 160 + 1] = 5;
    key = getch(); // Get the key
    do
    {
        if (key == '1')
        {
            while (ok != 3)
            {
                HIGHLrabbit(x1, y1);
                int new_x1 = x1;
                int new_y1 = y1;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y1 - 160, new_x1) && OKMatrix(new_y1 - 160, new_x1) != 2)
                    {
                        new_y1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y1 + 160, new_x1) && OKMatrix(new_y1 + 160, new_x1) != 2)
                    {
                        new_y1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y1, new_x1 - 160) && OKMatrix(new_y1, new_x1 - 160) != 2)
                    {
                        new_x1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y1, new_x1 + 160) && OKMatrix(new_y1, new_x1 + 160) != 2)
                    {
                        new_x1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 += 160;
                    }
                    break;
                }
                if (key == '3' || key == '2')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x1 >= 130 && new_x1 <= 780 && new_y1 >= 130 && new_y1 <= 780)
                {
                    // Updating the position
                    if (x1 != new_x1 || y1 != new_y1)
                    {
                        x1 = new_x1;
                        y1 = new_y1;
                        HIGHLrabbit(x1, y1);
                        a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
                        /// deleting the old position
                        specialcover(px1, py1);
                        px1 = x1;
                        py1 = y1;
                        if (OKMatrix((y1 - 130) / 160 + 1, (x1 - 130) / 160 + 1) == 2)
                        {
                            ok1 = 1;
                        }
                        if (scanmatrix(2) == 1)
                        {
                            ok = 3;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 1
            cover(px1, py1);
            rabbit(x1, y1);
        }
        else if (key == '2')
        {
            while (ok != 3)
            {

                HIGHLrabbit1(x2, y2);
                int new_x2 = x2;
                int new_y2 = y2;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y2 - 160, new_x2) && OKMatrix(new_y2 - 160, new_x2) != 2)
                    {
                        new_y2 -= 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_y2 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y2 + 160, new_x2) && OKMatrix(new_y2 + 160, new_x2) != 2)
                    {
                        new_y2 += 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_y2 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y2, new_x2 - 160) && OKMatrix(new_y2, new_x2 - 160) != 2)
                    {
                        new_x2 -= 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_x2 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y2, new_x2 + 160) && OKMatrix(new_y2, new_x2 + 160) != 2)
                    {
                        new_x2 += 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_x2 += 160;
                    }
                    break;
                }
                if (key == '1' || key == '3')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x2 >= 130 && new_x2 <= 780 && new_y2 >= 130 && new_y2 <= 780)
                {
                    // Update the position
                    if (x2 != new_x2 || y2 != new_y2)
                    {

                        x2 = new_x2;
                        y2 = new_y2;
                        HIGHLrabbit(x2, y2);
                        a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 4;
                        specialcover(px2, py2);
                        px2 = x2;
                        py2 = y2;
                        if (OKMatrix((y2 - 130) / 160 + 1, (x2 - 130) / 160 + 1) == 2)
                        {
                            ok2 = 1;
                        }
                        if (scanmatrix(2) == 1)
                        {
                            ok = 3;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 2
            cover(px2, py2);
            rabbit1(x2, y2);
        }
        else if (key == '3')
        {
            while (ok != 3)
            {

                HIGHLrabbit2(x3, y3);
                int new_x3 = x3;
                int new_y3 = y3;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y3 - 160, new_x3) && OKMatrix(new_y3 - 160, new_x3) != 2)
                    {
                        new_y3 -= 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_y3 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y3 + 160, new_x3) && OKMatrix(new_y3 + 160, new_x3) != 2)
                    {
                        new_y3 += 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_y3 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y3, new_x3 - 160) && OKMatrix(new_y3, new_x3 - 160) != 2)
                    {
                        new_x3 -= 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_x3 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y3, new_x3 + 160) && OKMatrix(new_y3, new_x3 + 160) != 2)
                    {
                        new_x3 += 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_x3 += 160;
                    }
                    break;
                }
                if (key == '1' || key == '2')
                    break;
                if (new_x3 >= 130 && new_x3 <= 780 && new_y3 >= 130 && new_y3 <= 780)
                {
                    // Update the position
                    if (x3 != new_x3 || y3 != new_y3)
                    {

                        x3 = new_x3;
                        y3 = new_y3;
                        HIGHLrabbit2(x3, y3);
                        a[(y3 - 130) / 160 + 1][(x3 - 130) / 160 + 1] = 5;
                        specialcover(px3, py3);
                        px3 = x3;
                        py3 = y3;
                        if (OKMatrix((y3 - 130) / 160 + 1, (x3 - 130) / 160 + 1) == 2)
                        {
                            ok3 = 1;
                        }
                        if (scanmatrix(2) == 1)
                        {
                            ok = 3;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 3
            cover(px3, py3);
            rabbit2(x3, y3);
        }
        if (ok == 3)
            break;
    } while (key != 27); // Continue until the ESC key is pressed or the rabbit reaches the hole
    delay(1000);
}

void movement4(int x1, int y1, int x2, int y2, int x3, int y3)
{
    x1 = 130 + 160 * (x1 - 1);
    y1 = 130 + 160 * (y1 - 1);
    x2 = 130 + 160 * (x2 - 1);
    y2 = 130 + 160 * (y2 - 1);
    x3 = 130 + 160 * (x3 - 1);
    y3 = 130 + 160 * (y3 - 1);
    char key;
    int px1 = x1, py1 = y1, px2 = x2, py2 = y2, ok1 = 0, ok2 = 0, ok3 = 0, px3 = x3, py3 = y3;
    /// Draw rabbit
    rabbit(x1, y1);
    rabbit1(x2, y2);
    rabbit2(x3, y3);
    a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
    a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 4;
    a[(y3 - 130) / 160 + 1][(x3 - 130) / 160 + 1] = 5;
    key = getch(); // Get the key
    do
    {
        if (key == '1')
        {
            while (ok != 4)
            {
                HIGHLrabbit(x1, y1);
                int new_x1 = x1;
                int new_y1 = y1;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y1 - 160, new_x1) && OKMatrix(new_y1 - 160, new_x1) != 2)
                    {
                        new_y1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y1 + 160, new_x1) && OKMatrix(new_y1 + 160, new_x1) != 2)
                    {
                        new_y1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y1, new_x1 - 160) && OKMatrix(new_y1, new_x1 - 160) != 2)
                    {
                        new_x1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y1, new_x1 + 160) && OKMatrix(new_y1, new_x1 + 160) != 2)
                    {
                        new_x1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 += 160;
                    }
                    break;
                }
                if (key == '3' || key == '2')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x1 >= 130 && new_x1 <= 780 && new_y1 >= 130 && new_y1 <= 780)
                {
                    // Updating the position
                    if (x1 != new_x1 || y1 != new_y1)
                    {
                        x1 = new_x1;
                        y1 = new_y1;
                        HIGHLrabbit(x1, y1);
                        a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
                        /// deleting the old position
                        specialcover(px1, py1);
                        px1 = x1;
                        py1 = y1;
                        if (OKMatrix((y1 - 130) / 160 + 1, (x1 - 130) / 160 + 1) == 2)
                        {
                            ok1 = 1;
                        }
                        if (scanmatrix(2) == 1)
                        {
                            ok = 4;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 1
            cover(px1, py1);
            rabbit(x1, y1);
        }
        else if (key == '2')
        {
            while (ok != 4)
            {

                HIGHLrabbit1(x2, y2);
                int new_x2 = x2;
                int new_y2 = y2;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y2 - 160, new_x2) && OKMatrix(new_y2 - 160, new_x2) != 2)
                    {
                        new_y2 -= 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_y2 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y2 + 160, new_x2) && OKMatrix(new_y2 + 160, new_x2) != 2)
                    {
                        new_y2 += 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_y2 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y2, new_x2 - 160) && OKMatrix(new_y2, new_x2 - 160) != 2)
                    {
                        new_x2 -= 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_x2 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y2, new_x2 + 160) && OKMatrix(new_y2, new_x2 + 160) != 2)
                    {
                        new_x2 += 160;
                        while (OKMatrix(new_y2, new_x2) && OKMatrix(new_y2, new_x2) != 2)
                            new_x2 += 160;
                    }
                    break;
                }
                if (key == '1' || key == '3')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x2 >= 130 && new_x2 <= 780 && new_y2 >= 130 && new_y2 <= 780)
                {
                    // Update the position
                    if (x2 != new_x2 || y2 != new_y2)
                    {

                        x2 = new_x2;
                        y2 = new_y2;
                        HIGHLrabbit(x2, y2);
                        a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 4;
                        specialcover(px2, py2);
                        px2 = x2;
                        py2 = y2;
                        if (OKMatrix((y2 - 130) / 160 + 1, (x2 - 130) / 160 + 1) == 2)
                        {
                            ok2 = 1;
                        }
                        if (scanmatrix(2) == 1)
                        {
                            ok = 4;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 2
            cover(px2, py2);
            rabbit1(x2, y2);
        }
        else if (key == '3')
        {
            while (ok != 4)
            {

                HIGHLrabbit2(x3, y3);
                int new_x3 = x3;
                int new_y3 = y3;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y3 - 160, new_x3) && OKMatrix(new_y3 - 160, new_x3) != 2)
                    {
                        new_y3 -= 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_y3 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y3 + 160, new_x3) && OKMatrix(new_y3 + 160, new_x3) != 2)
                    {
                        new_y3 += 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_y3 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y3, new_x3 - 160) && OKMatrix(new_y3, new_x3 - 160) != 2)
                    {
                        new_x3 -= 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_x3 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y3, new_x3 + 160) && OKMatrix(new_y3, new_x3 + 160) != 2)
                    {
                        new_x3 += 160;
                        while (OKMatrix(new_y3, new_x3) && OKMatrix(new_y3, new_x3) != 2)
                            new_x3 += 160;
                    }
                    break;
                }
                if (key == '1' || key == '2')
                    break;
                if (new_x3 >= 130 && new_x3 <= 780 && new_y3 >= 130 && new_y3 <= 780)
                {
                    // Update the position
                    if (x3 != new_x3 || y3 != new_y3)
                    {

                        x3 = new_x3;
                        y3 = new_y3;
                        HIGHLrabbit2(x3, y3);
                        a[(y3 - 130) / 160 + 1][(x3 - 130) / 160 + 1] = 5;
                        specialcover(px3, py3);
                        px3 = x3;
                        py3 = y3;
                        if (OKMatrix((y3 - 130) / 160 + 1, (x3 - 130) / 160 + 1) == 2)
                        {
                            ok3 = 1;
                        }
                        if (scanmatrix(2) == 1)
                        {
                            ok = 4;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit 3
            cover(px3, py3);
            rabbit2(x3, y3);
        }
        if (ok == 4)
            break;
    } while (key != 27); // Continue until the ESC key is pressed or the rabbit reaches the hole
    delay(1000);
}

void movement5(int x1, int y1, int x2, int y2)
{   
    x1 = 130 + 160 * (x1 - 1);
    y1 = 130 + 160 * (y1 - 1);
    x2 = 130 + 160 * (x2 - 1);
    y2 = 130 + 160 * (y2 - 1);
    int x3=x2+160, y3=y2;
    char key;
    int px1 = x1, py1 = y1, px2 = x2, py2 = y2, px3 = x3, py3 = y3;
    /// Draw rabbit and the fox
    rabbit1(x1, y1);
    fox(x2,y2,x3,y3);
    a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 4;
    a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 6;
    a[(y3 - 130) / 160 + 1][(x3 - 130) / 160 + 1] = 6;
    key = getch(); // Get the key
    do
    {
        if (key == '1')
        {
            while (ok != 5)
            {
                HIGHLrabbit1(x1, y1);
                int new_x1 = x1;
                int new_y1 = y1;
                key = getch();
                // position
                switch (key)
                {
                case 'w':
                    if (OKMatrix(new_y1 - 160, new_x1) && OKMatrix(new_y1 - 160, new_x1) != 2)
                    {
                        new_y1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 -= 160;
                    }
                    break;
                case 's':
                    if (OKMatrix(new_y1 + 160, new_x1) && OKMatrix(new_y1 + 160, new_x1) != 2)
                    {
                        new_y1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_y1 += 160;
                    }
                    break;
                case 'a':
                    if (OKMatrix(new_y1, new_x1 - 160) && OKMatrix(new_y1, new_x1 - 160) != 2)
                    {
                        new_x1 -= 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y1, new_x1 + 160) && OKMatrix(new_y1, new_x1 + 160) != 2)
                    {
                        new_x1 += 160;
                        while (OKMatrix(new_y1, new_x1) && OKMatrix(new_y1, new_x1) != 2)
                            new_x1 += 160;
                    }
                    break;
                }
                if (key == '2')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x1 >= 130 && new_x1 <= 780 && new_y1 >= 130 && new_y1 <= 780)
                {
                    // Updating the position
                    if (x1 != new_x1 || y1 != new_y1)
                    {
                        x1 = new_x1;
                        y1 = new_y1;
                        HIGHLrabbit1(x1, y1);
                        a[(y1 - 130) / 160 + 1][(x1 - 130) / 160 + 1] = 3;
                        /// deleting the old position
                        specialcover(px1, py1);
                        px1 = x1;
                        py1 = y1;
                        if (scanmatrix(3) == 1)
                        {
                            ok = 5;
                            break;
                        }
                    }
                }
            }
            /// deselect the rabbit #1
            cover(px1, py1);
            rabbit1(x1, y1);
        }
        else if (key == '2')
        {
            while (ok != 5)
            {

                HIGHLfox(x2,y2,x3,y3);
                int new_x2 = x2;
                int new_y2 = y2;
                int new_x3 = x3;
                int new_y3 = y3;
                key = getch();
                // position
                switch (key)
                {
                case 'a':
                    if (OKMatrix(new_y2, new_x2 - 160)== 0)
                    {
                        new_x2 -= 160;
                        new_x3 -= 160;
                    }
                    break;
                case 'd':
                    if (OKMatrix(new_y3, new_x3 + 160)==0)
                    {
                        new_x3 += 160;
                        new_x2 += 160;
                    }
                    break;
                }
                if (key == '1')
                    break;
                // Check if the new position is within the playfield and is !! possible !!
                if (new_x2 >= 130 && new_x3 <= 780 && new_y2 >= 130 && new_y2 <= 780)
                {
                    // Update the position
                    if (x2 != new_x2 || y2 != new_y2)
                    {

                        x2 = new_x2;
                        y2 = new_y2;
                        x3 = new_x3;
                        y3 = new_y3;
                        HIGHLfox(x2,y2,x3,y3);
                        a[(y2 - 130) / 160 + 1][(x2 - 130) / 160 + 1] = 6;
                        a[(y3 - 130) / 160 + 1][(x3 - 130) / 160 + 1] = 6;
                        foxcover(px2, py2, px3, py3);
                        px2 = x2;
                        py2 = y2;
                        px3 = x3;
                        py3 = y3;
                    }
                }
            }
            /// deselect the rabbit 2
            foxcover(px2, py2, px3, py3);
            fox(x2,y2,x3,y3);
        }
        if (ok == 5)
            break;
    } while (key != 27); // Continue until the ESC key is pressed or the rabbit reaches the hole
    delay(1000);
}

void board()
{
    initwindow(900, 880, "JumpIN'");
    playfield();
    circles();
    circlesandsquares();
}

void startscreen()
{
    initwindow(900, 880, "JumpIN' Startscreen");
    setfillstyle(SOLID_FILL, RGB(196,253,195));
    floodfill(1, 1, RGB(196,253,195));
    setlinestyle(SOLID_LINE, 0, 5);
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(100, 100, "Welcome to JumpIN'");
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(70, 200, "-Select the rabbit you want to control using");
    outtextxy(70, 230, " the number keys");
    outtextxy(70, 260, "-Once selected, control the rabbit using");
    outtextxy(70, 290, " the W A S D keys");
    outtextxy(70, 320, "-The object of the game is to move the rabbits");
    outtextxy(70, 350, " and foxes around the gameboard until all of the");
    outtextxy(70, 380, " rabbits are safe in brown holes.");
    outtextxy(70, 410, "-Rabbits can only move by jumping over obstacles");
    outtextxy(70, 440, " (other rabbits, foxes, mushrooms or ");
    outtextxy(70, 470, " a combination of these), foxes can only move");
    outtextxy(70, 500, " forwardor backward and cannot jump over");
    outtextxy(70, 530, " obstacles");
    outtextxy(70, 580, "Have fun!");
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(70, 630, "Press any key to start");
    while (!kbhit())
    {
        delay(500);
    }
    closegraph();
}

void lvl1()
{
    board();
    mushroom(2, 1); /// coordonatele sunt y, x, nu x, y for some odd fucking reason
    mushroom(3, 1);
    mushroom(4, 2);
    matrix();
    movement1(4, 3);
    if (ok == 1)
    {
        congrats1();
    }
}

void lvl2()
{
    clearmatrix();
    board();
    mushroom(3, 4); /// coordonatele sunt y, x, nu x, y for some odd fucking reason
    mushroom(3, 2);
    mushroom(4, 1);
    matrix();
    movement2(2, 1, 3, 5);
    if (ok == 2)
        congrats2();
}

void lvl3()
{
    clearmatrix();
    board();
    mushroom(2, 3); /// coordonatele sunt y, x, nu x, y for some odd fucking reason
    mushroom(4, 3);
    mushroom(5, 2);
    matrix();
    movement3(1, 3, 3, 3, 5, 3);
    if (ok == 3)
        congrats3();
}

void lvl4()
{
    clearmatrix();
    board();
    mushroom(2, 1); /// coordonatele sunt y, x, nu x, y for some odd fucking reason
    mushroom(3, 2);
    mushroom(4, 4);
    matrix();
    movement4(1, 1, 4, 1, 5, 3);
    if (ok == 4)
        congrats4();
}

void lvl5()
{
    clearmatrix();
    board();
    mushroom(4, 1); /// coordonatele sunt y, x, nu x, y for some odd fucking reason
    mushroom(2, 2);
    matrix();
    mushroom(3, 3);
    movement5(3, 2, 4, 2);
    if (ok == 5)
        congrats5();
}

int main()
{
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file
    startscreen();
    lvl1();
    if (ok == 1) /// the variable ok is keeping tabs on wether or not the user finished the current level he is on and what level is the finished one
        lvl2();
    if (ok == 2)
        lvl3();
    if (ok == 3)
        lvl4();
    if (ok == 4)
        lvl5();
    closegraph();
    return 0;
}

///clean, retail-ready version