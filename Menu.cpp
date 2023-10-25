
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

#define UPKEY 72
#define DOWNKEY 80

static bool flag = false;

static int color(int c){ //2绿色 3浅蓝色 7白色 8灰色 9蓝色 10绿色 11浅蓝色 12红色 13粉红色 14黄色 15白色 0黑色 1蓝色 4红色 5紫色 6黄色
    //SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
    return c;
}

static inline int Seed()
{
    srand((unsigned)time(nullptr)); //设置随机数种子
    return rand()%15 + 1; //生成 0-14 之间的随机数
}

void Gotoxy(short x, short y)
{
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void Menu() //主菜单
{

    color(14);
    std::cout << ("==--------------------向量测试------------------==\n")
     << ("0) 退出程序                                      |\n")
     << ("1) 赋值测试                                      |\n")
     << ("2) 输出测试                                      |\n")
     << ("3) 向量反转测试                                  |\n")
     << ("4) 迭代器测试                                    |\n")
     << ("5) 越界异常捕获测试                              |\n")
     << ("6) 插入测试                                      |\n")
     << ("7) 删除测试(erase & clear)                       |\n")
     << ("8) 追加测试(push_back)                           |\n")
     << ("9) 弹出测试(pop_back)                            |\n")
     << ("==----------------------------------------------==\n")
     << ("请使用↑、↓和enter来实现选择和执行命令\n")
     << ("或者输入每个命令前面的数字来执行命令<0 - 9>\n");
}

void CursorPos1(int x) //光标覆盖菜单
{
    /*
     测试函数之前都使用一次GotoXY()调整输出位置
     */
    switch (x)
    {
        case 0:
            std::cout << "0) 退出程序";
            break;
        case 1:
            std::cout << "1) 赋值测试";
            break;
        case 2:
            std::cout << "2) 输出测试";
            break;
        case 3:
            std::cout << "3) 向量反转测试";
            break;
        case 4:
            std::cout << "4) 迭代器测试";
            break;
        case 5:
            std::cout << "5) 越界异常捕获测试";
            break;
        case 6:
            std::cout << "6) 插入测试";
            break;
        case 7:
            std::cout << "7) 删除测试(erase & clear)";
            break;
        case 8:
            std::cout << "8) 追加测试(push_back)";
            break;
        case 9:
            std::cout << "9) 弹出测试(pop_back)";
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
    void TestGate(int gate,bool &flag);
    char c1, c2;
    Gotoxy(0, line);
    do
    {
        c2 = _getch();
        if (c2 == DOWNKEY)
        {
            Gotoxy(0, line);
//            IN_DEFAULT; //选择默认色
            color(14);
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
//            IN_DEFAULT;
            color(14);
            (*p)(line - deta);
            if (line == lower)
                line = upper;
            else
                --line;
            Gotoxy(0, line);
            IN_WHITE;
            (*p)(line - deta);
        }
    } while ((c1 = _getch()) != '\r' && !flag);
    IN_RED;
    Gotoxy(0, line);
    (*p)(line - deta);
    color(9);
    Gotoxy(0, 11 + 5);
    TestGate(line - deta,flag);
    system("pause");
    return line - deta;
}

void MenuStart() {
    int n, line = 2; // 对应menu()的1）
    char c1, c2;
    bool b;
    while (!flag) {
        system("cls");
        Menu();
        if ((c1 = _getch()) == -32) {
            CursorOpr(line,1 , 1, 10, CursorPos1);
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