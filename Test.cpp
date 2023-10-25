
//Test.cpp
#include "MyVector.h"
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

//一维double向量
static My::MyVector<double > VecD = {1,2.2,2,3.1415};
//一维string向量
static std::string strTemp[7] = {"I","am","a","student","in","SHU","University"};
static My::MyVector<std::string > VecString(strTemp);
//一维char向量
static My::MyVector<char > VecChtemp = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};
static My::MyVector<char > VecCh(VecChtemp);
//七维(行)char向量,列数是动态的,即可以随字符串的长度变化
//如"student"代表行数为3 长度为7列数一共7(加上'\0')(列数以0开始)
static My::MyVector<char > VecChDim7[7] = {My::MyVector(2,'a'),"am","a","student","in","SHU","University"};
//3x3int向量
static My::MyVector<int > VecINTDim3[3] = {{1,2,3},{4,5,6},{7,8,9}};

//int color(int c){ //2绿色 3浅蓝色 7白色 8灰色 9蓝色 10绿色 11浅蓝色 12红色 13粉红色 14黄色 15白色 0黑色 1蓝色 4红色 5紫色 6黄色
//    //SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
//    return c;
//}

static int color(int c){ //2绿色 3浅蓝色 7白色 8灰色 9蓝色 10绿色 11浅蓝色 12红色 13粉红色 14黄色 15白色 0黑色 1蓝色 4红色 5紫色 6黄色
    //SetConsoleTextAttribute是API设置控制台窗口字体颜色和背景色的函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
    return c;
}

static inline int Seed()
{
//    srand((unsigned)time(nullptr)); //设置随机数种子
    return rand()%15 + 1; //生成 0-14 之间的随机数
}

//赋值
static void TestAssign()
{

    std::cout << "执行对象构造...\n";
    color(Seed());
    std::cout << "初始化列表:\nMy::MyVector<double> VecD = {1,2.2,2,3.1415}\n\n";

    color(Seed());
    std::cout << "通过数组构造:\n"
    << "std::string strTemp[7] = {\"I\",\"am\",\"a\",\"student\",\"in\",\"SHU\",\"University\"}\n"
    << "My::MyVector<std::string> VecString(strTemp)\n\n";

    color(Seed());
    std::cout << "拷贝构造:\n"
    << "My::MyVector<char > VecChtemp = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'}\n"
    << "My::MyVector<char> VecCh(VecChtemp)\n\n";

    color(Seed());
    std::cout <<"初始化列表中调用构造函数:\n"
    << "My::MyVector<char> VecChDim7[7] = {My::MyVector(2,'a'),\"am\",\"a\",\"student\",\"in\",\"SHU\",\"University\"}\n\n";

    color(Seed());
    std::cout << "初始化3x3向量构造:\n"
    <<  "My::MyVector<int> VecINTDim3[3] = {{1,2,3},{4,5,6},{7,8,9}}\n";
}


static void TestShow()
{
    color(15);
    std::cout << "[执行输出]调用 .print()成员函数及重载operator[]\n";

    color(Seed());
    std::cout << "输出VecD: 使用负数下标反向遍历\n"
    << "逆向前";
    VecD.print();
    for(auto i:{-1,-2,-3,-4})
        std::cout << VecD[i] << ' ';
    std::cout << "\n";

    color(Seed());
    std::cout << "逆向输出VecString:\n";
    VecString.print();
    std::cout << "\n";

    color(Seed());
    std::cout << "输出VecCh:\n";
    VecCh.print();
    std::cout << "\n";

    color(Seed());
    std::cout << "循环输出VecINTDim3 调用重载operator<<:\n";
    for(auto it:{0,1,2})
        std::cout << VecINTDim3[it];
    std::cout << "\n";

    color(Seed());
    std::cout << "逆向循环输出VecChDim7{0,1,2,3} 调用 .print():\n";
    for(auto it:{0,1,2,3})
        VecChDim7[it].print();
    std::cout << "\n循环输出VecChDim7{4,5,6} 调用重载operator<<:\n";
    for(auto it:{4,5,6})
        std::cout << VecChDim7[it];
    std::cout << "\n";
}

