#pragma once
#include "..\pch.h"
#include "Sales_data.h"
// 前置声明，在将模板的一个特定实例声明为友元时要用到
template <typename T> class Pal;

class C // C是一个普通的非模板类
{
    friend class Pal<C>; // 用类C实例化的Pal是C的一个友元。
    // 类模板Pal2的所有实例都是C的友元；这种情况无须前置声明。
    template <typename T> friend class Pal2;
};

template <typename T>
class C2 // C2 本身是一个类模板。
{
    // C2的每个实例将相同实例化的Pal声明为友元。
    friend class Pal<T>; // Pal的模板声明必须在作用域之内。
    // 类模板Pal2的所有实例都是C2的每个实例的友元，不需要前置声明。
    template <typename X> friend class Pal2;
    // Pal3是一个非模板类，它是C2所有实例的友元。
    friend class Pal3; //不需要Pal3的前置声明。
};

template <typename Type> 
class Bar
{
    friend Type; // 将访问权限授予用来实例化Bar的类型
    //...
};

template <typename T> 
class Foo
{
public:
    Foo() { }
    Foo(int b) { ctr = ctr + b; }
    static std::size_t count() { return ctr; }
    //其他接口成员

private:
    static std::size_t ctr;
    //其他实现成员
};

template <typename T>
size_t Foo<T>::ctr = 0; // 定义并初始化ctr

// 一个普通的类，用于测试static数据成员
class Foo1
{
public:
    Foo1(int b) { ctr1 = ctr1 + b; }
    static std::size_t count() { return ctr1; }
    //其他接口成员

private:
    // static std::size_t ctr1;
    static int ctr1;
    //其他实现成员
};

//size_t Foo1::ctr1 = 1;
int Foo1::ctr1 = 1;

//template <typename Foo>
//Foo calc(const Foo& a, const Foo& b)
//{
//    Foo tmp = a; // tmp的类型与参数和返回类型一样
//    //..
//    return tmp; //返回类型和参数类型一样
//};

typedef double A;
template <typename A, typename B> 
void f(A a, B b)
{
    A tmp = a; // tmp的类型为模板参数A的类型，而非double 
    //double B;  // 错误：重声明模板参数B
};

//// 错误：非法重用模板参数名V 
//template<typename V, typename V> 
//class oiu;//...

// 声明但不定义compare和Blob
template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;

// 3个calc都指向相同的函数模板
template <typename T> T calc(const T&, const T&); // 声明
template <typename U> U calc(const U&, const U&); // 声明
//模板的定义
template <typename Type>
Type calc(const Type& a, const Type& b) { /* ... */ }

// 实例化 static 成员 Foo<string>::ctr 和 Foo<string>::count
// Foo<std::string> fs;
// 下面三个对象共享相同的Foo<int>::ctr 和 Foo<int>:：count 成员
// Foo<int> fi, fi2, fi3;

template <typename T>
typename T::value_type top(const T& c)
{
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
};


// compare有一个默认模板实参less<T>和一个默认函数实参F()
template<typename T, typename F = std::less<T>>
int compare(const T& vl, const T& v2, F f = F())
{
    if (f(vl, v2)) return -1;
    if (f(v2, vl)) return 1;
    return 0;
}