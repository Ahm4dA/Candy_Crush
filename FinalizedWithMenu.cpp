#include <iostream>
#include "myconsole.h"
#include "mygraphics.h"
#include "candy.h"
#include <fstream>
#include "Menu.h"
#include "MovesAndScore.h"

using namespace std;

int goal = 500;
int player = 0;
int moves = 20;

void Boundary()
{
	int x = 70, y = 70;

	myLine(x, y, x + 1690, y, RGB(255, 255, 255));
	myLine(x + 1690, y, x + 1690, y + 690, RGB(255, 255, 255));
	myLine(x, y, x, y + 690, RGB(255, 255, 255));
	myLine(x, y + 690, x + 1690, y + 690, RGB(255, 255, 255));

}

//void UpdateArray(int arr[9][9], int& x, int& y, int key);

bool checkwrappedandupdate(int arr[9][9], int y, int x);

bool checkstriped(int arr[9][9], int y, int x, int key);

bool checkcookie(int arr[9][9], int y, int x);

void checkwrapped(int arr[9][9], int x, int y, int key);

void checkforvertical(int arr[9][9], int x, int y, int key);

void checkforhorizontal(int arr[9][9], int x, int y, int key);

void checkifcookie(int arr[9][9], int x, int y, int key);

void PrintUpdatedArray(int arr[9][9], int x, int y);

void UpdateCursor(int& x, int& y, int key);

bool CheckIfCandyBreak(int arr[9][9], int x, int y, int key);

void DrawCursor(int x, int y)
{
	x = 100 + (x * 70);
	y = 100 + (y * 70);

	myLine(x + 1, y + 1, x + 69, y, RGB(255, 0, 0));
	myLine(x + 2, y + 2, x + 68, y, RGB(255, 0, 0));
	myLine(x + 1, y + 69, x + 69, y + 69, RGB(255, 0, 0));
	myLine(x + 2, y + 68, x + 68, y + 68, RGB(255, 0, 0));
	myLine(x + 1, y + 1, x + 1, y + 69, RGB(255, 0, 0));
	myLine(x + 2, y + 2, x + 2, y + 68, RGB(255, 0, 0));
	myLine(x + 69, y + 1, x + 69, y + 69, RGB(255, 0, 0));
	myLine(x + 68, y + 2, x + 68, y + 68, RGB(255, 0, 0));
	myLine(x + 3, y + 3, x + 67, y, RGB(255, 0, 0));
	myLine(x + 4, y + 4, x + 66, y, RGB(255, 0, 0));
	myLine(x + 3, y + 67, x + 67, y + 67, RGB(255, 0, 0));
	myLine(x + 4, y + 66, x + 66, y + 66, RGB(255, 0, 0));
	myLine(x + 3, y + 3, x + 3, y + 67, RGB(255, 0, 0));
	myLine(x + 4, y + 4, x + 4, y + 66, RGB(255, 0, 0));
	myLine(x + 67, y + 3, x + 67, y + 67, RGB(255, 0, 0));
	myLine(x + 66, y + 4, x + 66, y + 66, RGB(255, 0, 0));
}

void DrawCursorB(int x, int y)
{
	x = 100 + (x * 70);
	y = 100 + (y * 70);

	myLine(x + 1, y + 1, x + 69, y, RGB(0, 0, 0));
	myLine(x + 2, y + 2, x + 68, y, RGB(0, 0, 0));
	myLine(x + 1, y + 69, x + 69, y + 69, RGB(0, 0, 0));
	myLine(x + 2, y + 68, x + 68, y + 68, RGB(0, 0, 0));
	myLine(x + 1, y + 1, x + 1, y + 69, RGB(0, 0, 0));
	myLine(x + 2, y + 2, x + 2, y + 68, RGB(0, 0, 0));
	myLine(x + 69, y + 1, x + 69, y + 69, RGB(0, 0, 0));
	myLine(x + 68, y + 2, x + 68, y + 68, RGB(0, 0, 0));

	myLine(x + 3, y + 3, x + 67, y, RGB(0, 0, 0));
	myLine(x + 4, y + 4, x + 66, y, RGB(0, 0, 0));
	myLine(x + 3, y + 67, x + 67, y + 67, RGB(0, 0, 0));
	myLine(x + 4, y + 66, x + 66, y + 66, RGB(0, 0, 0));
	myLine(x + 3, y + 3, x + 3, y + 67, RGB(0, 0, 0));
	myLine(x + 4, y + 4, x + 4, y + 66, RGB(0, 0, 0));
	myLine(x + 67, y + 3, x + 67, y + 67, RGB(0, 0, 0));
	myLine(x + 66, y + 4, x + 66, y + 66, RGB(0, 0, 0));

}

void StartNewCandies(int arr[9][9])
{

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int temp = (rand() % 5) + 1;

			arr[i][j] = temp;
		}
	}
}


void LoadGame(int arr[9][9])
{
	ifstream fin;

	fin.open("SavedGame.txt");

	fin >> player >> goal >> moves;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fin >> arr[i][j];
		}
	}

	fin.close();
}

void SaveGame(int arr[9][9])
{
	ofstream fout;

	fout.open("SavedGame.txt");

	fout << player << "\t" << goal << "\t" << moves << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fout << arr[i][j] << "\t";
		}
		fout << endl;
	}

	fout.close();
}

int main()
{
	int arr[9][9];

	int JunkNumforMenu = Menu();
	if (JunkNumforMenu == 1)
	{
		LoadGame(arr);
	}
	else if (JunkNumforMenu == 2)
	{
		StartNewCandies(arr);
	}
	ClearScreen();

	int key = 0;
	int x = 100, y = 100;
	bool flag = 1;
	Maximized();
	PlaceCursor(0, 40);

	int l = 0, m = 0;
	Sleep(100);
	Boundary();
	PrintUpdatedArray(arr, x, y);
	DrawCursor(0, 0);
	PrintMovesandScore(0, player, goal, moves);
	int NumtoPrintScore = 0;
	while (key != ESCKEY)
	{
		key = CheckWhichKeyPressed(flag, 1000);
		if (key == 38 || key == 40 || key == 39 || key == 37)
		{
			PrintUpdatedArray(arr, 100, 100);
			UpdateCursor(l, m, key);
		}
		DrawCursor(l, m);

		if (key == 32)
		{
			NumtoPrintScore = arr[m][l];
			while (key != 38 && key != 40 && key != 39 && key != 37)
			{
				key = 0;
				key = CheckWhichKeyPressed(flag, 1000);
				if (key == 38 || key == 40 || key == 39 || key == 37)
				{
					int result = CheckIfCandyBreak(arr, l, m, key);
					if (result == 1)
					{
						moves = moves - 1;
						ClearScreen();

						Boundary();
						PrintUpdatedArray(arr, x, y);
						DrawCursor(l, m);
						PrintMovesandScore(NumtoPrintScore, player, goal, moves);
					}
				}
			}
		}
		flag = 1;
	}

	SaveGame(arr);
}

