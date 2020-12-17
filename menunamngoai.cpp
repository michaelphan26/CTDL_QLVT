#include <iostream>
#include <malloc.h>
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
#include"lib.h"

using namespace std;

void ChoiceLTC(int i,int j) {
	TextColor(j);
	if (i == 0) {
		gotoxy(131,7);
		cout << "THEM LOP TIN CHI";
	}
	if (i == 1) {
		gotoxy(132,7+7);
		cout << "XOA LOP TIN CHI";
	}
	if (i == 2) {
		gotoxy(129,7+14);
		cout << "CHINH SUA LOP TIN CHI";
	}
	if (i  == 3) {
		gotoxy(126,7+21);
		cout << "DANH SACH SINH VIEN CUA LOP";
	}
	if (i == 4) {
		gotoxy(130,7+28);
		cout << "DANG KI LOP TIN CHI";
	}
}

void menu(){
	int max = 10;
	int k=0;
	int thaoTac = 0;	
	bool exit = false;
	int So_item = 5;

	//TextColor(138);
	// in menu ra man hinh

	//	highlight thao tac dau tien khi mo chuong trinh
	TextColor(140);
	gotoxy(131,7);
	cout << "THEM LOP TIN CHI";
	TextColor(DEN);
	Draw_LTC(ds,k);
	while (!exit)
	{	
		
		char key;
		key = getch();
		if (key == UP)
		{
			ChoiceLTC(thaoTac,137);
			if (thaoTac == 0)
				thaoTac = So_item - 1;
			else thaoTac--;	
		}
		else if (key == DOWN)
		{
			ChoiceLTC(thaoTac,137);
			if (thaoTac == So_item - 1)
				thaoTac = 0;
			else thaoTac++;	
		}
		else if (key == ESC)
		{
			exit = true;
		}
		else if (key == PGUP) {
			k=k-30;
			if (k<0) {
				k=0;
			}
			cu 30 dong thi show ra
		}
		else if (key == PGDN) {
			k=k+30;
			if (k>=ds.n) {
				k=k-30;
			}
			ClearTable(); // xoa bang cu
			Draw_LTC(ds,k); // ve lai bang moi
		}
		if (key == TAB) {
			
			int l=0;
			ClearTable();
			DrawTableMH();
			Show_Tree(kd,k);
			bool exit=false;
			while (!exit) {
				char key;
				key = getch();
				if (key == ESC)
				{
					exit = true;
				}
				else if (key == PGUP) {
					l=l-30;
					if (l<0) {
						l=0;
					}
					ClearTable();
					DrawTableMH();
					Show_Tree(kd,l);
				}
				else if (key == PGDN) {
					l=l+30;
					if (l>=CountNode(kd)) {
						l=l-30;
					}
					ClearTable();
					DrawTableMH();
					Show_Tree(kd,l);
				}
			}
			exit = true;
			ClearTable();
			Draw_LTC(ds,k);
		}
		else if (key == ENTER)
		{
			if (thaoTac == 0) {
				ClearChoice();
				Create_LopTinChi(ds);
				GhiFile_LTC(ds);
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 1) {
				ClearChoice();
				DrawBox(114,20,50,2);
				gotoxy(116,20);
				cout << "Nhap ma lop tin chi can xoa!";
				char a[10];
				fflush(stdin);
				gotoxy(116,21);
				InputNumber(a,max);
				Delete_LTC_MALOPTC(ds,atoi(a));
				GhiFile_LTC(ds);
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 2) {
				exit = false;
				ClearTable();
				ClearChoice();
				Draw_LTC(ds,k);
				int thaotac=0;
				gotoxy(5,7);
				cout << ">";
				gotoxy(11,7);
				cout << "<";
				while (!exit) {
					char c;
					c = getch();
					if (c == DOWN)
					{
						thaotac++;
						if (thaotac >=(ds.n-k-1)) {
							thaotac=(ds.n-k-1);
						}
						if (thaotac >= 30) {
							thaotac=29;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+6);
						cout << " ";
						gotoxy(11,thaotac+6);
						cout << " ";				
					}
					else if (c == UP)
					{
						thaotac--;
						if (thaotac <= 0) {
							thaotac = 0;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+8);
						cout << " ";
						gotoxy(11,thaotac+8);
						cout << " ";	
					}
					else if (c == ESC)
					{
						exit = true;
					}
					else if (c == ENTER) {
						Fix_Data_LTC(ds,thaotac,k);
						GhiFile_LTC(ds);
						ClearTable();
						Draw_LTC(ds,k);
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
					}
				}
				exit = false;
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 3) {
				exit = false;
				ClearTable();
				ClearChoice();
				Draw_LTC(ds,k);
				int thaotac=0;
				gotoxy(5,7);
				cout << ">";
				gotoxy(11,7);
				cout << "<";
				while (!exit) {
					char c;
					c = getch();
					if (c == DOWN)
					{
						thaotac++;
						if (thaotac >=(ds.n-k-1)) {
							thaotac=(ds.n-k-1);
						}
						if (thaotac >= 30) {
							thaotac=29;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+6);
						cout << " ";
						gotoxy(11,thaotac+6);
						cout << " ";				
					}
					else if (c == UP)
					{
						thaotac--;
						if (thaotac <= 0) {
							thaotac = 0;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+8);
						cout << " ";
						gotoxy(11,thaotac+8);
						cout << " ";	
					}
					else if (c == ESC)
					{
						exit = true;
					}
					else if (c == ENTER) {
					
					}
				}
				exit = false;
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			}
			else if (thaoTac == 4) {
				exit = false;
				ClearTable();
				ClearChoice();
				Draw_LTC(ds,k);
				int thaotac=0;
				gotoxy(5,7);
				cout << ">";
				gotoxy(11,7);
				cout << "<";
				while (!exit) {
					char c;
					c = getch();
					if (c == DOWN)
					{
						thaotac++;
						if (thaotac >=(ds.n-k-1)) {
							thaotac=(ds.n-k-1);
						}
						if (thaotac >= 30) {
							thaotac=29;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+6);
						cout << " ";
						gotoxy(11,thaotac+6);
						cout << " ";				
					}
					else if (c == UP)
					{
						thaotac--;
						if (thaotac <= 0) {
							thaotac = 0;
						}
						gotoxy(5,thaotac+7);
						cout << ">";
						gotoxy(11,thaotac+7);
						cout << "<";
						//
						gotoxy(5,thaotac+8);
						cout << " ";
						gotoxy(11,thaotac+8);
						cout << " ";	
					}
					else if (c == ESC)
					{
						exit = true;
					}
					else if (c == ENTER) {
						int temp;
						temp = ds.nodett[thaotac+k]->MALOPTC;
						
					}
				}
				exit = false;
				ClearTable();
				Draw_LTC(ds,k);
				ClearChoice();
				DrawBoxItemLTC();
			} 
			
		}
		//	highlight thao tac duoc chon
		ChoiceLTC(thaoTac,140);
		// dua cac thao tac khac ve mau mac dinh
		TextColor(DEN);
	}
