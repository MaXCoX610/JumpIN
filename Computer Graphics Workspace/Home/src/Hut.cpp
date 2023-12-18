#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

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
}

void HIGHLrabbit(int x, int y)
{
    setcolor(RGB(159, 98, 5));
    setfillstyle(SOLID_FILL, RGB(159, 98, 5));
    circle(x, y, 30);
    floodfill(x, y, RGB(159, 98, 5));
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 35);
}

void mushroom(int x, int y)
{
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

void movement(int x, int y)
{
    int radius = 40;
    char key;
    int px = x, py = y;

    // Draw rabbit
    rabbit(x, y);
    key = getch(); // Get the key
    if (key == '1')
    {
        HIGHLrabbit(x, y);
        do
        {

            int new_x = x;
            int new_y = y;
            key = getch();
            // position
            switch (key)
            {
            case 'w':
                new_y -= 160;
                break;
            case 's':
                new_y += 160;
                break;
            case 'a':
                new_x -= 160;
                break;
            case 'd':
                new_x += 160;
                break;
            }

            // Check if the new position is within the playfield
            if (new_x >= 130 && new_x <= 780 && new_y >= 130 && new_y <= 780)
            {
                // Update the position if it's within the playfield
                x = new_x;
                y = new_y;
                HIGHLrabbit(x, y);
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
                px = x;
                py = y;
            }
        } while (key != 27); // Continue until the ESC key is pressed
    }
}

void board()
{
    initwindow(900, 880, "Level 1");
    playfield();
    circles();
    circlesandsquares();
}

void startscreen()
{
    initwindow(900, 880, "Main Menu");
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(100, 100, "Welcome to JumpIN'");
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(100, 200, "-Select the rabbit you want to control using");
    outtextxy(100, 230, " the number keys");
    outtextxy(100, 260, "-Once selected, control the rabbit using");
    outtextxy(100, 290, " the W A S D keys");
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(100, 600, "Press any key to start");
    while (!kbhit())
    {
        delay(100);
    }
    closegraph();
}

void lvl1()
{
    mushroom(290, 130);
    mushroom(450, 130);
    mushroom(610, 290);
    movement(610, 450);
}

int main()
{
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file
    startscreen();
    board();
    lvl1();
    closegraph();
    return 0;
}