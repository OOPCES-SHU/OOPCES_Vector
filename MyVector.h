//MyVector.h
#ifndef OOPCES_VECTOR_MYVECTOR_H
#define OOPCES_VECTOR_MYVECTOR_H
#include <iostream>

template<typename T>
class MyVector
{
private:
    T *data; //数据
    unsigned long long len; //当前长度
    unsigned long long capacity; //容量
    class iterator{
        /*
         *  写 迭代器 写 迭代器
         *  写 迭代器 写 迭代器
         *  写 迭代器 写 迭代器
         *  写 迭代器 写 迭代器
         * */
    };
public:
    MyVector(); //默认构造函数
    MyVector(int _size);
    MyVector(const MyVector<T>& copy); //拷贝构造函数

    MyVector(int size , const T& initial); //构造函数
    ~MyVector();  //析构函数
    unsigned long long size() const;
    void push_back(const T& element); //在后面增加一个元素
    void pop_back(); // 删除最后一个元素，减少容量
    void insert(unsigned long long index, const T& element); //在index处插入一个元素
    void erase(unsigned long long index); //删除index处的元素
    bool clear(); //清空
    void reverse(unsigned long long _capacity); //改变容量
    T & at(unsigned long long index); //下标
    iterator begin() const; //返回第一个元素的指针
    iterator end() const; //返回最后一个元素的指针

    MyVector & operator=(const MyVector<T> &other); //赋值
    MyVector operator+(const MyVector<T> &other); //加法
    MyVector operator+=(const MyVector<T> &other); //加法
    MyVector operator==(const MyVector<T> &other); //等于
    MyVector operator!=(const MyVector<T> &other); //不等于
    T & operator[](unsigned long long index); //下标

    typedef iterator iterator;
    friend std::istream & operator>>(std::istream & is, MyVector<T> & v); //输入
    friend std::ostream & operator<<(std::ostream & os, MyVector<T> & v); //输出
};

template<typename T>
MyVector<T>::MyVector() //默认构造函数
:len(0),capacity(5),data(new T[5])
{}

template<typename T> 
MyVector<T>::MyVector(int _size) //构造函数
:len(_size),capacity(_size + 5),data(new T[_size + 5])
{}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& copy) //深拷贝构造函数
:data(nullptr)
{
    len = copy.len;
    capacity = copy.capacity;
    data = new T[copy.capacity];
    for(int i=0 ; i<copy.len ; i++)
    {
        data[i] = copy.data[i];
    }
}

template<typename T>
MyVector<T>::MyVector(int size , const T& initial) //构造函数,将size个位置初始化为initial
{
    len = size;
    capacity = size + 5;
    data = new T[size + 5];
    for(int i=0;i<len;i++){
        data[i] = initial;
    }
}

template<typename T>
MyVector<T>::~MyVector() { 
    if(data!= nullptr){
        delete[] data; 
        data = nullptr;
    }
}

#endif //OOPCES_VECTOR_MYVECTOR_H