void PrintUpdatedArray(int arr[9][9], int x, int y)
{
	//Sleep(1);
	for (int i = 0; i <= 9; i++)
	{
		//Sleep(1);
		myLine(x, y, x + 630, y, RGB(255, 255, 255));
		y += 70;
	}
	y = 100;
	for (int i = 0; i <= 9; i++)
	{
		myLine(x, y, x, y + 630, RGB(255, 255, 255));
		x += 70;
	}
	x = 135, y = 135;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			checkcandy(arr[i][j], x, y, 12); // calling function to print candy
			x += 70; // x
		}
		y += 70;
		x = 135;
	}

}

bool checkwrappedandupdate(int arr[9][9], int y, int x)
{
	bool iswrapped = false;
	int count = 0;
	int variable = arr[y][x], i = 1, x2 = 0, x1 = 0, temp = 0;
	for (i = 1; i <= 2; i++)
	{
		count = 0;
		iswrapped = false;
		if (i == 1)
		{
			for (int j = 1; j <= 2; j++)
			{
				if (arr[y - j][x] == arr[y][x])
				{
					count++;
				}
				if (count == 2)
					iswrapped = true;
			}
			if (iswrapped)
			{
				for (x1 = 1; x1 <= 2; x1++)
				{
					if (arr[y][x] == arr[y][x - x1])
					{
						count++;
					}
				}
				if (count == 4)
					iswrapped = true;
				else
				{
					iswrapped = false;
					count = 2;
				}
				if (!iswrapped)
				{
					for (x2 = 1; x2 <= 2; x2++)
					{
						if (arr[y][x] == arr[y][x + x2])
						{
							count++;
						}
					}
				}
				if (count == 4)
					iswrapped = true;
				else
				{
					iswrapped = false;
					count = 2;
				}
			}
		}
		if (iswrapped && i == 1)
			break;
		/*if (i == 2)
		{
			for (int j = 1; j <= 2; j++)
			{
				if (arr[y - j][x] != arr[y][x])
				{
					iswrapped = false;
					break;
				}
			}
			if (iswrapped == true)
			{
				for (int j = 1; j <= 2; j++)
				{
					if (arr[y][x] != arr[y][x + j])
					{
						iswrapped = false;
						break;
					}
				}
			}
		}
		if (iswrapped && i == 2)
			break;
		if (i == 3)
		{
			for (int j = 1; j <= 2; j++)
			{
				if (arr[y + j][x] != arr[y][x])
				{
					iswrapped = false;
					break;
				}
			}
			if (iswrapped == true)
			{
				for (int j = 1; j <= 2; j++)
				{
					if (arr[y][x] != arr[y][x - j])
					{
						iswrapped = false;
						break;
					}
				}
			}
		}
		if (iswrapped && i == 3)
			break;
		if (i == 4)
		{
			for (int j = 1; j <= 2; j++)
			{
				if (arr[y + j][x] != arr[y][x])
				{
					iswrapped = false;
					break;
				}
			}
			if (iswrapped == true)
			{
				for (int j = 1; j <= 2; j++)
				{
					if (arr[y][x] != arr[y][x + j])
					{
						iswrapped = false;
						break;
					}
				}
			}
		}
		if (iswrapped == false)
			break;
	}
	if (iswrapped == true)
	{
		if (i == 1)
		{
			for (int j = 0; j <= 2; j++)
			{
				for (int k = y - j; k > 0; k--)
				{
					if (k != y || x - j != x)
						arr[k][x - j] = arr[k - 1][x - j];
				}
				arr[0][x] = (rand() % 5) + 1;
				if (x - j != x)
				{
					for (int k = y; k > 0; k--)
					{
						arr[k][x - j] = arr[k - 1][x - j];
					}
					arr[0][x - j] = (rand() % 5) + 1;
				}
			}
			arr[y][x] = variable + 30;
		}
		if (i == 2)
		{
			for (int j = 0; j <= 2; j++)
			{
				for (int k = y - j; k > 0; k--)
				{
					if (k != y || x + j != x)
						arr[k][x + j] = arr[k - 1][x + j];
				}
				arr[0][x] = (rand() % 5) + 1;
				if (x + j != x)
				{
					for (int k = y; k > 0; k--)
					{
						arr[k][x + j] = arr[k - 1][x + j];
					}
					arr[0][x + j] = (rand() % 5) + 1;
				}
			}
			arr[y][x] = variable + 30;

		}*/
		/*	if (i == 3)
			{
				for (int j = 2; j > 0; j--)
				{
					for (int k = y + 2; k > 0; k--)
					{
						arr[k][x] = arr[k - 1][x];
					}
					arr[0][x] = (rand() % 5) + 1;
					for (int k = y; k > 0; k--)
					{
						arr[k][x - j] = arr[k - 1][x - j];
					}
					arr[0][x - j] = (rand() % 5) + 1;
				}
				arr[y + 2][x] = variable + 30;
			}
			if (i == 4)
			{
				for (int j = 2; j > 0; j--)
				{
					for (int k = y + 2; k > 0; k--)
					{
						arr[k][x] = arr[k - 1][x];
					}
					arr[0][x] = (rand() % 5) + 1;
					for (int k = y; k > 0; k--)
					{
						arr[k][x + j] = arr[k - 1][x + j];
					}
					arr[0][x + j] = (rand() % 5) + 1;
				}
				arr[y + 2][x] = variable + 30;
			}

		}*/
		if (i == 2)
		{
			for (int i = 1; i <= 2; i++)
			{
				count = 0;
				iswrapped = false;
				if (i == 1)
				{
					for (int j = 1; j <= 2; j++)
					{
						if (arr[y + j][x] == arr[y][x])
						{
							count++;
						}
						if (count == 2)
							iswrapped = true;
					}
					if (iswrapped)
					{
						for (x1 = 1; x1 <= 2; x1++)
						{
							if (arr[y][x] == arr[y][x + x1])
							{
								count++;
							}
						}
						if (count == 4)
							iswrapped = true;
						else
						{
							iswrapped = false;
							count = 2;
						}
						if (!iswrapped)
						{
							for (x2 = 1; x2 <= 2; x2++)
							{
								if (arr[y][x] == arr[y][x - x2])
								{
									count++;
								}
							}
						}
						if (count == 4)
							iswrapped = true;
						else
						{
							iswrapped = false;
							count = 2;
						}
					}
				}
				if (iswrapped && i == 2)
					break;
			}
		}

	}
	if (iswrapped)
	{
		if (i == 1)
		{
			if (x1 > 1 && x2 < 1)
			{
				for (int a = 1; a <= 2; a++)
				{
					for (int h = y; h > 0; h--)
					{
						arr[h][x] = arr[h - 1][x];
					}

				}
				for (int f = 1; f < 3; f++)
				{
					for (int h = y; h > 0; h--)
					{
						arr[h][x - f] = arr[h - 1][x - f];
					}
				}
			}
			else if (x1 > 1 && x2 > 1)
			{
				for (int a = 1; a <= 2; a++)
				{
					for (int h = y; h > 0; h--)
					{
						arr[h][x] = arr[h - 1][x];
					}

				}
				for (int f = 1; f < 3; f++)
				{
					for (int h = y; h > 0; h--)
					{
						arr[h][x + f] = arr[h - 1][x + f];
					}
				}
			}
		}
		else if (i == 2)
		{
			if (x1 > 1 && x2 < 1)
			{
				for (int a = 1; a <= 2; a++)
				{
					for (int h = y + 2; h > 0; h--)
					{
						arr[h][x] = arr[h - 1][x];
					}

				}
				for (int f = 1; f < 3; f++)
				{
					for (int h = y; h > 0; h--)
					{
						arr[h][x - f] = arr[h - 1][x - f];
					}
				}
			}
			else if (x1 > 1 && x2 > 1)
			{
				for (int a = 1; a <= 2; a++)
				{
					for (int h = y + 2; h > 0; h--)
					{
						arr[h][x] = arr[h - 1][x];
					}

				}
				for (int f = 1; f < 3; f++)
				{
					for (int h = y; h > 0; h--)
					{
						arr[h][x + f] = arr[h - 1][x + f];
					}
				}
			}
		}
	}
	return iswrapped;
}

