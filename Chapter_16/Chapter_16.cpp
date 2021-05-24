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

class Sales_data {};

template <typename T> 
class Blob
{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // 构造函数
    Blob();
    Blob(std::initializer_list<T> il);
    // Blob中的元素数目
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); ) }
    // 添加和删除元素
    void push_back(const T& t) (data->push_back(t);
    // 移动版本，参见13.6.3节(第484页)
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();
    // 元素访问
    T& back();
    T& operator [] (size_type i); // 在 14.5 节(第 501 页)中定义 
private:
    std::shared_ptr<std::vector<T>> data;
    // 若data [i]无效，则抛出msg
    void check(size_type i, const std::string& msg) const;
};

template <>
class Blob<int> 
{
public:
    typedef typename std::vector<int>::size_type size_type;
    Blob();
    Blob(std::initializer_list<int> il);
    //...
    int& operator[](size_type i);
private:
    std::shared_ptr<std::vector<int>> data;
    void check(size_type i, const std::string& msg) const;
};

int main()
{

    Blob<int> ia; // 空Blob<int>
    Blob<int> ia2 = { 0, 1, 2, 3, 4 }; // 有5个元素的Blob<int>

    // 下面的定义实例化出两个不同的Blob类型
    Blob<std::string> names; // 保存 string 的 Blob
    Blob<double> prices; // 不同的元素类型

    Sales_data data1, data2;
    std::cout << compare(data1, data2) << std::endl; // 错误：Sales_data 未定义 <

    const char* p1 = "aweee";
    const char* p2 = "abeee";

    std::string s1 = "abeee";
    std::string s2 = "aweee";
    int r2 = compare2(s1,s2);
    int r = compare2(p1,p2);


    std::cout << compare(1, 0) << std::endl; // T 为 int

    // 实例化出 int compare(const int&, const int&)
    std::cout << compare(1, 0) << std::endl; // T = int

    // 实例化出 int compare (const vector<int>&, const vector<int>&)
    std::vector<int> vecl{ 1, 2, 3 }, vec2{ 4, 5, 6 };
    std::cout << compare(vecl, vec2) << std::endl; // T = vector<int>

    compare("hi", "mom");


    return 0;
}
