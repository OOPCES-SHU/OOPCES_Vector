
//Menu.cpp
#include "MyVector.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), \
                                       BACKGROUND_RED |                   \
                                           BACKGROUND_GREEN   |          \
                                           BACKGROUND_BLUE |           \
                                           BACKGROUND_INTENSITY)
#define IN_DEFAULT SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), \
                                           FOREGROUND_RED |                 \
                                               FOREGROUND_GREEN |           \
                                               FOREGROUND_BLUE)

#define IN_RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), \
                                       BACKGROUND_RED |                 \
                                           BACKGROUND_INTENSITY)



void Gotoxy(short x, short y)
{
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}


#define UPKEY 72
#define DOWNKEY 80

void Menu() //主菜单
{

    std::cout << ("==--------------------向量测试------------------==\n")
     << ("0) 退出程序                                      |\n")
     << ("1) 输出测试                                      |\n")
     << ("2) 向量反转测试                                  |\n")
     << ("3) 迭代器测试                                    |\n")
     << ("4) 越界异常捕获测试                              |\n")
     << ("5) 插入测试                                      |\n")
     << ("6) 删除测试(erase & clear)                       |\n")
     << ("7) 追加测试(push_back)                           |\n")
     << ("8) 弹出测试(pop_back)                            |\n")
     << ("==----------------------------------------------==\n")
     << ("请使用↑、↓和enter来实现选择和执行命令\n")
     << ("或者输入每个命令前面的数字来执行命令<0 - 9>\n");
}

void CursorPos1(int x) //光标覆盖菜单
{
    switch (x)
    {
        case 0:
            std::cout << ("0) 退出程序");
            break;
        case 1:
            std::cout << ("1) 输出测试");
            break;
        case 2:
            std::cout << ("2) 向量反转测试");
            break;
        case 3:
            std::cout << ("3) 迭代器测试");
            break;
        case 4:
            std::cout << ("4) 越界异常捕获测试");
            break;
        case 5:
            std::cout << ("5) 插入测试");
            break;
        case 6:
            std::cout << ("6) 删除测试(erase & clear)");
            break;
        case 7:
            std::cout << ("7) 追加测试(push_back)");
            break;
        case 8:
            std::cout << ("8) 弹出测试(pop_back)");
            break;
    }
}

int CursorOpr(int line, int deta, int lower, int upper, void (*p)(int))
{
/*
line：当前光标所在行数
deta：行数与菜单选项的差值。比如在main菜单中选项(0)在第2行(行数从0开始计算)，所以deta等于2，即2 - 0
upper, lower：选项的上下界
(*P)(int)：函数指针，选择哪个覆盖菜单
*/
    char c1, c2;
    Gotoxy(0, line);
    do
    {
        c2 = _getch();
        if (c2 == DOWNKEY)
        {
            Gotoxy(0, line);
            IN_DEFAULT; //选择默认色
            (*p)(line - deta); //覆盖，实现退选
            if (line == upper) //如果已经到了上界，则返回下界，实现滚动高亮
                line = lower;
            else
                ++line; //行数+1
            Gotoxy(0, line);
            IN_WHITE;
            (*p)(line - deta);
        }
        if (c2 == UPKEY)
        {
            Gotoxy(0, line);
            IN_DEFAULT;
            (*p)(line - deta);
            if (line == lower)
                line = upper;
            else
                --line;
            Gotoxy(0, line);
            IN_WHITE;
            (*p)(line - deta);
        }
    } while ((c1 = _getch()) != '\r');
    IN_RED;
    Gotoxy(0, line);
    (*p)(line - deta);
    IN_DEFAULT;
    Gotoxy(0, 11 + 5);
    system("pause");
    return line - deta;
}

void MenuStart() {
    int n, line = 1; // 对应menu()的1）
    char c1, c2;
    bool b;
    while (1) {
        system("cls");
        Menu();
        if ((c1 = _getch()) == -32) {
            CursorOpr(line,1 , 1, 9, CursorPos1);
        } else {
            char tmp;
            scanf("%c", &tmp);
            if (tmp >= '0' && tmp <= '9')
                n = tmp - '0';
            else
                n = tmp;
        }
    }
}