void UpdateCursor(int& x, int& y, int key)
{

	if (key != 0)
	{
		DrawCursorB(x, y);
	}
	/*
	const int UPKEY = 38
	;const int DOWNKEY = 40;
	const int RIGHTKEY = 39;
	const int LEFTKEY = 37;
							*/
	if (key == 38 && y != 0)
	{
		y = y - 1;
		DrawCursor(x, y);
	}
	else if (key == 40 && y != 8)
	{
		y = y + 1;
		DrawCursor(x, y);
	}
	else if (key == 39 && x != 8)
	{
		x = x + 1;
		DrawCursor(x, y);
	}
	else if (key == 37 && x != 0)
	{
		x = x - 1;
		DrawCursor(x, y);
	}
}

bool CheckIfCandyBreak(int arr[9][9], int x, int y, int key)
{
	bool flag = 1;
	bool iswrapped = false;
	bool striped = false;
	bool cookie = false;

	//const int UPKEY = 38
	//;const int DOWNKEY = 40;
	//const int RIGHTKEY = 39;
	//const int LEFTKEY = 37;
	checkifcookie(arr, x, y, key);
	checkforvertical(arr, x, y, key);
	checkwrapped(arr, x, y, key);
	checkifcookie(arr, x, y, key);
	if (key == 38 && y != 0)
	{
		if (arr[y - 1][x - 1] == arr[y][x] && arr[y][x] == arr[y - 1][x + 1])
		{
			swap(arr[y][x], arr[y - 1][x]);
			iswrapped = checkwrappedandupdate(arr, y - 1, x);
			cookie = checkcookie(arr, y - 1, x);
			striped = checkstriped(arr, y - 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = -1; h <= 1; h++)
				{
					arr[0][x + h] = (rand() % 5) + 1;
					for (int i = y - 1; i > 0; i--)
					{
						arr[i][x + h] = arr[i - 1][x + h];
					}
				}
			}

			return true;
		}
		else if (arr[y - 1][x + 1] == arr[y][x] && arr[y][x] == arr[y - 1][x + 2])
		{
			swap(arr[y][x], arr[y - 1][x]);
			iswrapped = checkwrappedandupdate(arr, y - 1, x);
			cookie = checkcookie(arr, y - 1, x);
			striped = checkstriped(arr, y - 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					arr[0][x + h] = (rand() % 5) + 1;
					for (int i = y - 1; i > 0; i--)
					{
						arr[i][x + h] = arr[i - 1][x + h];
					}
				}
			}
			return true;
		}
		else if (arr[y - 1][x - 1] == arr[y][x] && arr[y][x] == arr[y - 1][x - 2])
		{
			swap(arr[y][x], arr[y - 1][x]);
			iswrapped = checkwrappedandupdate(arr, y - 1, x);
			cookie = checkcookie(arr, y - 1, x);
			striped = checkstriped(arr, y - 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					arr[0][x - h] = (rand() % 5) + 1;
					for (int i = y - 1; i > 0; i--)
					{
						arr[i][x - h] = arr[i - 1][x - h];
					}
				}
			}
			return true;
		}
		else if (arr[y - 3][x] == arr[y][x] && arr[y][x] == arr[y - 2][x])
		{
			swap(arr[y][x], arr[y - 1][x]);
			iswrapped = checkwrappedandupdate(arr, y - 1, x);
			cookie = checkcookie(arr, y - 1, x);
			striped = checkstriped(arr, y - 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int j = 0; j < 2; j++)
				{
					for (int i = y - 2; i > 0; i--)
					{
						arr[i][x] = arr[i - 1][x];
					}
					arr[0][x] = (rand() % 5) + 1;
				}
			}

			return true;
		}

	}
	else if (key == 40 && y != 8)
	{
		if (arr[y + 1][x - 1] == arr[y][x] && arr[y][x] == arr[y + 1][x + 1])
		{
			swap(arr[y][x], arr[y + 1][x]);
			iswrapped = checkwrappedandupdate(arr, y + 1, x);
			cookie = checkcookie(arr, y + 1, x);
			striped = checkstriped(arr, y + 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = -1; h <= 1; h++)
				{
					for (int i = y + 1; i > 0; i--)
					{
						arr[i][x + h] = arr[i - 1][x + h];
					}
					arr[0][x + h] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y + 1][x - 1] == arr[y][x] && arr[y][x] == arr[y + 1][x - 2])
		{
			swap(arr[y][x], arr[y + 1][x]);
			iswrapped = checkwrappedandupdate(arr, y + 1, x);
			cookie = checkcookie(arr, y + 1, x);
			striped = checkstriped(arr, y + 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{

					for (int i = y + 1; i > 0; i--)
					{
						arr[i][x - h] = arr[i - 1][x - h];
					}
					arr[0][x - h] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y + 1][x + 1] == arr[y][x] && arr[y][x] == arr[y + 1][x + 2])
		{
			swap(arr[y][x], arr[y + 1][x]);
			iswrapped = checkwrappedandupdate(arr, y + 1, x);
			cookie = checkcookie(arr, y + 1, x);
			striped = checkstriped(arr, y + 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y + 1; i > 0; i--)
					{
						arr[i][x + h] = arr[i - 1][x + h];
					}
					arr[0][x + h] = rand() % 5 + 1;
				}
			}
			return true;
		}
		else if (arr[y + 3][x] == arr[y][x] && arr[y][x] == arr[y + 2][x])
		{
			swap(arr[y][x], arr[y + 1][x]);
			iswrapped = checkwrappedandupdate(arr, y + 1, x);
			cookie = checkcookie(arr, y + 1, x);
			striped = checkstriped(arr, y + 1, x, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int i = y + 3; i > 0; i--)
					{
						arr[i][x] = arr[i - 1][x];
					}
					arr[0][x] = (rand() % 5) + 1;
				}
			}
			return true;
		}
	}
	else if (key == 39 && x != 8)
	{
		if (arr[y - 1][x + 1] == arr[y][x] && arr[y][x] == arr[y + 1][x + 1])
		{
			swap(arr[y][x], arr[y][x + 1]);
			iswrapped = checkwrappedandupdate(arr, y, x + 1);
			cookie = checkcookie(arr, y, x + 1);
			striped = checkstriped(arr, y, x + 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y + 1; i > 0; i--)
					{
						arr[i][x + 1] = arr[i - 1][x + 1];
					}
					arr[0][x + 1] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y + 2][x + 1] == arr[y][x] && arr[y][x] == arr[y + 1][x + 1])
		{
			swap(arr[y][x], arr[y][x + 1]);
			iswrapped = checkwrappedandupdate(arr, y, x + 1);
			cookie = checkcookie(arr, y, x + 1);
			striped = checkstriped(arr, y, x + 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y + 2; i > 0; i--)
					{
						arr[i][x + 1] = arr[i - 1][x + 1];
					}
					arr[0][x + 1] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y - 2][x + 1] == arr[y][x] && arr[y][x] == arr[y - 1][x + 1])
		{
			swap(arr[y][x], arr[y][x + 1]);
			iswrapped = checkwrappedandupdate(arr, y, x + 1);
			cookie = checkcookie(arr, y, x + 1);
			striped = checkstriped(arr, y, x + 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y; i > 0; i--)
					{
						arr[i][x + 1] = arr[i - 1][x + 1];
					}
					arr[0][x + 1] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y][x + 2] == arr[y][x] && arr[y][x] == arr[y][x + 3])
		{
			swap(arr[y][x], arr[y][x + 1]);
			iswrapped = checkwrappedandupdate(arr, y, x + 1);
			cookie = checkcookie(arr, y, x + 1);
			striped = checkstriped(arr, y, x + 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h <= 3; h++)
				{

					for (int i = y; i > 0; i--)
					{
						arr[i][x + h] = arr[i - 1][x + h];
					}
					arr[0][x + h] = (rand() % 5) + 1;
				}
			}
			return true;
		}
	}
	else if (key == 37 && x != 0)
	{
		if (arr[y - 1][x - 1] == arr[y][x] && arr[y][x] == arr[y + 1][x - 1])
		{
			swap(arr[y][x], arr[y][x - 1]);
			iswrapped = checkwrappedandupdate(arr, y, x - 1);
			cookie = checkcookie(arr, y, x - 1);
			striped = checkstriped(arr, y, x - 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y + 1; i > 0; i--)
					{
						arr[i][x - 1] = arr[i - 1][x - 1];
					}
					arr[0][x - 1] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y - 1][x - 1] == arr[y][x] && arr[y][x] == arr[y - 2][x - 1])
		{
			swap(arr[y][x], arr[y][x - 1]);
			iswrapped = checkwrappedandupdate(arr, y, x - 1);
			cookie = checkcookie(arr, y, x - 1);
			striped = checkstriped(arr, y, x - 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y; i >= 0; i--)
					{
						if (i != 0)
							arr[i][x - 1] = arr[i - 1][x - 1];
					}
					arr[0][x - 1] = (rand() % 5) + 1;
				}

			}
			return true;
		}
		else if (arr[y + 1][x - 1] == arr[y][x] && arr[y][x] == arr[y + 2][x - 1])
		{
			swap(arr[y][x], arr[y][x - 1]);
			iswrapped = checkwrappedandupdate(arr, y, x - 1);
			cookie = checkcookie(arr, y, x - 1);
			striped = checkstriped(arr, y, x - 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 0; h < 3; h++)
				{
					for (int i = y + 2; i > 0; i--)
					{
						arr[i][x - 1] = arr[i - 1][x - 1];
					}
					arr[0][x - 1] = (rand() % 5) + 1;
				}
			}
			return true;
		}
		else if (arr[y][x - 3] == arr[y][x] && arr[y][x] == arr[y][x - 2])
		{
			swap(arr[y][x], arr[y][x - 1]);
			iswrapped = checkwrappedandupdate(arr, y, x - 1);
			cookie = checkcookie(arr, y, x - 1);
			striped = checkstriped(arr, y, x - 1, key);
			if (!striped && !iswrapped && !cookie)
			{
				for (int h = 1; h <= 3; h++)
				{
					for (int i = y; i > 0; i--)
					{
						arr[i][x - h] = arr[i - 1][x - h];
					}
					arr[0][x - h] = (rand() % 5) + 1;
				}
			}
			return true;
		}
	}

	return false;
}

