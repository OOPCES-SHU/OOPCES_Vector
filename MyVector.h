//MyVector.h
#ifndef OOPCES_VECTOR_MYVECTOR_H
#define OOPCES_VECTOR_MYVECTOR_H
#include <iostream>
#include <format>
#include <initializer_list>

namespace My {
    template<typename T>
    class MyVector {
    private:
        T *data; //数据
        unsigned long long len; //当前长度
        unsigned long long capacity; //容量
        class iterator {
            /*
             *  写 迭代器 写 迭代器
             *  写 迭代器 写 迭代器
             *  写 迭代器 写 迭代器
             *  写 迭代器 写 迭代器
             * */
        };

    public:
        typedef iterator iterator;

        MyVector(); //默认构造函数
        MyVector(int _size);

        MyVector(const MyVector<T> &copy); //拷贝构造函数
        MyVector(int size, const T &initial); //构造函数
        MyVector(const T *other); //可用数组做初始化
        MyVector(const std::initializer_list<T> &list); //初始化列表
        ~MyVector();  //析构函数
        unsigned long long size() const;

        void push_back(const T &element); //在后面增加一个元素
        void pop_back(); // 删除最后一个元素，减少容量
        void insert(unsigned long long index, const T &element); //在index处插入一个元素
        void erase(unsigned long long index); //删除index处的元素
        bool clear(); //清空
        void reserve(unsigned long long _capacity); //改变容量
        void reverse(); //反转
        void print(); //输出
        T &at(unsigned long long index); //下标

        iterator begin() const; //返回第一个元素的指针
        iterator end() const; //返回最后一个元素的指针

        MyVector &operator=(const MyVector<T> &other); //赋值
        MyVector &operator=(const T *other); //可用数组
        MyVector operator+(const MyVector<T> &other); //加法
        MyVector operator+=(const MyVector<T> &other); //加法
        bool operator==(const MyVector<T> &other) const;

        bool operator!=(const MyVector<T> &other) const; //不等于

        T &operator[](unsigned long long index); //下标
    };

    template<typename T>
    MyVector<T>::MyVector() //默认构造函数
            :len(0), capacity(5), data(new T[5]) {}

    template<typename T>
    MyVector<T>::MyVector(int _size) //构造函数
            :len(_size), capacity(_size + 5), data(new T[_size + 5]) {}

    template<typename T>
    MyVector<T>::MyVector(const MyVector<T> &copy) //深拷贝构造函数
            :data(nullptr) {
        len = copy.len;
        capacity = copy.capacity;
        data = new T[copy.capacity];
        for (int i = 0; i < copy.len; i++) {
            data[i] = copy.data[i];
        }
    }

    template<typename T>
    MyVector<T>::MyVector(int size, const T &initial) //构造函数,将size个位置初始化为initial
    {
        len = size;
        capacity = size + 5;
        data = new T[size + 5];
        for (int i = 0; i < len; i++) {
            data[i] = initial;
        }
    }

    template<typename T>
    MyVector<T>::MyVector(const T *other)
            :data(nullptr), len(0), capacity(0) {
        unsigned long long other_len{0};
        while (other[other_len] != '\0') {
            other_len++;
        }
        len = other_len;
        capacity = other_len + 5;
        data = new T[capacity];
        for (unsigned long long i = 0; i < other_len; ++i) {
            data[i] = other[i];
        }
    }

    template<typename T>
    MyVector<T>::MyVector(const std::initializer_list<T> &list)
    :data(new T[list.size() + 5]),len(0),capacity(list.size() + 5)
    {
        for(auto it:list)
        {
            data[len++] = it;
        }
    }



