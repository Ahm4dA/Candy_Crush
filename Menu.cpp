#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"

using namespace std;

void lettersnNumbers(char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
    x1 += 5;
    x2 -= 5;
    y1 += 5;
    y2 -= 5;
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;

    if (chr == 'A') {
        myLine(mid_x, y1, x1, y2, RGB(R, G, B));
        myLine(mid_x, y1, x2, y2, RGB(R, G, B));
        myLine(x1 + 2, mid_y + size / 2, x2 - 3, mid_y + size / 2, RGB(R, G, B));
    }
    else if (chr == 'B') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, mid_x + size / 4, y1 + size / 8, RGB(R, G, B));
        myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, mid_x, mid_y, RGB(R, G, B));
        myLine(mid_x, mid_y, x2, mid_y + size / 4, RGB(R, G, B));
        myLine(x2, mid_y + size / 4, mid_x + size / 8, y2, RGB(R, G, B));
        myLine(mid_x + size / 8, y2, x1, y2, RGB(R, G, B));
    }
    else if (chr == 'C') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x2, y1 + size / 4, RGB(R, G, B));
        myLine(x2, y2, x2, y2 - size / 4, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'D') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, mid_x + size / 4, y1 + size / 4, RGB(R, G, B));
        myLine(mid_x + size / 4, y1 + size / 4, mid_x + size / 4, y2 - size / 4, RGB(R, G, B));
        myLine(mid_x + size / 4, y2 - size / 4, x1, y2, RGB(R, G, B));
    }
    else if (chr == 'E') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'F') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
    }
    else if (chr == 'G') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x2, y1 + size / 4, RGB(R, G, B));
        myLine(x2, y2, x2, y2 - size / 2, RGB(R, G, B));
        myLine(x2, y2 - size / 2, mid_x, y2 - size / 2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'H') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
    }
    else if (chr == 'I') {
        myLine(mid_x, y1, mid_x, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'J') {
        myLine(x2, y1, x2, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y2, x1, y2, RGB(R, G, B));
        myLine(x1, y2, x1, y2 - size / 2, RGB(R, G, B));
    }
    else if (chr == 'K') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, mid_y, x2, y1, RGB(R, G, B));
        myLine(x1, mid_y, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'L') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'M') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, mid_x, mid_y, RGB(R, G, B));
        myLine(mid_x, mid_y, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'N') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y2, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'O') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'P') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, mid_x + size / 4, y1 + size / 8, RGB(R, G, B));
        myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, mid_x, mid_y, RGB(R, G, B));

    }
    else if (chr == 'Q') {
        myLine(x1, y1, x1, y2 - 5, RGB(R, G, B));
        myLine(x1, y1, mid_x + 3, y1, RGB(R, G, B));
        myLine(mid_x + 3, y1, mid_x + 3, y2 - 5, RGB(R, G, B));
        myLine(x1, y2 - 5, mid_x + 3, y2 - 5, RGB(R, G, B));
        myLine(mid_x - 2, mid_y, mid_x + 3, y2 - 5, RGB(R, G, B));
        myLine(mid_x + 3, y2 - 5, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'R') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y1, mid_x + size / 4, y1 + size / 8, RGB(R, G, B));
        myLine(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, mid_x, mid_y, RGB(R, G, B));
        myLine(mid_x, mid_y, x2, y2, RGB(R, G, B));
    }
    else if (chr == 'S') {
        myLine(mid_x, y1, x2, y1 + size / 2, RGB(R, G, B));
        myLine(mid_x, y1, x1, y1 + size / 2, RGB(R, G, B));
        myLine(x1, y1 + size / 2, x2, y2 - size / 2, RGB(R, G, B));
        myLine(x2, y2 - size / 2, mid_x, y2, RGB(R, G, B));
        myLine(mid_x, y2, x1, y2 - size / 2, RGB(R, G, B));
    }
    else if (chr == 'T') {
        myLine(mid_x, y1, mid_x, y2, RGB(R, G, B));
        myLine(x1, y1, x2, y1, RGB(R, G, B));
    }
    else if (chr == 'U') {
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));

    }
    else if (chr == 'V') {
        myLine(x1, y1, mid_x, y2, RGB(R, G, B));
        myLine(mid_x, y2, x2, y1, RGB(R, G, B));
    }
    else if (chr == 'W') {
        myLine(x1, y1, mid_x - size / 8, y2, RGB(R, G, B));
        myLine(mid_x - size / 8, y2, mid_x, mid_y, RGB(R, G, B));
        myLine(mid_x, mid_y, mid_x + size / 8, y2, RGB(R, G, B));
        myLine(mid_x + size / 8, y2, x2, y1, RGB(R, G, B));
    }
    else if (chr == 'X') {
        myLine(x1, y1, x2, y2, RGB(R, G, B));
        myLine(x2, y1, x1, y2, RGB(R, G, B));

    }
    else if (chr == 'Y') {
        myLine(x1, y1, mid_x, mid_y, RGB(R, G, B));
        myLine(x2, y1, x1, y2, RGB(R, G, B));
    }
    else if (chr == 'Z') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x1, y2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == '.') {
    myRect(x2, y2 - size / 8, mid_x + size / 4, y2, RGB(R, G, B), RGB(0, 0, 0));
    }
    else if (chr == ',') {
        myRect(x2, y2 - size / 3, mid_x + size / 4, y2 - size / 6, RGB(R, G, B), RGB(0, 0, 0));
        myLine(x2, y2 - size / 3, x2, y2, R);
        myLine(x2, y2, mid_x + size / 4, y2, R);
    }
    else if (chr == '!') {
        myRect(mid_x - size / 8, y1, mid_x - 1, y2 - size / 3, RGB(R, G, B), RGB(0, 0, 0));
        myRect(mid_x - size / 8, y2 - size / 8, mid_x, y2, RGB(R, G, B), RGB(0, 0, 0));
    }
    else if (chr == ':') {
        myRect(x2, y2 - 20, mid_x + size / 4, y2 - 16, RGB(R, G, B), RGB(0, 0, 0));
        myRect(x2, y2 - 4, mid_x + size / 4, y2, RGB(R, G, B), RGB(0, 0, 0));
    }
    else if (chr == '0') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
        myLine(x2, y1, x1, y2, RGB(R, G, B));
    }
    else if (chr == '1') {
        myLine(x1, mid_y - size / 2, mid_x, y1, RGB(R, G, B));
        myLine(mid_x, y1, mid_x, y2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == '2') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x2, mid_y, RGB(R, G, B));
        myLine(x2, mid_y, x1, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, x1, y2, RGB(R, G, B));
        myLine(x1, y2, x2, y2, RGB(R, G, B));
    }
    else if (chr == '3') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x2, mid_y, RGB(R, G, B));
        myLine(x2, mid_y, x1, mid_y, RGB(R, G, B));
        myLine(x2, mid_y, x2, y2, RGB(R, G, B));
        myLine(x2, y2, x1, y2, RGB(R, G, B));
    }
    else if (chr == '4') {
        myLine(x1, y1, x1, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
        myLine(mid_x + size / 6, y1, mid_x + size / 6, y2, RGB(R, G, B));
    }
    else if (chr == '5') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y1, x1, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
        myLine(x2, mid_y, x2, y2, RGB(R, G, B));
        myLine(x2, y2, x1, y2, RGB(R, G, B));
    }
    else if (chr == '6') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
        myLine(x2, mid_y, x2, y2, RGB(R, G, B));
        myLine(x2, y2, x1, y2, RGB(R, G, B));
    }
    else if (chr == '7') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
    }
    else if (chr == '8') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y1, x1, y2, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
        myLine(x2, y2, x1, y2, RGB(R, G, B));
    }
    else if (chr == '9') {
        myLine(x1, y1, x2, y1, RGB(R, G, B));
        myLine(x1, y1, x1, mid_y, RGB(R, G, B));
        myLine(x1, mid_y, x2, mid_y, RGB(R, G, B));
        myLine(x2, y1, x2, y2, RGB(R, G, B));
        myLine(x2, y2, x1, y2, RGB(R, G, B));
    }
    else if (chr == '-')
        myRect(x1 - 5, y1 - 5, x2 + 5, y2 + 5, RGB(R, G, B), RGB(0, 0, 0));
}
//This Function Converts a Cstring to uppercase
void Capitalizer(char text[]) {
    for (int i = 0; i < strlen(text); i++)
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] -= 32;
}
//This Function to print Text on Screen
void drawText(int size, int start_x, int start_y, int R, int G, int B, char text[], bool isNum = false, int num = 0) {
    int idx = 0;
    int idx_x = 0;
    int idx_y = 0;
    int x1, x2, y1, y2;
    int digit_count = 0;
    int len = strlen(text);
    char temp[100];

    strcpy_s(temp, text);
    //If this function takes a number to print then he converts the number into atring using following loop
    if (isNum == true) {
        int reverse_num = 0;
        int i;

        for (; num > 0; num /= 10, digit_count++)
            reverse_num = (reverse_num * 10) + num % 10;

        for (i = len; i - len < digit_count; i++, reverse_num /= 10)
            temp[i] = (reverse_num % 10) + 48;

        temp[i] = '\0';
    }
    //Now the cstring is converted into upper case letters
    Capitalizer(temp);
    //This loop prints each individual letter on the screen
    for (idx = 0; idx < strlen(temp); idx++)
    {
        x1 = start_x + size * idx_x;
        x2 = start_x + size * (idx_x + 1);

        if (x2 > 1585 - size) {
            idx_y++;
            idx_x = 0;
            x1 = start_x + size * idx_x;
            x2 = start_x + size * (idx_x + 1);

        }

        y1 = start_y + 2 * size * idx_y;
        y2 = start_y + 2 * size * (idx_y + 1);
        lettersnNumbers(temp[idx], x1, x2, y1, y2, size, RGB(R, G, B));
        idx_x++;
    }

}

