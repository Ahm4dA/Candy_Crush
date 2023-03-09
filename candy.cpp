#include <iostream>
#include "mygraphics.h"

using namespace std;

void orange_candy(int x, int y, int size) {
	myEllipse(x - size, y - size, x + (size / 2), y + 2 * size, RGB(242, 97, 24), RGB(255, 116, 46));
}
void blue_candy(int x, int y, int size) {
	myEllipse(x - size, y - size, x + size, y + size, RGB(34, 64, 199), RGB(34, 64, 199));
}
void green_candy(int x, int y, int size) {
	myRect(x - size, y - size, x + size, y + size, RGB(34, 199, 64), RGB(34, 199, 64));
}
void yellow_candy(int x, int y, int size) {

	y -= size / 2;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 255, 0), RGB(255, 255, 0));
	y += size;
	myRect(x - size, y - size, x + size, y, RGB(255, 255, 0), RGB(255, 255, 0));
}
void red_candy(int x, int y, int size) {
	size *= 0.6;
	myRect(x - size, y - size, x + size, y + 2 * size, RGB(255, 0, 0), RGB(255, 0, 0));
	y -= size;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(255, 0, 0));
	y += 3 * size;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(255, 0, 0));
}

void orange_candy_stripped(int x, int y, int size) {
	size *= 0.6;
	myEllipse(x - size, y - size, x + size, y + 3 * size, RGB(242, 97, 24), RGB(0, 0, 0));
	size -= size / 2;
	myEllipse(x - size, y - size, x + size, y + 4.5 * size, RGB(242, 97, 24), RGB(0, 0, 0));
}
void blue_candy_stripped(int x, int y, int size) {
	myEllipse(x - size, y - size, x + size, y + size, RGB(34, 64, 199), RGB(0, 0, 0));
	size /= 2;
	myEllipse(x - size, y - size, x + size, y + size, RGB(34, 64, 199), RGB(0, 0, 0));
}
void green_candy_stripped(int x, int y, int size) {
	myRect(x - size, y - size, x + size, y + size, RGB(34, 199, 64), RGB(0, 0, 0));
	myLine(x - size, y, x + size, y, RGB(34, 199, 64));
	y -= size / 2;
	myLine(x - size, y, x + size, y, RGB(34, 199, 64));
	y += size;
	myLine(x - size, y, x + size, y, RGB(34, 199, 64));
}
void yellow_candy_stripped(int x, int y, int size) {

	y -= size / 2;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 255, 0), RGB(0, 0, 0));
	y += size;
	myRect(x - size, y - size, x + size, y, RGB(255, 255, 0), RGB(0, 0, 0));
}
void red_candy_stripped(int x, int y, int size) {
	size *= 0.6;
	myRect(x - size, y - size, x + size, y + 2 * size, RGB(255, 0, 0), RGB(0, 0, 0));
	y -= size;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(0, 0, 0));
	y += 3 * size;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(0, 0, 0));
}


void orange_candy_wrapped(int x, int y, int size) {
	size += size / 5;
	myRect(x - size, y - size, x + (size / 2), y + 2 * size, RGB(79, 86, 94), RGB(79, 86, 94));
	size -= size / 5;
	myEllipse(x - size, y - size, x + (size / 2), y + 2 * size, RGB(242, 97, 24), RGB(255, 116, 46));
}
void blue_candy_wrapped(int x, int y, int size) {
	size += size / 5;
	myRect(x - size, y - size, x + size, y + size, RGB(79, 86, 94), RGB(79, 86, 94));
	size -= size / 5;
	myEllipse(x - size, y - size, x + size, y + size, RGB(34, 64, 199), RGB(34, 64, 199));
}
void green_candy_wrapped(int x, int y, int size) {
	size += size / 3;
	myRect(x - size, y - size, x + size, y + size, RGB(79, 86, 94), RGB(79, 86, 94));
	size -= size / 3;
	myRect(x - size, y - size, x + size, y + size, RGB(34, 199, 64), RGB(34, 199, 64));
}
void yellow_candy_wrapped(int x, int y, int size) {
	size += size / 3;
	myRect(x - size, y - size - size / 5, x + size, y + size - size / 5, RGB(79, 86, 94), RGB(79, 86, 94));
	size -= size / 3;
	y -= size / 2;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 255, 0), RGB(255, 255, 0));
	y += size;
	myRect(x - size, y - size, x + size, y, RGB(255, 255, 0), RGB(255, 255, 0));
}
void red_candy_wrapped(int x, int y, int size) {
	size += size / 3;
	myRect(x - size * 0.6, y - size, x + size * 0.6, y + size + size / 3, RGB(79, 86, 94), RGB(79, 86, 94));
	size -= size / 3;
	size *= 0.6;
	myRect(x - size, y - size, x + size, y + 2 * size, RGB(255, 0, 0), RGB(255, 0, 0));
	y -= size;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(255, 0, 0));
	y += 3 * size;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(255, 0, 0));
}

