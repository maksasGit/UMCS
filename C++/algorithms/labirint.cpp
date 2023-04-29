#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>

#include <stdio.h>
#include <Windows.h>
#include "VecFunctions.h"

using namespace std;

int nScreenWidth = 40;			// Console Screen Size X (columns)
int nScreenHeight = 10;			// Console Screen Size Y (rows)
int nMapWidth = 5;				// World Dimensions
int nMapHeight = 5;


int PlayerX = 1;
int PlayerY = 1;


void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}



int main() {
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
    string mapa[5];
    mapa[0] = "#####";
    mapa[1] = "#...#";
    mapa[2] = "#.#.#";
    mapa[3] = "#...#";
    mapa[4] = "#####";
    while (1)
    {
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
			PlayerX-=1;

		// Handle CW Rotation
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
			PlayerX+=1;

		// Handle Forwards movement & collision
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000)
		{
			PlayerY+=1;
		}

		// Handle backwards movement & collision
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000)
		{
			PlayerY-=1;
		}

		for (int nx = 0; nx < nMapWidth; nx++) {

			for (int ny = 0; ny < nMapWidth; ny++)
			{
				screen[nx * nScreenHeight + ny] =  mapa[nx][ny];
			}
		}
		screen[PlayerX * nScreenHeight + PlayerY] = 'P';
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacterW(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);

    }
    getchar();
}




