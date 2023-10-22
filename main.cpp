//main.cpp
#include "MyVector.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>


//声明
void Gotoxy(short x, short y);
void Menu(); //主菜单
void CursorPos1(int x); //光标覆盖菜单
int CursorOpr(int line, int deta, int lower, int upper, void (*p)(int));
void MenuStart();



int main()
{
    system("chcp 65001");
    system("cls");
    MenuStart();
    return 0;
}