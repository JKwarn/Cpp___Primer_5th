#pragma once
#include "..\pch.h"
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
    static std::size_t count() { return ctr; }
    //�����ӿڳ�Ա

private:
    static std::size_t ctr;
    //����ʵ�ֳ�Ա
};