#pragma once
#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<time.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define ESC 27
#define ENTER 13
#define BACKSPACE 8
#define TAB 9
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define F2 60
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define PU 73
#define PD 81

#define WIDTH 
#define HEIGHT 

#define DEN 128
#define LAMDAM 129
#define LUCDAM 130
#define DATROIDAM 131
#define DODAM 132
#define HONGDAM 133
#define VANGDAM 134
#define TRANGDAM 135
#define XAM 136
#define LAM 137
#define LUC 138
#define DATROI 139
#define DO 140
#define HONG 141
#define VANG 142
#define TRANG 143

using namespace std;

void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}

void clreol() {
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
        info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
    gotoxy(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
    system("cls");
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void VeKhung(int posx, int posy, int dai,int rong)
{
	
	for(int i = 0; i < dai; i++) // top
	{
		gotoxy(posx + i, posy);
		cout << char(196);
	}
	gotoxy(posx, posy);
	cout << char(218); // top-left
	gotoxy(posx + dai, posy);
	cout << char(191); // top-right
	for(int i = 1; i <= rong; i++) // right
	{
		gotoxy(posx + dai, posy + i);
		cout << char(179);
	}	
	for(int i = 0; i < dai; i++) // bot
	{
		gotoxy(posx + i, posy + rong);
		cout << char(196);
	}
	gotoxy(posx + dai, posy + rong);
	cout << char(217);	// bot-right	
	for(int i = 1; i <= rong; i++) // left
	{
		gotoxy(posx, posy + i);
		cout << char(179);
	}
	gotoxy(posx, posy + rong);
	cout << char(192); // bot-left

}


void VeLine(int dai, int posx, int posy)
{
	for(int i = 0; i < dai; i++)
	{
		gotoxy(posx + i, posy);
		cout << char(196);
	}
}

void fullScreen()
{
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

//bo thanh keo console
void RemoveScroll()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hstdout, &csbi);

    csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
    csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
    SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

    HWND x = GetConsoleWindow();
    ShowScrollBar(x, SB_BOTH, FALSE);
}
struct InputSTR {
	unsigned int n;
	char *Key[255];
};

void InputString(char *variable, int max)
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && !((int)c>=48 && (int)c<=57)) && Nhap.n < MaxNhap)
			{
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57) {
					continue;
				}
				if(Nhap.n == 0){
					c=toupper(c);
				}
				else c=tolower(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
			}
			
			if(Nhap.n>0 && c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}

void InputLoai(char *variable, int max)
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && ((int)c == 78 || (int)c == 88 || (int)c == 110 || (int)c == 120) && Nhap.n < MaxNhap)
			{
				
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
			}
			
			if(Nhap.n>0 && c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}

void InputNumber(char *variable, int max)
{
	int MaxNhap = max;
	rewind(stdin);
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && !(!((int)c>=48 && (int)c<=57) && !((int)c==45)) && Nhap.n < MaxNhap)
			{
				if(Nhap.n > 0 && c == int(45)) continue;
				c = toupper(c);
				Nhap.Key[Nhap.n] = new char;
				cout << c;
				*Nhap.Key[Nhap.n] = c;
				Nhap.n++;
				
			}
			if(Nhap.n>0 && c== '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}		
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';

}

void InputStringSpace(char *variable, int max) //ham chi cho cach 1 khoang trang
{
	int MaxNhap = max;
	InputSTR Nhap;	
	Nhap.n = 0;
	while(true)
	{
		if(kbhit())
		{
			char c = getch();
			if(c==27) {
				strcpy(variable,"quit");
				return;
			}
			if(!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122) && c != ' ' && !((int)c>=48 && (int)c<=57)))
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ' && c == ' ')
				{
					continue;
				}
				if (Nhap.n == 0 && (int)c>=48 && (int)c<=57 ) {
					continue;
				}
				if(!(Nhap.n == 0 && c == ' '))
				{
					if(Nhap.n == 0)
						c = toupper(c);
					else
					{
						if(*Nhap.Key[Nhap.n - 1] == ' ')
							c = toupper(c);
						else 
							c = tolower(c);
					}
					Nhap.Key[Nhap.n] = new char;
					cout << c;
					*Nhap.Key[Nhap.n] = c;
					Nhap.n++;
				}
			}
			if(c == '\r')
			{
				if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
				{
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if(Nhap.n > 0)
					{
						Nhap.n--;
					}
				}	
				break;
			}
			if(c == BACKSPACE && Nhap.n > 0)
			{
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				Nhap.n--;
			}
		}
			
	}
	for(int i = 0; i < Nhap.n; i++)
	{
		variable[i] = *Nhap.Key[i];
	}
	variable[Nhap.n] = '\0';
}

void thongBaoLoi(string s) {
	SetColor(DODAM);
	gotoxy(125,43);
	cout << s;
	gotoxy(125,44);
	cout << "Nhan phim bat ki de tiep tuc";
	SetColor(TRANG);
}

void InputFloatNumber(char *variable, int max)
{
    int MaxNhap = max;
    rewind(stdin);
    InputSTR Nhap;
    Nhap.n = 0;
    while(true)
    {
        if(kbhit())
        {
            char c = getch();
            if(c==27) {
                strcpy(variable,"quit");
                return;
            }
            if(!kbhit() && !(!((int)c>=48 && (int)c<=57) && (int)c!=46 ) && Nhap.n < MaxNhap)
            {
                if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == '.' && c == '.')
                {
                    continue;
                }
                c = toupper(c);
                Nhap.Key[Nhap.n] = new char;
                cout << c;
                *Nhap.Key[Nhap.n] = c;
                Nhap.n++;

            }
            if(Nhap.n>0 && c== '\r')
            {
                if(Nhap.n > 0 && *Nhap.Key[Nhap.n - 1] == ' ')
                {
                    gotoxy(wherex() - 1, wherey());
                    cout << " ";
                    gotoxy(wherex() - 1, wherey());
                    if(Nhap.n > 0)
                    {
                        Nhap.n--;
                    }
                }
                break;
            }
            if(c == BACKSPACE && Nhap.n > 0)
            {
                gotoxy(wherex() - 1, wherey());
                cout << " ";
                gotoxy(wherex() - 1, wherey());
                Nhap.n--;
            }
        }
    }
    for(int i = 0; i < Nhap.n; i++)
    {
        variable[i] = *Nhap.Key[i];
    }
    variable[Nhap.n] = '\0';

}