bool checkcookie(int arr[9][9], int y, int x)
{
	bool iscookie = true;
	int j = x - 4, h = y + 4;
	for (int k = 1; k <= 2; k++)
	{
		iscookie = true;
		if (k == 1)
		{

			for (j = x - 4; j <= x + 4; j++)
			{
				if (j + 4 <= 8)
				{
					for (int i = j; i < j + 4; i++)
					{
						if (arr[y][i] != arr[y][i + 1])
						{
							iscookie = false;
							break;
						}
					}
				}
				if (iscookie)
					break;
			}
		}

		if (iscookie && k == 1)
		{
			for (int z = j; z <= j + 4; z++)
			{
				for (int a = y; a > 0; a--)
				{
					if (a != y || z != x)
						arr[a][j] = arr[a - 1][j];
				}
			}
			arr[y][x] = 40;
			break;
		}

		if (k == 2)
		{

			for (h = y + 4; h > y - 4; h--)
			{
				for (int i = h; i > h - 4; i--)
				{
					if (arr[i][x] != arr[i + 1][x])
					{
						iscookie = false;
						break;
					}
				}
				if (iscookie)
					break;
			}

		}
		if (iscookie && k == 2)
		{
			for (int z = h; z > h - 4; z--)
			{
				for (int a = h; a > 0; a--)
				{
					arr[a][x] = arr[a - 1][x];
				}
				arr[0][x] = (rand() % 5) + 1;
			}
			arr[h][x] = 40;
			break;
		}
	}
	return iscookie;
}

