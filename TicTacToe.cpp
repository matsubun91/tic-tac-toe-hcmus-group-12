#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	SetWindowLong(consoleWindow, GWL_STYLE, style);
}


void GotoXY(int x, int y)
{
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


#define BOARD_SIZE 15
#define LEFT 3
#define TOP 1


struct _POINT {
	int x; /*hoanh do*/
	int y; /*tung do*/
	int c; /*trang thai o*/
};

struct _POINT _A[BOARD_SIZE][BOARD_SIZE];

bool _TURN;
int _COMMAND;
int _X, _Y;

void ResetData()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_A[i][j].x = 4 * j + LEFT + 2;
			_A[i][j].y = 4 + i * TOP + 1;
			_A[i][j].c = 0;
		}
	}

	_TURN = true;
	_COMMAND = -1;

	_X = _A[0][0].x;
	_Y = _A[0][0].y;
}
void DrawBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			GotoXY(LEFT + 4 * j, TOP + 2 * i);
			printf_s("|");

			GotoXY(LEFT + 4 * j+ 1, TOP + 2 * i);
			printf_s("___");

			GotoXY(LEFT + 4 * j + 4, TOP + 2 * i);
			printf_s("|");
		}
	}
	
}


void StartGame() {
	system("cls");
	ResetData();
	DrawBoard();

}
void ExitGame() {
	system("cls");
	printf_s("Thanks for playing!\n");
	exit(0);
}

void main()
{
	FixConsoleWindow();

	StartGame();

	_getch();

	ExitGame();

}