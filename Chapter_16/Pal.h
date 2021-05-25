#pragma once
#include "..\pch.h"
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
    static std::size_t count() { return ctr; }
    //其他接口成员

private:
    static std::size_t ctr;
    //其他实现成员
};