bool checkstriped(int arr[9][9], int y, int x, int key)
{
	//int k = 0, i = 0, z = 0, j = 0;
	//bool isstriped = true;
	//int count = 0;
	//int candy = arr[y][x];
	//for (j = 1; j <= 4; j++)
	//{
	//	isstriped = true;
	//	if (j == 1)
	//	{
	//		for (int i = 1; i <= 3; i++)
	//		{
	//			if (arr[y][x] != arr[y + i][x])
	//			{
	//				isstriped = false;
	//				break;
	//			}

	//		}
	//	}
	//	if (isstriped == true)
	//		break;
	//	else if (j == 2)
	//	{
	//		for (int i = 1; i <= 3; i++)
	//		{
	//			if (arr[y][x] != arr[y - i][x])
	//			{
	//				isstriped = false;
	//				break;
	//			}
	//		}
	//	}
	//	if (isstriped == true)
	//		break;
	//	else if (j == 3)
	//	{
	//		for (int i = 0; i < 4; i++)
	//		{
	//			if (arr[y][x] != arr[y][x + i])
	//			{
	//				isstriped = false;
	//				break;
	//			}

	//		}
	//	}
	//	if (isstriped == true)
	//		break;
	//	else if (j == 4)
	//	{
	//		for (int i = 0; i < 4; i++)
	//		{
	//			if (arr[y][x] != arr[y][x - i])
	//			{
	//				isstriped = false;
	//				break;
	//			}

	//		}
	//	}
	//	if (isstriped == true)
	//		break;
	//}
	//if (isstriped == true)
	//{
	//	candy = arr[y][x];
	//	if (j == 4)
	//	{
	//		for (int i = 0; i < 4; i++)
	//		{
	//			for (int h = y - 1; h > 0; h--)
	//			{
	//				if (h + 1 != y && x - i != x)
	//					arr[h + 1][x - i] = arr[h][x - i];
	//			}
	//			if (x - i != x)
	//				arr[0][x - i] = (rand() % 5) + 1;
	//		}
	//		arr[y][x] = candy + 20;
	//	}
	//	if (j == 3)
	//	{
	//		for (int i = 0; i < 4; i++)
	//		{
	//			for (int h = y - 1; h > 0; h--)
	//			{
	//				if (h + 1 != y && x + i != x)
	//					arr[h + 1][x + i] = arr[h][x + i];
	//			}
	//			if (x - i != x)
	//				arr[0][x + i] = (rand() % 5) + 1;
	//		}
	//		arr[y][x] = candy + 20;
	//	}
	//	if (j == 2)
	//	{
	//		arr[y][x] = candy + 10;
	//		for (int i = 1; i <= 2; i++)
	//		{
	//			for (int h = y - 1; h > 0; h--)
	//			{
	//				arr[h][x] = arr[h - 1][x];
	//			}

	//			arr[0][x] = (rand() % 5) + 1;
	//		}
	//	}
	//	if (j == 1)
	//	{
	//		arr[y][x] = candy + 10;
	//		for (int i = 2; i >= 1; i--)
	//		{
	//			for (int h = y + 3; h > 1; h--)
	//			{
	//				arr[h][x] = arr[h - 1][x];
	//			}
	//			arr[0][x] = (rand() % 5) + 1;
	//		}

	//	}

	//}

int k = 0, i = 0, z = 0, j = 0;
bool isstriped = true;
int count = 0;
int candy = arr[y][x];
for (j = 1; j <= 4; j++)
{
	isstriped = true;
	if (j == 1)
	{
		for (int i = 1; i <= 3; i++)
		{
			if (arr[y][x] != arr[y + i][x])
			{
				isstriped = false;
				break;
			}

		}
	}
	if (isstriped && j == 1)
		break;
	else if (j == 2)
	{
		for (int i = 1; i <= 3; i++)
		{
			if (arr[y][x] != arr[y - i][x])
			{
				isstriped = false;
				break;
			}
		}
	}
	if (isstriped && j == 2)
		break;
	else if (j == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[y][x] != arr[y][x + i])
			{
				isstriped = false;
				break;
			}

		}
	}
	if (isstriped && j == 3)
		break;
	else if (j == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[y][x] != arr[y][x - i])
			{
				isstriped = false;
				break;
			}

		}
	}
	if (isstriped && j == 4)
		break;
}
if (isstriped == true)
{
	candy = arr[y][x];
	if (j == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int h = y - 1; h > 0; h--)
			{
				if (h + 1 != y && x - i != x)
					arr[h + 1][x - i] = arr[h][x - i];
			}
			if (x - i != x)
				arr[0][x - i] = (rand() % 5) + 1;
		}
		arr[y][x] = candy + 20;
	}
	if (j == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int h = y - 1; h > 0; h--)
			{
				if (h + 1 != y && x + i != x)
					arr[h + 1][x + i] = arr[h][x + i];
			}
			if (x - i != x)
				arr[0][x + i] = (rand() % 5) + 1;
		}
		arr[y][x] = candy + 20;
	}
	if (j == 2)
	{
		arr[y][x] = candy + 10;
		for (int i = 1; i <= 2; i++)
		{
			for (int h = y - 1; h > 0; h--)
			{
				arr[h][x] = arr[h - 1][x];
			}

			arr[0][x] = (rand() % 5) + 1;
		}
	}
	if (j == 1)
	{
		arr[y][x] = candy + 10;
		for (int i = 2; i >= 1; i--)
		{
			for (int h = y + 3; h > 1; h--)
			{
				arr[h][x] = arr[h - 1][x];
			}
			arr[0][x] = (rand() % 5) + 1;
		}

	}
}



	//for (int z = 1; z <= 2; z++)
	//{
	//	if (z == 1)
	//	{
	//		if (x < 3)
	//			k = x;
	//		else
	//			k = x - 3;
	//		for (i = k; i <= 8 && i <= x + 3; i++)
	//		{
	//			if (arr[y][i] == arr[y][x])
	//			{
	//				count++;
	//			}
	//			else
	//			{
	//				count = 0;
	//				isstriped = false;
	//			}
	//			if (count == 4)
	//			{
	//				isstriped = true;
	//				break;
	//			}
	//		}
	//		if (isstriped && count == 4)
	//		{
	//			for (int g = i; g > i - 3; g--)
	//			{
	//				for (int j = y; j > 0; j--)
	//				{
	//					if (j != y || g != x)
	//						arr[j][g] = arr[j - 1][g];
	//				}
	//				arr[0][g] = (rand() % 5) + 1;
	//			}
	//		}
	//	}
	//	if (z == 1 && isstriped)
	//		break;
	//	if (z == 2)
	//	{
	//		count = 0;
	//		if (y < 3)
	//			k = y;
	//		else
	//			k = y + 3;
	//		for (i = k; i >= 0 && i > y - 3; i--)
	//		{
	//			if (arr[i][x] == arr[y][x])
	//			{
	//				count++;
	//			}
	//			else
	//			{
	//				count = 0;
	//				isstriped = false;
	//			}
	//			if (count == 4)
	//			{
	//				isstriped = true;
	//				break;
	//			}
	//		}
	//		if (isstriped && count == 4)
	//		{

	//			for (int s = 1; s <= 3; s++)
	//			{
	//				for (int j = i; j > 0; j--)
	//				{
	//					arr[j][x] = arr[j - 1][x];
	//				}
	//				arr[0][x] = (rand() % 5) + 1;
	//			}
	//		}
	//		if (z == 2 && isstriped)
	//			break;
	//	}
	//}
	//if (isstriped && z == 2)
	//{
	//	if (key == 38 || key == 40)
	//		arr[i][x] = candy + 10;
	//	else
	//		arr[i][x] = candy + 20;
	//}
	//else if (isstriped && z == 1)
	//{
	//	if (key == 38 || key == 40)
	//		arr[y][x] = candy + 10;
	//	else
	//		arr[y][x] = candy + 20;
	//}
	return isstriped;
}

