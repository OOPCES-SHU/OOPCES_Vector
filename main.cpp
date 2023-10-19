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


//一维double向量
static My::MyVector<double > VecD = {1,2.2,2,3.1415};
//一维string向量
static My::MyVector<std::string > VecString = {"I","am","a","student","in","SHU","University"};
//一维char向量
static My::MyVector<char > VecCh = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};
//七维(行)char向量,列数是动态的,即可以随字符串的长度变化
//如"student"代表行数为3 长度为7列数一共7(加上'\0')(列数以0开始)
static My::MyVector<char > VecChDim7[7] = {My::MyVector(2,'a'),"am","a","student","in","SHU","University"};
//3x3int向量
static My::MyVector<int > VecINTDim3[3] = {{1,2,3},{4,5,6},{7,8,9}};



int main()
{
//    MyVector<int> vec(10);
    // vec.push_back(10);
    system("chcp 65001");
    system("cls");
//    VecString.reverse();
//    VecString.print();
//    VecD.print();
//    VecD.reverse();
//    VecD.print();
//    VecCh.print();
//    VecChDim7[0].print();
//    VecINTDim3[0].print();
    MenuStart();


    return 0;
}