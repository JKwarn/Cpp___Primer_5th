#pragma once
#include "..\pch.h"
#include "Sales_data.h"
// ǰ���������ڽ�ģ���һ���ض�ʵ������Ϊ��ԪʱҪ�õ�
template <typename T> class Pal;

class C // C��һ����ͨ�ķ�ģ����
{
    friend class Pal<C>; // ����Cʵ������Pal��C��һ����Ԫ��
    // ��ģ��Pal2������ʵ������C����Ԫ�������������ǰ��������
    template <typename T> friend class Pal2;
};

template <typename T>
class C2 // C2 ������һ����ģ�塣
{
    // C2��ÿ��ʵ������ͬʵ������Pal����Ϊ��Ԫ��
    friend class Pal<T>; // Pal��ģ������������������֮�ڡ�
    // ��ģ��Pal2������ʵ������C2��ÿ��ʵ������Ԫ������Ҫǰ��������
    template <typename X> friend class Pal2;
    // Pal3��һ����ģ���࣬����C2����ʵ������Ԫ��
    friend class Pal3; //����ҪPal3��ǰ��������
};

template <typename Type> 
class Bar
{
    friend Type; // ������Ȩ����������ʵ����Bar������
    //...
};

template <typename T> 
class Foo
{
public:
    Foo() { }
    Foo(int b) { ctr = ctr + b; }
    static std::size_t count() { return ctr; }
    //�����ӿڳ�Ա

private:
    static std::size_t ctr;
    //����ʵ�ֳ�Ա
};

template <typename T>
size_t Foo<T>::ctr = 0; // ���岢��ʼ��ctr

// һ����ͨ���࣬���ڲ���static���ݳ�Ա
class Foo1
{
public:
    Foo1(int b) { ctr1 = ctr1 + b; }
    static std::size_t count() { return ctr1; }
    //�����ӿڳ�Ա

private:
    // static std::size_t ctr1;
    static int ctr1;
    //����ʵ�ֳ�Ա
};

//size_t Foo1::ctr1 = 1;
int Foo1::ctr1 = 1;

//template <typename Foo>
//Foo calc(const Foo& a, const Foo& b)
//{
//    Foo tmp = a; // tmp������������ͷ�������һ��
//    //..
//    return tmp; //�������ͺͲ�������һ��
//};

typedef double A;
template <typename A, typename B> 
void f(A a, B b)
{
    A tmp = a; // tmp������Ϊģ�����A�����ͣ�����double 
    //double B;  // ����������ģ�����B
};

//// ���󣺷Ƿ�����ģ�������V 
//template<typename V, typename V> 
//class oiu;//...

// ������������compare��Blob
template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;

// 3��calc��ָ����ͬ�ĺ���ģ��
template <typename T> T calc(const T&, const T&); // ����
template <typename U> U calc(const U&, const U&); // ����
//ģ��Ķ���
template <typename Type>
Type calc(const Type& a, const Type& b) { /* ... */ }

// ʵ���� static ��Ա Foo<string>::ctr �� Foo<string>::count
// Foo<std::string> fs;
// ����������������ͬ��Foo<int>::ctr �� Foo<int>:��count ��Ա
// Foo<int> fi, fi2, fi3;

template <typename T>
typename T::value_type top(const T& c)
{
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
};


// compare��һ��Ĭ��ģ��ʵ��less<T>��һ��Ĭ�Ϻ���ʵ��F()
template<typename T, typename F = std::less<T>>
int compare(const T& vl, const T& v2, F f = F())
{
    if (f(vl, v2)) return -1;
    if (f(v2, vl)) return 1;
    return 0;
}