    template<typename T>
    MyVector<T>::~MyVector() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
    }

    template<typename T>
    unsigned long long MyVector<T>::size() const {
        return len;
    }

    template<typename T>
    void MyVector<T>::push_back(const T &element) {
        len++;
        if (len >= capacity) {
            capacity = len + 5;
            reserve(capacity);
        }
        data[len - 1] = element;
    }

    template<typename T>
    void MyVector<T>::reverse() //反转
    {
        unsigned long long start{0};
        unsigned long long end{len - 1};
        while (start < end) {
            T temp = data[start];
            data[start] = data[end];
            data[end] = temp;
            start++;
            end--;
        }
    }

    template<typename T>
    void MyVector<T>::print() {
        std::cout << std::format("namepace[My]::vector<{}>: ", typeid(T).name());
        for (unsigned long long i = 0; i < len;) {
            std::cout << data[i++] << " ";
        }
        std::cout << '\n';
    }

    template<typename T>
    void MyVector<T>::pop_back() // 删除最后一个元素，但容量不变
    {
        len--;
        T *newData = new T[capacity];
        for (unsigned long long i = 0; i < len; i++) {
            newData[i] = data[i];
        }
        delete[] data; // 重新分配内存防止出错
        data = nullptr; // 防止出错
        data = newData;
    }

    template<typename T>
    void MyVector<T>::insert(unsigned long long index, const T &element) {
        if (index < 0 || index > len) {
            throw -1;
            return;
        }
        len++;
        if (len >= capacity)
            capacity = len + 5;
        MyVector<T> temp(this->data); // 拷贝当前对象
        delete[] data;
        data = nullptr;
        data = new T[capacity];

        for (unsigned long long i = 0; i < index; i++) {
            data[i] = temp.data[i];
        }
        data[index] = element;
        for (unsigned long long i = index + 1; i < len; i++) {
            data[i] = temp.data[i - 1];
        }
    }

    template<typename T>
    void MyVector<T>::erase(unsigned long long index) //容量不变
    {
        if (index < 0 || index > len) {
            throw -1;
            return;
        }
        len--;
        MyVector<T> temp(this->data);
        delete[] data;
        data = nullptr;
        data = new T[capacity];

        for (unsigned long long i = 0; i < index; i++) {
            data[i] = temp.data[i];
        }
        for (unsigned long long i = index; i < len; i++) {
            data[i] = temp.data[i + 1];
        }
    }

    template<typename T>
    bool MyVector<T>::clear() //只是清空，容量不变 //原对象还能进行push_back等操作
    {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
            len = 0;
            data = new T[capacity];
            return true;
        } else {
            return false;
        }
    }

    template<typename T>
    void MyVector<T>::reserve(unsigned long long _capacity) //改变容量
    {
        if (_capacity > capacity) {
            T *newData = new T[_capacity];
            for (unsigned long long i = 0; i < len; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = nullptr;
            data = newData;
            capacity = _capacity;
        }
    }

    template<typename T>
    T &MyVector<T>::at(unsigned long long index) {
        if (index >= 0 && index < capacity) {
            return data[index];
        } else {
            throw "Index out of range MyVector<T>::at";
        }
    }

//********************************************************
//*
//*   这里   iterator begin() const; //返回第一个元素的指针
//*          iterator end() const; //返回最后一个元素的指针
//*
//********************************************************

    template<typename T>
    MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other)//赋值
    {
        if (this == &other) {
            return *this;
        } else {
            delete[] data;
            data = nullptr;
            len = other.len;
            capacity = other.capacity;
            data = new T[capacity];
            for (unsigned long long i = 0; i < len; ++i) {
                data[i] = other.data[i];
            }
            return *this;
        }
    }

    template<typename T>
    MyVector<T> &MyVector<T>::operator=(const T *other) {
        unsigned long long other_len = sizeof(other) / sizeof(other[0]);
        if (data != nullptr) {
            len = other_len;
            capacity = other_len + 5;
            delete[] data;
            data = nullptr;
            data = new T[capacity];
            for (unsigned long long i = 0; i < other_len; ++i) {
                data[i] = other[i];
            }
        }
    }

    template<typename T>
    MyVector<T> MyVector<T>::operator+(const MyVector<T> &other) //加法
    {
        if (typeid(T) != typeid(other.data[0])) {
            throw "type error";
        } else {
            MyVector<T> result;
            result.len = this->len + other.len;
            result.capacity = this->capacity + other.capacity;
            result.data = new T[result.capacity];
            unsigned long long i = 0;
            for (i = 0; i < this->len; i++) {
                result.data[i] = this->data[i];
            }
            for (i = 0; i < other.len; i++) {
                result.data[this->len + i] = other.data[0];
            }
            return result;
        }
    }

    template<typename T>
    MyVector<T> MyVector<T>::operator+=(const MyVector<T> &other) {
        // 确保当前对象有足够的容量来容纳另一个对象的元素
        if (typeid(T) == typeid(other.data[0])) {
            if (len + other.len > capacity) {
                // 如果容量不够，扩展容量
                reserve(len + other.len + 5);
            }

            // 复制另一个对象的元素到当前对象的末尾
            for (unsigned long long i = 0; i < other.len; ++i) {
                data[len + i] = other.data[i];
            }
            // 更新当前对象的长度
            len += other.len;
            return *this;
        } else {
            throw "type error";
        }
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
    T &MyVector<T>::operator[](unsigned long long index) {
        return data[index];  //直接返回引用，不做异常处理
    }

    template<typename T>
    std::istream &operator>>(std::istream &in, MyVector<T> &v) {
        for (unsigned long long i = 0; i < v.size();) {
            in >> v[i++];
        }
        return in;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &out, MyVector<T> &v) //输出
    {
        for (unsigned long long i = 0; i < v.size();) {
            out << v[i++] << " ";
        }
        out << '\n';
        return out;
    }
}
#endif //OOPCES_VECTOR_MYVECTOR_H