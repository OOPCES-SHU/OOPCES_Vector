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
    void reserve(unsigned long long _capacity); //改变容量
    T & at(unsigned long long index); //下标
    iterator begin() const; //返回第一个元素的指针
    iterator end() const; //返回最后一个元素的指针

    MyVector & operator=(const MyVector<T> &other); //赋值
    MyVector operator+(const MyVector<T> &other); //加法
    MyVector operator+=(const MyVector<T> &other); //加法
    bool operator==(const MyVector<T> &other) const;
    bool operator!=(const MyVector<T> &other) const; //不等于
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
MyVector<T>::~MyVector()
{
    if(data!= nullptr)
    {
        delete[] data; 
        data = nullptr;
    }
}

template<typename T>
void MyVector<T>::push_back(const T &element)
{
    len++;
    if(len >= capacity)
    {
        capacity = len + 5;
        reserve(capacity);
    }
    data[len-1] = element;
}

template<typename T>
void MyVector<T>::pop_back()
{
    len--;
    if (len < capacity / 2)
    {
        unsigned long long newCapacity = capacity / 2;
        T* newData = new T[newCapacity];
        for (unsigned long long i = 0; i < len; i++)
        {
            newData[i] = data[i];
        }
        delete[] data; // 重新分配内存防止出错
        capacity = newCapacity;
        data = newData;
    }
}

template<typename T>
void MyVector<T>::insert(unsigned long long index, const T& element)
{
    try
    {
        if (index < 0 || index > len)
        { throw "error index!\n"; }
    }catch(const char *error)
    {
        std::cerr << error;
        return;
    }

    len++;
    capacity = len + 5;
    MyVector<T> temp(this->data);
    delete[] data;
    data = new T[capacity];

    if (len >= capacity)
    {
        capacity = len + 5;
        reserve(capacity);
    }

    for (unsigned long long i = 0; i < index; i++)
    {
        data[i] = temp.data[i];
    }
    data[index] = element;
    for (unsigned long long i = index + 1; i < len; i++)
    {
        data[i] = temp.data[i - 1];
    }
}

template<typename T>
void MyVector<T>::erase(unsigned long long index)
{
    try
    {
        if (index < 0 || index > len)
        { throw "error index!\n"; }
    }catch(const char *error)
    {
        std::cerr << error;
        return;
    }

    len--;
    capacity = len + 5;
    MyVector<T> temp(this->data);
    delete[] data;
    data = new T[capacity];

    if (len >= capacity)
    {
        capacity = len + 5;
        reserve(capacity);
    }

    for (unsigned long long i = 0; i < index; i++)
    {
        data[i] = temp.data[i];
    }
    for (unsigned long long i = index; i < len; i++)
    {
        data[i] = temp.data[i + 1];
    }
}

template<typename T>
bool MyVector<T>::clear()
{
    if(data!= nullptr)
    {
        delete[] data;
        data = nullptr;
        len = 0;
        capacity = 0;
        return true;
    }
    return false;
}

template<typename T>
void MyVector<T>::reserve(unsigned long long _capacity)
{
    if(_capacity >= capacity)
    {
        T* newData = new T[_capacity];
        for(unsigned long long i=0 ; i<len ; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = _capacity;
    }
}

template<typename T>
T & MyVector<T>::at(unsigned long long index)
{
    if(index >= 0 && index < capacity)
    {
        return data[index];
    }
    else
    {
        throw -1;
    }
}

//********************************************************
//*
//*   这里   iterator begin() const; //返回第一个元素的指针
//*          iterator end() const; //返回最后一个元素的指针
//*
//********************************************************

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &other)//赋值
{
    if (this == &other) {
        return *this;
    }
    delete[] data;
    len = other.len;
    capacity = other.capacity;
    data = new T[capacity];
    for (unsigned long long i = 0; i < len; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

template<typename T>
MyVector<T> MyVector<T>::operator+(const MyVector<T> &other) //加法
{
    MyVector<T> result;
    result.len=this->len+other.len;
    result.capacity=this->capacity+other.capacity;
    result.data = new T[result.capacity];
    unsigned long long i = 0;
    for(i=0;i<this->len;i++)
    {
        result.data[i]=this->data[i];
    }
    for(i=this->len;i<result.len;i++)
    {
        result.data[i]=other.data[i];
    }
    return result;
}

template<typename T>
MyVector<T> MyVector<T>::operator+=(const MyVector<T> &other) {
    // 确保当前对象有足够的容量来容纳另一个对象的元素
    if (len + other.len > capacity) {
        // 如果容量不够，扩展容量
        reserve(len + other.len);
    }

    // 复制另一个对象的元素到当前对象的末尾
    for (unsigned long long i = 0; i < other.len; ++i) {
        data[len + i] = other.data[i];
    }

    // 更新当前对象的长度
    len += other.len;

    return *this;
}

template<typename T>
bool MyVector<T>::operator==(const MyVector<T> &other) const {
    if (len != other.len) {
        return false;
    }
    for (unsigned long long i = 0; i < len; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector<T> &other) const {
    if (len != other.len) {
        return true;
    }
    for (unsigned long long i = 0; i < len; ++i) {
        if (data[i] != other.data[i]) {
            return true;
        }
    }
    return false;
}

template<typename T>
T&  MyVector<T>::operator[](unsigned long long index)
{
    T result;
    result=this->data[index];
    return result;
}
#endif //OOPCES_VECTOR_MYVECTOR_H