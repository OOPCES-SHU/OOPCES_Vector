//
// Created by He stu on 2023/10/15.
//

#ifndef OOPCES_VECTOR_MYVECTOR_H
#define OOPCES_VECTOR_MYVECTOR_H

template<typename T>
class MyVector
{
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
    void clear(); //清空
    void reverse(unsigned long long _capacity); //改变容量
    T & at(unsigned long long index); //下标
    T* begin() const; //返回第一个元素的指针
    T* end() const; //返回最后一个元素的指针
    typedef T* iterator;//迭代器

    MyVector & operator=(const MyVector<T> &other); //赋值
    MyVector operator+(const MyVector<T> &other); //加法
    MyVector operator+=(const MyVector<T> &other); //加法
    MyVector operator==(const MyVector<T> &other); //等于
    MyVector operator!=(const MyVector<T> &other); //不等于
    T & operator[](unsigned long long index); //下标

    friend std::ostream operator<<(std::ostream & out , const MyVector<T> & Vector);
    friend std::istream operator>>(std::istream & in , const MyVector<T> & Vector);
private:
    T *data; //数据
    unsigned long long len; //当前长度
    unsigned long long capacity; //容量
};

#endif //OOPCES_VECTOR_MYVECTOR_H
