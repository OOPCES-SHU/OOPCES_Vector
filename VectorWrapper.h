// VectorWrapper.h

#ifndef OOPCES_VECTOR_VECTORWRAPPER_H
#define OOPCES_VECTOR_VECTORWRAPPER_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class VectorWrapper{
public:
    // 构造函数
    VectorWrapper();
    VectorWrapper(int size);

    // 析构函数
    ~VectorWrapper();

    // 赋值函数
    VectorWrapper<T>& operator=(const VectorWrapper<T>& other);

    // 运算符重载
    T& operator[](int index);
    const T& operator[](int index) const; //这个意义是什么？
    VectorWrapper<T> operator+(const VectorWrapper<T>& other);
    VectorWrapper<T> operator-(const VectorWrapper<T>& other);
    VectorWrapper<T>& operator+=(const VectorWrapper<T>& other);
    VectorWrapper<T>& operator-=(const VectorWrapper<T>& other);
    bool operator==(const VectorWrapper<T>& other) const;
    bool operator!=(const VectorWrapper<T>& other) const;
    friend std::istream& operator>>(std::istream& is, VectorWrapper<T>& v);
    friend std::ostream& operator<<(std::ostream& os, const VectorWrapper<T>& v);

private:
    std::vector<T> data; //拿vector 做 vector
};

#endif //OOPCES_VECTOR_VECTORWRAPPER_H