void GiveNumASCII(int &num)
{
    int zero = 48;
    if (num == 0)
    {
        num = zero;
    }
    else if (num == 1)
    {
        num += zero;
    }
    else if (num == 2)
    {
        num += zero;
    }
    else if (num == 3)
    {
        num += zero;
    }
    else if (num == 4)
    {
        num += zero;
    }
    else if (num == 5)
    {
        num += zero;
    }
    else if (num == 6)
    {
        num += zero;
    }
    else if (num == 7)
    {
        num += zero;
    }
    else if (num == 8)
    {
        num += zero;
    }
    else if (num == 9)
    {
        num += zero;
    }
}
void DrawCursorMenu(int x, int y)
{

	myLine(x + 1, y + 1, x + 599, y, RGB(255, 0, 0));
	myLine(x + 2, y + 2, x + 598, y, RGB(255, 0, 0));
	myLine(x + 1, y + 119, x + 599, y + 119, RGB(255, 0, 0));
	myLine(x + 2, y + 118, x + 598, y + 118, RGB(255, 0, 0));
	myLine(x + 1, y + 1, x + 1, y + 119, RGB(255, 0, 0));
	myLine(x + 2, y + 2, x + 2, y + 118, RGB(255, 0, 0));
	myLine(x + 599, y + 1, x + 599, y + 119, RGB(255, 0, 0));
	myLine(x + 598, y + 2, x + 598, y + 118, RGB(255, 0, 0));
	myLine(x + 3, y + 3, x + 597, y, RGB(255, 0, 0));
	myLine(x + 4, y + 4, x + 596, y, RGB(255, 0, 0));
	myLine(x + 3, y + 117, x + 597, y + 117, RGB(255, 0, 0));
	myLine(x + 4, y + 116, x + 596, y + 116, RGB(255, 0, 0));
	myLine(x + 3, y + 3, x + 3, y + 117, RGB(255, 0, 0));
	myLine(x + 4, y + 4, x + 4, y + 116, RGB(255, 0, 0));
	myLine(x + 597, y + 3, x + 597, y + 117, RGB(255, 0, 0));
	myLine(x + 596, y + 4, x + 596, y + 116, RGB(255, 0, 0));

}