void burstcookie(int arr[9][9], int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == arr[y][x])
			{
				for (int k = i; k > 0; k--)
				{
					arr[k][j] = arr[k - 1][j];
				}
				arr[0][j] = ((rand() % 5) + 1);
			}
		}
	}
}

void burstwrapped(int arr[9][9], int x, int y)
{
	for (int k = 1; k <= 3; k++)
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y + 1; j > 0; j--)
			{
				arr[j][i] = arr[j - 1][i];
			}
			arr[0][i] = ((rand() % 5) + 1);
		}
	}
}

void burststriped(int arr[9][9], int x, int y)
{
	if (arr[y][x] > 20 && arr[y][x] < 26)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = y; j > 0; j--)
			{
				arr[j][i] = arr[j - 1][i];
			}
		}
	}
	if (arr[y][x] > 10 && arr[y][x] < 16)
	{
		for (int i = 8; i >= 0; i--)
		{
			arr[i][x] = (rand() % 5) + 1;
		}
	}
}

void checkforhorizontal(int arr[9][9], int x, int y, int key)
{
	if (key == 38)
	{
		if (((arr[y - 1][x - 1] == arr[y][x] + 20) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 1]) || (arr[y][x] == arr[y - 1][x + 1] + 20)) ||
			((arr[y - 1][x - 1] == arr[y][x] - 20) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 1]) || (arr[y][x] == arr[y - 1][x + 1] - 20)) ||
			((arr[y - 1][x + 1] == arr[y][x] + 20) || (arr[y - 1][x + 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 2]) || (arr[y][x] == arr[y - 1][x + 2] + 20)) ||
			((arr[y - 1][x + 1] == arr[y][x] - 20) || (arr[y - 1][x + 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 2]) || (arr[y][x] == arr[y - 1][x + 2] - 20)) ||
			((arr[y - 1][x - 1] == arr[y][x] - 20) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x - 2]) || (arr[y][x] == arr[y - 1][x - 2] - 20)))
		{
			burststriped(arr, x, y - 1);
		}
		else if ((arr[y - 1][x] == arr[y][x] || arr[y - 1][x] == arr[y][x] + 20) && (arr[y - 2][x] == arr[y][x] || arr[y - 2][x] == arr[y][x] + 20) ||
			((arr[y - 1][x] == arr[y][x] || arr[y - 1][x] == arr[y][x] + 20) && (arr[y - 2][x] == arr[y][x] || arr[y - 2][x] == arr[y][x] + 20)))
		{
			if (arr[y][x] > 20 && arr[y][x] < 26)
				burststriped(arr, x, y);
			else if (arr[y - 1][x] > 20 && arr[y - 1][x] < 26)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x] > 20 && arr[y - 2][x] < 26)
				burststriped(arr, x, y - 2);
		}
	}
	else if (key == 40)
	{
		if ((arr[y + 1][x - 1] == arr[y][x] || arr[y - 1][x - 1] == arr[y][x] + 20) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 20) ||
			(arr[y + 1][x + 1] == arr[x][y] || arr[y + 1][x + 1] == arr[y][x] + 20) &&
			(arr[y + 1][x + 2] = arr[x][y] || arr[y + 1][x + 2] == arr[y][x] + 20) ||
			(arr[y + 1][x - 1] == arr[x][y] || arr[y + 1][x - 1] == arr[y][x] + 20) &&
			(arr[y + 1][x - 2] = arr[x][y] || arr[y + 1][x - 2] == arr[y][x] + 20))
			burststriped(arr, x, y + 1);
		if ((arr[y + 2][x] == arr[y + 1][x]) || (arr[y + 2][x] == arr[y + 1][x] + 20) &&
			((arr[y + 3][x] == arr[y + 1][x]) || (arr[y + 3][x] == arr[y + 1][x] + 20)) ||
			((arr[y + 2][x] == arr[y + 1][x] || arr[y + 2][x] == arr[y + 1][x] - 20)) &&
			((arr[y + 3][x] == arr[y + 1][x]) || (arr[y + 3][x] == arr[y + 1][x] - 20)))
		{
			if (arr[y + 3][x] > 20 && arr[y + 3][x] < 26)
				burststriped(arr, x, y + 3);
			else if (arr[y + 2][x] > 20 && arr[y + 2][x] < 26)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x] > 20 && arr[y + 1][x] < 26)
				burststriped(arr, x, y + 1);
		}


	}
	else if (key == 39)
	{
		if ((arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 20) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 20) ||
			(arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 20) &&
			(arr[y - 2][x + 1] == arr[y][x] || arr[y - 2][x + 1] == arr[y][x] + 20) ||
			(arr[y + 2][x + 1] == arr[y][x] || arr[y + 2][x] == arr[y][x] + 20) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 2][x + 1] == arr[y][x] + 20))
		{
			if (arr[y + 2][x + 1] > 20 && arr[y + 2][x + 1] < 26)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x + 1] > 20 && arr[y + 2][x + 1] < 26)
				burststriped(arr, x, y + 1);
			else if (arr[y - 1][x + 1] > 20 && arr[y][x + 1] < 26)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x + 1] > 20 && arr[y - 2][x + 1] < 26)
				burststriped(arr, x, y - 2);
		}
		if ((arr[y][x + 3] == arr[y][x] + 20 && arr[y][x + 2] == arr[y][x]) ||
			(arr[y][x + 2] == arr[y][x] + 20 && arr[y][x + 3] == arr[y][x]) ||
			(arr[y][x + 2] == arr[y][x] - 20 && arr[y][x + 3] == arr[y][x] - 20) ||
			(arr[y][x + 3] == arr[y][x] - 20 && arr[y][x + 2] == arr[y][x] - 20))
			burststriped(arr, x, y);
	}
	else if (key == 37)
	{
		if ((arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 20) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 20) ||
			(arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 20) &&
			(arr[y - 2][x + 1] == arr[y][x] || arr[y - 2][x + 1] == arr[y][x] + 20) ||
			(arr[y + 2][x + 1] == arr[y][x] || arr[y + 2][x] == arr[y][x] + 20) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 2][x + 1] == arr[y][x] + 20))
		{
			if (arr[y + 2][x + 1] > 20 && arr[y + 2][x + 1] < 26)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x + 1] > 20 && arr[y + 2][x + 1] < 26)
				burststriped(arr, x, y + 1);
			else if (arr[y - 1][x + 1] > 20 && arr[y][x + 1] < 26)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x + 1] > 20 && arr[y - 2][x + 1] < 26)
				burststriped(arr, x, y - 2);
		}
		if ((arr[y][x - 3] == arr[y][x] + 20 && arr[y][x - 2] == arr[y][x]) ||
			(arr[y][x - 2] == arr[y][x] + 20 && arr[y][x - 3] == arr[y][x]) ||
			(arr[y][x - 2] == arr[y][x] - 20 && arr[y][x - 3] == arr[y][x] - 20) ||
			(arr[y][x - 3] == arr[y][x] - 20 && arr[y][x - 2] == arr[y][x] - 20))
			burststriped(arr, x, y);

	}
}

