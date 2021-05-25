// Chapter_16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\pch.h"

//如果两个值相等，返回0,如果v1小返回T,如果v2小返回1 
int compare(const std::string& v1, const std::string& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
};

int compare(const double& v1, const double& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int compare(const int& v1, const int& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template<typename T>
int compare(const T& v1, const T& v2)
{
    ////期望的比较操作
    //if (v1 < v2) return -1;
    //if (v1 > v2) return 1;
    //return 0;

    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
};

//// 正确：返回类型和参数类型相同
//template <typename T>
//T foo(T* p)
//{
//    T tmp = *p; // tmp的类型将是指针p指向的类型
//    //...
//    return tmp;
//}
//
//////错误：U之前必须加上class或typename
////template<typename T, U >
////T calc(const T&, const U&);
//
////正确：在模板参数列表中，typename和class没有什么不同
//template <typename T, class U>
//T calc(const T&, const U&);
//
//template<unsigned N, unsigned M>
//int compare(const char(&p1)[N], const char(&p2)[M])
//{
//    return strcmp(p1, p2);
//}
//int compare(const char(&pl)[3], const char(&p2)[4]);
//
//
////正确：inline说明符跟在模板参数列表之后
//template <typename T> 
//inline T min(const T&, const T&);
//////错误：inline说明符的位置不正确
////inline template <typename T> 
////T min(const T&, const T&);


    // 即使用于指针也正确的compare版本；参见14.8.2节(第510页)
    template <typename T>
    int compare2(const T& v1, const T& v2)
    {
        if (std::less<T>() (v1, v2)) return -1;
        if (std::less<T>() (v2, v1)) return 1;
        return 0;
    }

#include "Pal.h"
#include "Blob.h"
#include "Sales_data.h"

int main()
{

    //Blob<int> ia; // 空Blob<int>
    //Blob<int> ia2 = { 0, 1, 2, 3, 4 }; // 有5个元素的Blob<int>

    //// 下面的定义实例化出两个不同的Blob类型
    //Blob<std::string> names; // 保存 string 的 Blob
    //Blob<double> prices; // 不同的元素类型

    //Sales_data data1, data2;
    //std::cout << compare(data1, data2) << std::endl; // 错误：Sales_data 未定义 <

    //const char* p1 = "aweee";
    //const char* p2 = "abeee";

    //std::string s1 = "abeee";
    //std::string s2 = "aweee";
    //int r2 = compare2(s1,s2);
    //int r = compare2(p1,p2);


    //std::cout << compare(1, 0) << std::endl; // T 为 int

    //// 实例化出 int compare(const int&, const int&)
    //std::cout << compare(1, 0) << std::endl; // T = int

    //// 实例化出 int compare (const vector<int>&, const vector<int>&)
    //std::vector<int> vecl{ 1, 2, 3 }, vec2{ 4, 5, 6 };
    //std::cout << compare(vecl, vec2) << std::endl; // T = vector<int>

    //// 实例化Blob<int>和接受initializer_list<int>的构造函数 
    //Blob<int> squares = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //// 实例化 Blob<int>::size() const 
    //for (size_t i = 0; i != squares.size(); ++i)
    //    squares[i] = i * i; // 实例化 Blob<int>::operator[] (size_t)

    //compare("hi", "mom");

    // Foo<std::string> fs;
    // 下面三个对象共享相同的Foo<int>::ctr 和 Foo<int>: count 成员
    Foo<char> f1(1);
    Foo<char> f2(2);
    Foo<char> f3(3);

    auto o1 = f1.count();
    auto o2 = f2.count();
    auto o3 = f3.count();

    Foo1 f11(1);
    Foo1 f21(2);
    Foo1 f31(3);

    auto o11 = f11.count();
    auto o21 = f21.count();
    auto o31 = f31.count();

    Foo<std::string> fs(1);
    auto o32 = fs.count();


    //Foo<int> fi; // 实例化 Foo<int>类和 static 数据成员 ctr
    //auto ct = Foo<int>::count(); // 实例化 Foo<int>::count
    //ct = fi.count(); // 使用 Foo<int>::count
    //ct = Foo::count(); //错误：使用哪个模板实例的count?

    bool i = compare(0, 42); // 使用 less; i 为-1
    // 结果依赖于item1和item2中的isbn
    Sales_data item1(...), item2(...);
    bool j = compare(item1, item2, compareIsbn);

    return 0;
}