void DrawCursorBMenu(int x, int y)
{

	myLine(x + 1, y + 1, x + 599, y, RGB(0, 0, 0));
	myLine(x + 2, y + 2, x + 598, y, RGB(0, 0, 0));
	myLine(x + 1, y + 119, x + 599, y + 119, RGB(0, 0, 0));
	myLine(x + 2, y + 118, x + 598, y + 118, RGB(0, 0, 0));
	myLine(x + 1, y + 1, x + 1, y + 119, RGB(0, 0, 0));
	myLine(x + 2, y + 2, x + 2, y + 118, RGB(0, 0, 0));
	myLine(x + 599, y + 1, x + 599, y + 119, RGB(0, 0, 0));
	myLine(x + 598, y + 2, x + 598, y + 118, RGB(0, 0, 0));
	myLine(x + 3, y + 3, x + 597, y, RGB(0, 0, 0));
	myLine(x + 4, y + 4, x + 596, y, RGB(0, 0, 0));
	myLine(x + 3, y + 117, x + 597, y + 117, RGB(0, 0, 0));
	myLine(x + 4, y + 116, x + 596, y + 116, RGB(0, 0, 0));
	myLine(x + 3, y + 3, x + 3, y + 117, RGB(0, 0, 0));
	myLine(x + 4, y + 4, x + 4, y + 116, RGB(0, 0, 0));
	myLine(x + 597, y + 3, x + 597, y + 117, RGB(0, 0, 0));
	myLine(x + 596, y + 4, x + 596, y + 116, RGB(0, 0, 0));

}