static void TestReverse()
{
    color(15);
    std::cout << "[执行反转]调用 .reverse()成员函数\n";

    color(Seed());
    std::cout << "反转并输出VecD:\n";
    VecD.reverse();
    VecD.print();
    std::cout << "\n";

    color(Seed());
    std::cout << "反转并输出VecString:\n";
    VecString.reverse();
    VecString.print();
    std::cout << "\n";

    color(Seed());
    std::cout << "反转并输出VecCh:\n";
    VecCh.reverse();
    VecCh.print();
    std::cout << "\n";

    color(Seed());
    std::cout << "循环反转输出VecINTDim3:\n";
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].reverse();
        VecINTDim3[it].print();
    }
    std::cout << "\n";

    color(Seed());
    std::cout << "循环输出VecChDim7:\n";
    for(auto it:{0,1,2,3,4,5,6})
    {
        VecChDim7[it].reverse();
        VecChDim7[it].print();
    }
    std::cout << "\n";
}

static void TestIterator()
{
    color(15);
    std::cout << "使用迭代器 My::MyVector<T>::iterator it\n";

    color(10);
    std::cout << "循环迭代输出VecD:\n"
    << "采用迭代器后自增 it++: ";
    color(3);
    for(auto it=VecD.begin();it!=VecD.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    color(10);
    std::cout << "循环迭代输出VecCh:\n"
              << "采用迭代器前自减 --it:\n"
              << "for(auto it=VecCh.end();it!=VecCh.begin();)\n"
                 "{\n"
                 "        std::cout << *(--it) << \" \";\n"
                 "}\n";
    color(3);
    for(auto it=VecCh.end();it!=VecCh.begin();)
    {
        std::cout << *(--it) << " ";
    }
    std::cout << "\n\n";

    color(10);
    std::cout << "循环迭代输出VecCh:\n"
              << "采用迭代器后自减 it--:\n"
              << "for(auto it=VecCh.end();it!=VecCh.begin();)\n"
                 "{\n"
                 "        std::cout << *(it--) << \" \";\n"
                 "}\n";
    color(3);
    for(auto it=VecCh.end();it!=VecCh.begin();)
    {
        std::cout << *(it--) << " ";
    }
    std::cout << '\n';
}

static void TestException()
{
    color(15);
    std::cout << "[执行越界异常捕获] 通过 .at()\n";
    try{
        color(10);
        std::cout << "VecD.at(INT_MAX)\n";
        VecD.at(INT_MAX);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try{
        color(10);
        std::cout << "VecString.at(100)\n";
        VecString.at(100);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try{
        color(10);
        std::cout << "VecCh.at(-23)\n";
        VecCh.at(-23);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try{
        color(10);
        std::cout << "VecINTDim3[0].at(-1)\n";
        VecINTDim3[0].at(-1);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
}

static void TestInsert()
{
    color(15);
    std::cout << "[执行插入] 使用 .insert()\n";

    color(3);
    std::cout << "插入并输出VecD:\n"
    << "插入前:";
    VecD.print();
    std::cout << "[插入位置index=1 插入元素double 114.1]\n";
    try {
        std::cout << "尝试插入判断异常...\n";
        VecD.insert(1, 114.1);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    VecD.print();
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "插入并输出VecString:\n"
              << "插入前:";
    VecString.print();
    std::cout << "[插入位置index=3 插入元素std::string ILOVEU]\n";
    try {
        std::cout << "尝试插入判断异常...\n";
        VecString.insert(3, "ILOVEU");
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    VecString.print();
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "插入并输出VecCh:\n"
              << "插入前:";
    VecCh.print();
    std::cout << "[插入位置index=0 插入元素char V]\n";
    try{
        std::cout << "尝试插入判断异常...\n";
        VecCh.insert(0,'V');
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    VecCh.print();
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "循环插入并输出VecINTDim3:\n"
              << "插入前:\n";
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    std::cout << "[插入位置VecINTDim3[0] index=299 插入元素int 1919]\n"
    << "[插入位置VecINTDim3[1] index=-2 插入元素int 124]\n"
    << "[插入位置VecINTDim3[2] index=2 插入元素int 114514]\n";
    try {
        std::cout << "尝试插入判断异常...\n";
        VecINTDim3[0].insert(299, 1919);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecINTDim3[1].insert(-2, 124);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecINTDim3[2].insert(2, 114514);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "循环插入并输出VecChDim7:\n"
              << "插入前:\n";
    for(auto it:{0,1,2,3,4,5,6})
    {
        VecChDim7[it].print();
    }
    std::cout << "[插入位置VecChDim7[0] index=-20 插入元素ch 's']\n"
              << "[插入位置VecChDim7[3] index=0 插入元素ch 'Q']\n"
              << "[插入位置VecChDim7[6] index=100 插入元素ch 'M']\n";
    try {
        std::cout << "尝试插入判断异常...\n";
        VecChDim7[0].insert(-20, 's');
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecChDim7[3].insert(0, 'Q');
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecChDim7[6].insert(100, 'M');
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    for(auto it:{0,3,6})
    {
        VecChDim7[it].print();
    }
    std::cout << "\n";
}

static void TestErase()
{
    color(15);
    std::cout << "[执行删除] 使用 .erase()\n";

    color(3);
    std::cout << "删除并输出VecD:\n"
              << "删除前:";
    VecD.print();
    std::cout << "[删除位置index=-30]\n";
    try {
        std::cout << "尝试删除判断异常...\n";
        VecD.erase(-30);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    VecD.print();
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "删除并输出VecString:\n"
              << "删除前:";
    VecString.print();
    std::cout << "[删除位置index=100]\n";
    try {
        std::cout << "尝试删除判断异常...\n";
        VecString.erase(100);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    VecString.print();
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "删除并输出VecCh:\n"
              << "删除前:";
    VecCh.print();
    std::cout << "[删除位置index=0]\n";
    try{
        std::cout << "尝试删除判断异常...\n";
        VecCh.erase(0);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    VecCh.print();
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "循环删除并输出VecINTDim3:\n"
              << "删除前:\n";
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    std::cout << "[删除位置VecINTDim3[0] index=9 ]\n"
              << "[删除位置VecINTDim3[1] index=1 ]\n"
              << "[删除位置VecINTDim3[2] index=-2 ]\n";
    try {
        std::cout << "尝试删除判断异常...\n";
        VecINTDim3[0].erase(9);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecINTDim3[1].erase(1);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecINTDim3[2].erase(-2);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    std::cout << "\n";
    std::cout << "按下任意键继续...\n";
    getchar();


    color(3);
    std::cout << "循环删除并输出VecChDim7:\n"
              << "删除前:\n";
    for(auto it:{0,1,2,3,4,5,6})
    {
        VecChDim7[it].print();
    }
    std::cout << "[删除位置VecChDim7[0] index=1 ]\n"
              << "[删除位置VecChDim7[3] index=2 ]\n"
              << "[删除位置VecChDim7[6] index=-5 ]\n";
    try {
        std::cout << "尝试插入判断异常...\n";
        VecChDim7[0].erase(1);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecChDim7[3].erase(-2);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    try {
        VecChDim7[6].erase(-5);
    }catch (const std::string & str){
        color(12);
        std::cout << str << '\n';
    }
    color(15);
    for(auto it:{0,3,6})
    {
        VecChDim7[it].print();
    }
    std::cout << "\n";
}

static void TestPushBack()
{
    color(15);
    std::cout << "[执行追加]调用 .push_back成员函数\n";

    color(3);
    std::cout << "追加并输出VecD:\n"
    << "追加前:";
    VecD.print();
    color(15);
    std::cout << "[追加元素double 114.1  double 121]\n";
    VecD.push_back(114.1);
    VecD.push_back(121);
    VecD.print();
    std::cout << "\n";

    color(3);
    std::cout << "追加并输出VecString:\n"
    << "追加前:";
    VecString.print();
    color(15);
    std::cout << "[追加元素std::string ILOVEU]\n";
    VecString.push_back("ILOVEU");
    VecString.print();
    std::cout << "\n";

    color(3);
    std::cout << "追加并输出VecCh:\n"
    << "追加前:";
    VecCh.print();
    color(15);
    std::cout << "[追加元素char V]\n";
    VecCh.push_back('V');
    VecCh.print();
    std::cout << "\n";

    color(3);
    std::cout << "循环追加输出VecINTDim3:\n";
    std::cout << "追加前:";
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    color(15);
    std::cout << "VecINTDim3[0] [追加元素int 1919]\n";
    VecINTDim3[0].push_back(1919);
    std::cout << "VecINTDim3[1] [追加元素int 124]\n";
    VecINTDim3[1].push_back(124);
    std::cout << "VecINTDim3[2] [追加元素int 114514]\n";
    VecINTDim3[2].push_back(114514);
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    std::cout << "\n";

    color(3);
    std::cout << "循环追加并输出VecChDim7:\n";
    std::cout << "追加前:";
    for(auto it:{0,1,2,3,4,5,6})
    {
        VecChDim7[it].print();
    }
    color(15);
    std::cout << "VecChDim7[0] [追加元素ch 's']\n";
    VecChDim7[0].push_back('s');
    std::cout << "VecChDim7[3] [追加元素ch 'Q']\n";
    VecChDim7[3].push_back('Q');
    std::cout << "VecChDim7[6] [追加元素ch 'M']\n";
    VecChDim7[6].push_back('M');
    for(auto it:{0,3,6})
    {
        VecChDim7[it].print();
    }
    std::cout << "\n";
}

static void TestPopBack()
{
    color(15);
    std::cout << "[执行弹出]调用 .pop_back成员函数\n";

    color(3);
    std::cout << "弹出并输出VecD:\n"
    << "弹出前:";
    VecD.print();
    color(15);
    std::cout << "[弹出元素]\n";
    VecD.pop_back();
    VecD.print();
    std::cout << "\n";

    color(3);
    std::cout << "弹出并输出VecString:\n"
    << "弹出前:";
    VecString.print();
    color(15);
    std::cout << "[循环弹出所有元素]\n";
    long long  size = VecString.size();
    for(auto it=0;it<size;it++)
    {
        VecString.pop_back();
    }
    VecString.print();
    std::cout << "\n";

    color(3);
    std::cout << "弹出并输出VecCh:\n"
    << "弹出前:";
    VecCh.print();
    color(15);
    std::cout << "[弹出元素]\n";
    VecCh.pop_back();
    VecCh.print();
    std::cout << "\n";

    color(3);
    std::cout << "循环弹出输出VecINTDim3:\n";
    std::cout << "弹出前:";
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    color(15);
    std::cout << "VecINTDim3[0] [弹出元素]\n";
    VecINTDim3[0].pop_back();
    std::cout << "VecINTDim3[1] [弹出元素]\n";
    VecINTDim3[1].pop_back();
    std::cout << "VecINTDim3[2] [弹出元素]\n";
    VecINTDim3[2].pop_back();
    for(auto it:{0,1,2})
    {
        VecINTDim3[it].print();
    }
    std::cout << "\n";

    color(3);
    std::cout << "循环弹出并输出VecChDim7:\n";
    std::cout << "弹出前:";
    for(auto it:{0,1,2,3,4,5,6})
    {
        VecChDim7[it].print();
    }
    color(15);
    std::cout << "VecChDim7[0] [弹出元素]\n";
    VecChDim7[0].pop_back();
    std::cout << "VecChDim7[3] [两次弹出元素]\n";
    VecChDim7[3].pop_back();
    VecChDim7[3].pop_back();
    std::cout << "VecChDim7[6] [弹出元素]\n";
    VecChDim7[6].pop_back();
    for(auto it:{0,3,6})
    {
        VecChDim7[it].print();
    }
}

//测试函数入口
//flag 用于退出
void TestGate(int gate,bool &flag)
{
    switch (gate)
    {
        case 0:
            flag = true;
            break;
        case 1:
            TestAssign();
            break;
        case 2:
            TestShow();
            break;
        case 3:
            TestReverse();
            break;
        case 4:
            TestIterator();
            break;
        case 5:
            TestException();
            break;
        case 6:
            TestInsert();
            break;
        case 7:
            TestErase();
            break;
        case 8:
            TestPushBack();
            break;
        case 9:
            TestPopBack();
            break;
        default:
            std::cout << "输入错误，请重新输入\n";
            system("pause");
            break;
    }
}