void checkforvertical(int arr[9][9], int x, int y, int key)
{
	if (key == 38)
	{
		if (((arr[y - 1][x - 1] == arr[y][x] + 10) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 1]) || (arr[y][x] == arr[y - 1][x + 1] + 10)) ||
			((arr[y - 1][x - 1] == arr[y][x] - 10) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 1]) || (arr[y][x] == arr[y - 1][x + 1] - 10)) ||
			((arr[y - 1][x + 1] == arr[y][x] + 10) || (arr[y - 1][x + 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 2]) || (arr[y][x] == arr[y - 1][x + 2] + 10)) ||
			((arr[y - 1][x + 1] == arr[y][x] - 10) || (arr[y - 1][x + 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 2]) || (arr[y][x] == arr[y - 1][x + 2] - 10)) ||
			((arr[y - 1][x - 1] == arr[y][x] - 10) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x - 2]) || (arr[y][x] == arr[y - 1][x - 2] - 10)))
		{
			burststriped(arr, x, y - 1);
		}
		else if ((arr[y - 1][x] == arr[y][x] || arr[y - 1][x] == arr[y][x] + 10) && (arr[y - 2][x] == arr[y][x] || arr[y - 2][x] == arr[y][x] + 10) ||
			((arr[y - 1][x] == arr[y][x] || arr[y - 1][x] == arr[y][x] + 10) && (arr[y - 2][x] == arr[y][x] || arr[y - 2][x] == arr[y][x] + 10)))
		{
			if (arr[y][x] > 10 && arr[y][x] < 16)
				burststriped(arr, x, y);
			else if (arr[y - 1][x] > 10 && arr[y - 1][x] < 16)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x] > 10 && arr[y - 2][x] < 16)
				burststriped(arr, x, y - 2);
		}
	}
	else if (key == 40)
	{
		if ((arr[y + 1][x - 1] == arr[y][x] || arr[y - 1][x - 1] == arr[y][x] + 10) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 10) ||
			(arr[y + 1][x + 1] == arr[x][y] || arr[y + 1][x + 1] == arr[y][x] + 10) &&
			(arr[y + 1][x + 2] = arr[x][y] || arr[y + 1][x + 2] == arr[y][x] + 10) ||
			(arr[y + 1][x - 1] == arr[x][y] || arr[y + 1][x - 1] == arr[y][x] + 10) &&
			(arr[y + 1][x - 2] = arr[x][y] || arr[y + 1][x - 2] == arr[y][x] + 10))
			burststriped(arr, x, y + 1);
		if ((arr[y + 2][x] == arr[y + 1][x]) || (arr[y + 2][x] == arr[y + 1][x] + 10) &&
			((arr[y + 3][x] == arr[y + 1][x]) || (arr[y + 3][x] == arr[y + 1][x] + 10)) ||
			((arr[y + 2][x] == arr[y + 1][x] || arr[y + 2][x] == arr[y + 1][x] - 10)) &&
			((arr[y + 3][x] == arr[y + 1][x]) || (arr[y + 3][x] == arr[y + 1][x] - 10)))
		{
			if (arr[y + 3][x] > 10 && arr[y + 3][x] < 16)
				burststriped(arr, x, y + 3);
			else if (arr[y + 2][x] > 10 && arr[y + 2][x] < 16)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x] > 10 && arr[y + 1][x] < 16)
				burststriped(arr, x, y + 1);
		}


	}
	else if (key == 39)
	{
		if ((arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 10) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 10) ||
			(arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 10) &&
			(arr[y - 2][x + 1] == arr[y][x] || arr[y - 2][x + 1] == arr[y][x] + 10) ||
			(arr[y + 2][x + 1] == arr[y][x] || arr[y + 2][x] == arr[y][x] + 10) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 2][x + 1] == arr[y][x] + 10))
		{
			if (arr[y + 2][x + 1] > 10 && arr[y + 2][x + 1] < 16)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x + 1] > 10 && arr[y + 2][x + 1] < 16)
				burststriped(arr, x, y + 1);
			else if (arr[y - 1][x + 1] > 10 && arr[y][x + 1] < 16)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x + 1] > 10 && arr[y - 2][x + 1] < 16)
				burststriped(arr, x, y - 2);
		}
		if ((arr[y][x + 3] == arr[y][x] + 10 && arr[y][x + 2] == arr[y][x]) ||
			(arr[y][x + 2] == arr[y][x] + 10 && arr[y][x + 3] == arr[y][x]) ||
			(arr[y][x + 2] == arr[y][x] - 10 && arr[y][x + 3] == arr[y][x] - 10) ||
			(arr[y][x + 3] == arr[y][x] - 10 && arr[y][x + 2] == arr[y][x] - 10))
			burststriped(arr, x, y);
	}
	else if (key == 37)
	{
		if ((arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 10) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 10) ||
			(arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 10) &&
			(arr[y - 2][x + 1] == arr[y][x] || arr[y - 2][x + 1] == arr[y][x] + 10) ||
			(arr[y + 2][x + 1] == arr[y][x] || arr[y + 2][x] == arr[y][x] + 10) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 2][x + 1] == arr[y][x] + 10))
		{
			if (arr[y + 2][x + 1] > 10 && arr[y + 2][x + 1] < 16)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x + 1] > 10 && arr[y + 2][x + 1] < 16)
				burststriped(arr, x, y + 1);
			else if (arr[y - 1][x + 1] > 10 && arr[y][x + 1] < 16)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x + 1] > 10 && arr[y - 2][x + 1] < 16)
				burststriped(arr, x, y - 2);
		}
		if ((arr[y][x - 3] == arr[y][x] + 10 && arr[y][x - 2] == arr[y][x]) ||
			(arr[y][x - 2] == arr[y][x] + 10 && arr[y][x - 3] == arr[y][x]) ||
			(arr[y][x - 2] == arr[y][x] - 10 && arr[y][x - 3] == arr[y][x] - 10) ||
			(arr[y][x - 3] == arr[y][x] - 10 && arr[y][x - 2] == arr[y][x] - 10))
			burststriped(arr, x, y);

	}
}