void BoundaryMenu()
{
    int x = 70, y = 70;

    myLine(x, y, x + 1690, y, RGB(255, 255, 255));
    myLine(x + 1690, y, x + 1690, y + 690, RGB(255, 255, 255));
    myLine(x, y, x, y + 690, RGB(255, 255, 255));
    myLine(x, y + 690, x + 1690, y + 690, RGB(255, 255, 255));

}

void LoadB()
{
	int x = 500, y = 250;

	myLine(x, y, x + 600, y, RGB(255, 255, 255));
	myLine(x + 600, y, x + 600, y + 120, RGB(255, 255, 255));
	myLine(x, y, x, y + 120, RGB(255, 255, 255));
	myLine(x, y + 120, x + 600, y + 120, RGB(255, 255, 255));
}

void LoadT()
{
    int x1 = 670;
    int y1 = 260;
    lettersnNumbers('L', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('O', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('A', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('D', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);

}

void NewGameB()
{
	int x = 500, y = 430;

	myLine(x, y, x + 600, y, RGB(255, 255, 255));
	myLine(x + 600, y, x + 600, y + 120, RGB(255, 255, 255));
	myLine(x, y, x, y + 120, RGB(255, 255, 255));
	myLine(x, y + 120, x + 600, y + 120, RGB(255, 255, 255));
}

void NewGameT()
{
    int x1 = 510;
    int y1 = 440;
    lettersnNumbers('S', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('T', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('A', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('R', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('T', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    x1 += 60;
    lettersnNumbers('N', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('E', x1, x1 + 50, y1, y1 + 100, 7, 255, 0, 0);
    x1 += 60;
    lettersnNumbers('W', x1, x1 + 70, y1, y1 + 100, 140, 255, 0, 0);
}

int Menu()
{
	Maximized();
	PlaceCursor(0, 40);

	Sleep(100);
	BoundaryMenu();
	LoadB();
    LoadT();
	NewGameB();
    NewGameT();
    DrawCursorMenu(500, 250);
	
    int num = 1;
	int key = 0;
	while (key != 13)
	{
		bool flag = 1;
		key = CheckWhichKeyPressed(flag, 100);

        if (key == 38)
        {
            DrawCursorMenu(500, 250);
            DrawCursorBMenu(500, 430);
            num = 1;
        }
        else if (key == 40)
        {
            DrawCursorMenu(500, 430);
            DrawCursorBMenu(500, 250);
            num = 2;
        }
	}
    return num;
 
}