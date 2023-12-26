#include <iostream>
#include <graphics.h>
#include <cmath>
#include <vector>

using namespace std;

int a[7][7];

/// backend :(

void matrix()
{
    a[1][1] = 2;
    a[1][5] = 2;
    a[3][3] = 2;
    a[5][1] = 2;
    a[5][5] = 2;
}

int OKMatrix(int newx, int newy)
{
    newx -= 130;
    newx = newx / 160 + 1;
    newy -= 130;
    newy = newy / 160 + 1;
    if (a[newx][newy] == 1)
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

void rabbit1(int x, int y)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 30);
    floodfill(x, y, WHITE);
}

void HIGHLrabbit1(int x, int y)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 30);
    floodfill(x, y, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 35);
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

/// backend :(
    
void movement(int x, int y)
{
    x = 130 + 160 * (x - 1);
    y = 130 + 160 * (y - 1);
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
                if (OKMatrix(new_y - 160, new_x) == 1)
                {
                    new_y -= 160;
                    while (OKMatrix(new_y, new_x))
                        new_y -= 160;
                }
                break;
            case 's':
                if (OKMatrix(new_y + 160, new_x) == 1)
                {
                    new_y += 160;
                    while (OKMatrix(new_y, new_x))
                        new_y += 160;
                }
                break;
            case 'a':
                if (OKMatrix(new_y , new_x - 160) == 1)
                {
                    new_x -= 160;
                    while (OKMatrix(new_y, new_x))
                        new_x -= 160;
                }
                break;
            case 'd':
                if (OKMatrix(new_y , new_x + 160) == 1)
                {
                    new_x += 160;
                    while (OKMatrix(new_y, new_x))
                        new_x += 160;
                }
                break;
            }
            // Check if the new position is within the playfield and is !! possible !!
            cout << endl
                 << (new_y - 130) / 160 + 1 << ' ' << (new_x - 130) / 160 + 1 << ' ' << OKMatrix(new_y, new_x);
            if (new_x >= 130 && new_x <= 780 && new_y >= 130 && new_y <= 780)
            {
                // Update the position
                if (x != new_x || y != new_y)
                {
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

/*
class MatrixGame {
public:
    MatrixGame(int rows, int cols) : rows(rows), cols(cols), elementRow(0), elementCol(0) {
        initializeMatrix();
        placeObstacles();
    }


    void runGame() {
        while (true) {
            displayMatrix();
            char direction;
            cout << "Enter direction (U/D/L/R to move, Q to quit): ";
            cin >> direction;


            if (direction == 'Q' || direction == 'q') {
                break;
            }


            jumpElement(direction);


            if (isElementOutOfBounds() || hasCollidedWithObstacle()) {
                cout << "Game over. Element is out of bounds or collided with an obstacle.\n";
                break;
            }
        }
    }


private:
    int rows;
    int cols;
    int elementRow;
    int elementCol;
    vector<vector<char>> matrix; // 'O' for obstacle, 'E' for element, '.' for empty space


    void initializeMatrix() {
        matrix.resize(rows, vector<char>(cols, '.'));
    }


    void placeObstacles() {
        // Place some obstacles randomly
        const int obstacleCount = rows * cols / 10;
        for (int i = 0; i < obstacleCount; ++i) {
            int obstacleRow, obstacleCol;
            do {
                obstacleRow = rand() % rows;
                obstacleCol = rand() % cols;
            } while (matrix[obstacleRow][obstacleCol] != '.');
            matrix[obstacleRow][obstacleCol] = 'O';
        }


        // Place the element at the top-left corner
        matrix[elementRow][elementCol] = 'E';
    }


    void displayMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }


    void jumpElement(char direction) {
        // Clear the current position of the element
        matrix[elementRow][elementCol] = '.';


        // Jump the element in the specified direction
        switch (direction) {
            case 'U':
            case 'u':
                elementRow = max(0, elementRow - 1);
                break;
            case 'D':
            case 'd':
                elementRow = min(rows - 1, elementRow + 1);
                break;
            case 'L':
            case 'l':
                elementCol = max(0, elementCol - 1);
                break;
            case 'R':
            case 'r':
                elementCol = min(cols - 1, elementCol + 1);
                break;
            default:
                cout << "Invalid direction. Please enter U, D, L, R, or Q.\n";
        }


        // Place the element in the new position
        matrix[elementRow][elementCol] = 'E';
    }


    bool isElementOutOfBounds() {
        // Check if the element is out of bounds
        return (elementRow < 0 || elementRow >= rows || elementCol < 0 || elementCol >= cols);
    }


    bool hasCollidedWithObstacle() {
        // Check if the element has collided with an obstacle
        return (matrix[elementRow][elementCol] == 'O');
    }
};
*/

void lvl1()
{
    board();
    mushroom(2, 1);     ///coordonatele sunt y, x, nu x, y for some odd fucking reason
    mushroom(3, 1);
    mushroom(4, 2);
    matrix();
    movement(4, 3);
}

int main()
{
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; // static file
    startscreen();
    lvl1();
    closegraph();
    return 0;
}