void cookie(int x, int y, int size) {
	size *= 1.3;
	myEllipse(x - size, y - size, x + size, y + size, RGB(120, 65, 48), RGB(120, 65, 48));
	size -= size / 5;
	myEllipse(x - size, y - size, x + size, y + size, RGB(34, 64, 199), RGB(34, 64, 199));
	size -= size / 4;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 255, 0), RGB(255, 255, 0));
	size -= size / 4;
	myEllipse(x - size, y - size, x + size, y + size, RGB(255, 0, 0), RGB(255, 0, 0));
	size -= size / 3;
	myEllipse(x - size, y - size, x + size, y + size, RGB(242, 97, 24), RGB(242, 97, 24));
	size -= size / 2;
	myEllipse(x - size, y - size, x + size, y + size, RGB(120, 65, 48), RGB(120, 65, 48));
}

void checkcandy(int num, int x, int y, int size)
{
	Sleep(1);
	switch (num)
	{
	case 1:
	{
		red_candy(x, y, size);
	}
	break;
	case 2:
	{
		yellow_candy(x, y, size);
	}
	break;
	case 3:

	{
		green_candy(x, y, size);
	}
	break;
	case 4:
	{
		blue_candy(x, y, size);
	}
	break;
	case 5:
	{
		orange_candy(x, y, size);
	}
	break;
	case 11:
	{
		red_candy_stripped(x, y, size);
	}
	break;
	case 12:
	{
		yellow_candy_stripped(x, y, size);
	}
	break;
	case 13:
	{
		green_candy_stripped(x, y, size);
	}
	break;
	case 14:
	{
		blue_candy_stripped(x, y, size);
	}
	break;
	case 15:
	{
		orange_candy_stripped(x, y, size);
	}
	break;
	case 21:
	{
		red_candy_stripped(x, y, size);
	}
	break;
	case 22:
	{
		yellow_candy_stripped(x, y, size);
	}
	break;
	case 23:
	{
		green_candy_stripped(x, y, size);
	}
	case 24:
	{
		blue_candy_stripped(x, y, size);
	}
	break;
	case 25:
	{
		orange_candy_stripped(x, y, size);
	}
	break;
	case 31:
	{
		red_candy_wrapped(x, y, size);
	}
	break;
	case 32:
	{
		yellow_candy_wrapped(x, y, size);
	}
	break;
	case 33:
	{
		green_candy_wrapped(x, y, size);
	}
	case 34:
	{
		blue_candy_wrapped(x, y, size);
	}
	break;
	case 35:
	{
		orange_candy_wrapped(x, y, size);
	}
	break;
	case 40:
	{
		cookie(x, y, size);
	}
	break;
	}
}
//int main() {
//
//	blue_candy_stripped(50, 50, 20);
//	orange_candy_stripped(150, 50, 20);
//	green_candy_stripped(250, 50, 20);
//	yellow_candy_stripped(350, 50, 20);
//	red_candy_stripped(450, 50, 20);
//	blue_candy(50, 150, 20);
//	orange_candy(150, 150, 20);
//	green_candy(250, 150, 20);
//	yellow_candy(350, 150, 20);
//	red_candy(450, 150, 20);
//
//	cin.get();
//	return 0;
//}