void checkwrapped(int arr[9][9], int x, int y, int key)
{
	if (key == 38)
	{
		if (((arr[y - 1][x - 1] == arr[y][x] + 30) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 1]) || (arr[y][x] == arr[y - 1][x + 1] + 30)) ||
			((arr[y - 1][x - 1] == arr[y][x] - 30) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 1]) || (arr[y][x] == arr[y - 1][x + 1] - 30)) ||
			((arr[y - 1][x + 1] == arr[y][x] + 30) || (arr[y - 1][x + 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 2]) || (arr[y][x] == arr[y - 1][x + 2] + 30)) ||
			((arr[y - 1][x + 1] == arr[y][x] - 30) || (arr[y - 1][x + 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x + 2]) || (arr[y][x] == arr[y - 1][x + 2] - 30)) ||
			((arr[y - 1][x - 1] == arr[y][x] - 30) || (arr[y - 1][x - 1] == arr[y][x])) &&
			((arr[y][x] == arr[y - 1][x - 2]) || (arr[y][x] == arr[y - 1][x - 2] - 30)))
		{
			burststriped(arr, x, y - 1);
		}
		else if ((arr[y - 1][x] == arr[y][x] || arr[y - 1][x] == arr[y][x] + 30) && (arr[y - 2][x] == arr[y][x] || arr[y - 2][x] == arr[y][x] + 30) ||
			((arr[y - 1][x] == arr[y][x] || arr[y - 1][x] == arr[y][x] + 30) && (arr[y - 2][x] == arr[y][x] || arr[y - 2][x] == arr[y][x] + 30)))
		{
			if (arr[y][x] > 30 && arr[y][x] < 36)
				burststriped(arr, x, y);
			else if (arr[y - 1][x] > 30 && arr[y - 1][x] < 36)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x] > 30 && arr[y - 2][x] < 36)
				burststriped(arr, x, y - 2);
		}
	}
	else if (key == 40)
	{
		if ((arr[y + 1][x - 1] == arr[y][x] || arr[y - 1][x - 1] == arr[y][x] + 30) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 30) ||
			(arr[y + 1][x + 1] == arr[x][y] || arr[y + 1][x + 1] == arr[y][x] + 30) &&
			(arr[y + 1][x + 2] = arr[x][y] || arr[y + 1][x + 2] == arr[y][x] + 30) ||
			(arr[y + 1][x - 1] == arr[x][y] || arr[y + 1][x - 1] == arr[y][x] + 30) &&
			(arr[y + 1][x - 2] = arr[x][y] || arr[y + 1][x - 2] == arr[y][x] + 30))
			burststriped(arr, x, y + 1);
		if ((arr[y + 2][x] == arr[y + 1][x]) || (arr[y + 2][x] == arr[y + 1][x] + 30) &&
			((arr[y + 3][x] == arr[y + 1][x]) || (arr[y + 3][x] == arr[y + 1][x] + 30)) ||
			((arr[y + 2][x] == arr[y + 1][x] || arr[y + 2][x] == arr[y + 1][x] - 30)) &&
			((arr[y + 3][x] == arr[y + 1][x]) || (arr[y + 3][x] == arr[y + 1][x] - 30)))
		{
			if (arr[y + 3][x] > 30 && arr[y + 3][x] < 36)
				burststriped(arr, x, y + 3);
			else if (arr[y + 2][x] > 30 && arr[y + 2][x] < 36)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x] > 30 && arr[y + 1][x] < 36)
				burststriped(arr, x, y + 1);
		}


	}
	else if (key == 39)
	{
		if ((arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 30) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 30) ||
			(arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 30) &&
			(arr[y - 2][x + 1] == arr[y][x] || arr[y - 2][x + 1] == arr[y][x] + 30) ||
			(arr[y + 2][x + 1] == arr[y][x] || arr[y + 2][x] == arr[y][x] + 30) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 2][x + 1] == arr[y][x] + 30))
		{
			if (arr[y + 2][x + 1] > 30 && arr[y + 2][x + 1] < 36)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x + 1] > 30 && arr[y + 2][x + 1] < 36)
				burststriped(arr, x, y + 1);
			else if (arr[y - 1][x + 1] > 30 && arr[y][x + 1] < 36)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x + 1] > 30 && arr[y - 2][x + 1] < 36)
				burststriped(arr, x, y - 2);
		}
		if ((arr[y][x + 3] == arr[y][x] + 30 && arr[y][x + 2] == arr[y][x]) ||
			(arr[y][x + 2] == arr[y][x] + 30 && arr[y][x + 3] == arr[y][x]) ||
			(arr[y][x + 2] == arr[y][x] - 30 && arr[y][x + 3] == arr[y][x] - 30) ||
			(arr[y][x + 3] == arr[y][x] - 30 && arr[y][x + 2] == arr[y][x] - 30))
			burststriped(arr, x, y);
	}
	else if (key == 37)
	{
		if ((arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 30) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 1][x + 1] == arr[y][x] + 30) ||
			(arr[y - 1][x + 1] == arr[y][x] || arr[y - 1][x + 1] == arr[y][x] + 30) &&
			(arr[y - 2][x + 1] == arr[y][x] || arr[y - 2][x + 1] == arr[y][x] + 30) ||
			(arr[y + 2][x + 1] == arr[y][x] || arr[y + 2][x] == arr[y][x] + 30) &&
			(arr[y + 1][x + 1] == arr[y][x] || arr[y + 2][x + 1] == arr[y][x] + 30))
		{
			if (arr[y + 2][x + 1] > 30 && arr[y + 2][x + 1] < 36)
				burststriped(arr, x, y + 2);
			else if (arr[y + 1][x + 1] > 30 && arr[y + 2][x + 1] < 36)
				burststriped(arr, x, y + 1);
			else if (arr[y - 1][x + 1] > 30 && arr[y][x + 1] < 36)
				burststriped(arr, x, y - 1);
			else if (arr[y - 2][x + 1] > 30 && arr[y - 2][x + 1] < 36)
				burststriped(arr, x, y - 2);
		}
		if ((arr[y][x - 3] == arr[y][x] + 30 && arr[y][x - 2] == arr[y][x]) ||
			(arr[y][x - 2] == arr[y][x] + 30 && arr[y][x - 3] == arr[y][x]) ||
			(arr[y][x - 2] == arr[y][x] - 30 && arr[y][x - 3] == arr[y][x] - 30) ||
			(arr[y][x - 3] == arr[y][x] - 30 && arr[y][x - 2] == arr[y][x] - 30))
			burststriped(arr, x, y);

	}
}

void checkifcookie(int arr[9][9], int x, int y, int key)
{
	if (key == 38 && arr[y][x] == 40)
	{
		burstcookie(arr, x, y - 1);
		for (int i = y; i > 0; i--)
		{
			arr[i][x] = arr[i - 1][x];
		}
		arr[0][x] = (rand() % 5) + 1;
	}
	if (key == 40 && arr[y][x] == 40)
	{
		for (int i = y; i > 0; i--)
		{
			arr[i][x] = arr[i - 1][x];
		}
		burstcookie(arr, x, y + 1);
		arr[0][x] = (rand() % 5) + 1;
	}
	if (key == 39 && arr[y][x] == 40)
	{
		for (int i = y; i > 0; i--)
		{
			arr[i][x] = arr[i - 1][x];
		}
		burstcookie(arr, x + 1, y);
		arr[0][x] = (rand() % 5) + 1;
	}
	if (key == 37 && arr[y][x] == 40)
	{
		for (int i = y; i > 0; i--)
		{
			arr[i][x] = arr[i - 1][x];
		}
		burstcookie(arr, x - 1, y);
		arr[0][x] = (rand() % 5) + 1;
	}
}