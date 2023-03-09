#include <iostream>
#include "myconsole.h"
#include "mygraphics.h"
#include "Menu.h"

using namespace std;


void choice(int c, int& player, int& goal)
{
    if (c == 1)
    {
        player += 30;
        goal -= 30;
    }
    else if (c == 2)
    {
        player += 30;
        goal -= 30;
    }
    else if (c == 3)
    {
        player += 40;
        goal -= 40;
    }
    else if (c == 4)
    {
        player += 50;
        goal -= 50;
    }
    else if (c == 5)
    {
        player += 60;
        goal -= 60;
    }
    else if (c == 11 || c == 21)
    {
        player += 80;
        goal -= 80;
    }
    else if (c == 12 || c == 22)
    {
        player += 80;
        goal -= 80;
    }
    else if (c == 13 || c == 23)
    {
        player += 80;
        goal -= 80;
    }
    else if (c == 14 || c == 24)
    {
        player += 80;
        goal -= 80;
    }
    else if (c == 15 || c == 25)
    {
        player += 80;
        goal -= 80;
    }
    else if (c == 31)
    {
        player += 90;
        goal -= 390;
    }
    else if (c == 32)
    {
        player += 90;
        goal -= 90;
    }
    else if (c == 33)
    {
        player += 90;
        goal -= 90;
    }
    else if (c == 34)
    {
        player += 90;
        goal -= 90;
    }
    else if (c == 35)
    {
        player += 90;
        goal -= 90;
    }
    else if (c == 40)
    {
        player += 100;
        goal -= 100;
    }

    if (goal < 0)
    {
        goal = 0;
    }
}

void PrintMovesandScore(int CandyNum, int &score,int &ToScore, int &MovesLeft)
{
    choice(CandyNum, score, ToScore);
    Maximized();
    PlaceCursor(0, 40);
    Sleep(100);
    int x1 = 900, y1 = 200;
    int size = 10;
    // Below one prints scored
    lettersnNumbers('S', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('C', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('O', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('R', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('E', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers(':', x1, x1 + 50, y1 - 30, y1 + 70, size, 255, 255, 0);
    x1 += 50;

    // Below one prints scored

    int count = 0;
    int num = score;
    int junk = num;
    while (junk > 0)
    {
        junk /= 10;
        count++;
    }
    while (count != 0)
    {
        int temp = num % 10;
        GiveNumASCII(temp);

        lettersnNumbers(temp, x1 + (50 * count), x1 + (50 * (count + 1)), y1, y1 + 100, size, 255, 255, 0);
        num /= 10;
        count--;
    }

    // below one prints score left
    y1 += 110;
    x1 = 900;
    lettersnNumbers('S', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('C', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('O', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('R', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('E', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    x1 += 50;
    lettersnNumbers('L', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('E', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('F', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('T', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers(':', x1, x1 + 50, y1 - 30, y1 + 70, size, 255, 255, 0);
    x1 += 50;

    count = 0;
    num = ToScore;
    junk = num;
    while (junk > 0)
    {
        junk /= 10;
        count++;
    }
    while (count != 0)
    {
        int temp = num % 10;
        GiveNumASCII(temp);

        lettersnNumbers(temp, x1 + (50 * count), x1 + (50 * (count + 1)), y1, y1 + 100, size, 255, 255, 0);
        num /= 10;
        count--;
    }

    y1 += 110;
    x1 = 900;
    lettersnNumbers('M', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('O', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('V', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('E', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('S', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    x1 += 50;
    lettersnNumbers('L', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('E', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('F', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers('T', x1, x1 + 50, y1, y1 + 100, size, 255, 255, 0);
    x1 += 50;
    lettersnNumbers(':', x1, x1 + 50, y1 - 30, y1 + 70, size, 255, 255, 0);
    x1 += 50;

    count = 0;
    num = MovesLeft;
    junk = num;
    while (junk > 0)
    {
        junk /= 10;
        count++;
    }
    while (count != 0)
    {
        int temp = num % 10;
        GiveNumASCII(temp);

        lettersnNumbers(temp, x1 + (50 * count), x1 + (50 * (count + 1)), y1, y1 + 100, size, 255, 255, 0);
        num /= 10;
        count--;
    }


}