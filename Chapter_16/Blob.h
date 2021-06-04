// #include "Version_test.h"

#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>

//#define INITIALIZER_LIST
#ifdef INITIALIZER_LIST
#include <initializer_list>
#endif

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

#ifdef Section16_1_1_ON
namespace Section_16_1_1
{
    // 如果两个值相等，返回0,如果v1小返回T,如果v2小返回1
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
    };

#ifndef USE_LESS
    template<typename T>
    int compare(const T& v1, const T& v2)
    {
        if (v1 < v2) return -1;
        if (v2 < v1) return 1;
        return 0;
    };
    // 与类型无关的代码中的函数模板冲突，因此使用了宏 USE_LESS 来控制是否使用。
#endif


    int compare(const int& v1, const int& v2)
    {
        if (v1 < v2) return -1;
        if (v2 < v1) return 1;
        return 0;
    }

// 模板类型参数
    // 正确：返回类型和参数类型相同
    template <typename T>
    T foo(T* p)
    {
        T tmp = *p; // tmp的类型将是指针p指向的类型
        //...
        return tmp;
    }

    ////错误：U之前必须加上class或typename
    //template<typename T, U >
    //T calc(const T&, const U&);

    //正确：在模板参数列表中，typename和class没有什么不同
    template <typename T, class U>T calc(const T&, const U&);

// 非类型模板参数
    template<unsigned N, unsigned M>
    int compare(const char(&p1)[N], const char(&p2)[M])
    {
        return strcmp(p1, p2);
    }

// inline和constexpr的函数模板
    //正确：inline说明符跟在模板参数列表之后
    template <typename T>
    inline T min(const T&, const T&);

    ////错误：inline说明符的位置不正确
    //inline template <typename T>
    //    T min(const T&, const T&);


// 与类型无关的代码
#ifdef USE_LESS
    // 即使用于指针也正确的compare版本；参见14.8.2节
    template <typename T>
    int compare(const T& v1, const T& v2)
    {
        if (std::less<T>() (v1, v2)) return -1;
        if (std::less<T>() (v2, v1)) return 1;
        return 0;
    }
    // 这种代码与最前面的函数模板冲突了。
    // 虽然定义部分不同，但是这不足以让编译器能区分这是两个模板。
#endif


}
#endif

#ifdef Section16_1_2_ON
namespace Section_16_1_2
{
#include <initializer_list>

#pragma region 
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
        size_type size() const
        {
            return data->size();
        }
        bool empty() const
        {
            return data->empty();
        }
        // 添加和删除元素
        void push_back(const T& t)
        {
            data->push_back(t);
        }
        // 移动版本，参见13.6.3节(第484页)
        void push_back(T&& t)
        {
            data->push_back(std::move(t));
        }
        void pop_back();
        // 元素访问
        T& back();
        T& operator [] (size_type i); // 在 14.5 节(第 501 页)中定义 
    private:
        std::shared_ptr<std::vector<T>> data;
        // 若data [i]无效，则抛出msg
        void check(size_type i, const std::string& msg) const;
    };

#pragma region

    template <typename T>
    void Section_16_1_2::Blob<T>::pop_back()
    {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }

    template <typename T>
    T& Section_16_1_2::Blob<T>::operator[](size_type i)
    {
        // 如果i太大，check会抛出异常，阻止访问一个不存在的元素
        check(i, "subscript out of range");
        return (*data)[i];
    }

    template <typename T>
    T& Section_16_1_2::Blob<T>::back()
    {
        check(0, "back on empty Blob");
        return data->back();
    }

    template <typename T>
    void Section_16_1_2::Blob<T>::check(size_type i, const std::string& msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }

    template <typename T>
    Section_16_1_2::Blob<T>::Blob(std::initializer_list<T> il)
        : data(std::make_shared<std::vector<T>>(il))
    {

    }

    template <typename T>
    Section_16_1_2::Blob<T>::Blob()
        : data(std::make_shared<std::vector<T>>())
    {

    }
#pragma endregion Blob类模板的定义
#pragma endregion Blob类模板

#pragma region 
#if 0
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
#endif

}
#pragma endregion 编译器为Blob<int>实例化的代码

#endif

#ifdef Section16_1_3_ON
namespace Section_16_1_3
{


}
#endif

#ifdef Section16_1_4_ON
namespace Section_16_1_4
{


}
#endif

//
//// forward declarations needed for friend declarations in Blob
//template <typename> class BlobPtr;
//template <typename> class Blob; // needed for parameters in operator==
//template <typename T>
//bool operator==(const Blob<T>&, const Blob<T>&);
//
//template <typename T> class Blob {
//    // each instantiation of Blob grants access to the version of
//    // BlobPtr and the equality operator instantiated with the same type
//    // 每个Blob实例,将访问权限授予,用相同类型实例化的BlobPtr和相等运算符. 
//    friend class BlobPtr<T>;
//    friend bool operator==<T>
//        (const Blob<T>&, const Blob<T>&);
//public:
//    typedef T value_type;
//    typedef typename std::vector<T>::size_type size_type;
//
//    // constructors
//    Blob();
//#ifdef INITIALIZER_LIST  
//    Blob(std::initializer_list<T> il);
//    // if no initializer_list support use the iterator constructor
//#endif
//    template <typename It> Blob(It b, It e);
//    Blob(T*, std::size_t);
//
//    // return BlobPtr to the first and one past the last elements
//    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
//    BlobPtr<T> end()
//    {
//        auto ret = BlobPtr<T>(*this, data->size());
//        return ret;
//    }
//
//    // number of elements in the Blob
//    size_type size() const { return data->size(); }
//    bool empty() const { return data->empty(); }
//
//    // add and remove elements
//    void push_back(const T& t) { data->push_back(t); }
//    void push_back(T&& t) { data->push_back(std::move(t)); }
//    void pop_back();
//
//    // element access
//    T& front();
//    T& back();
//    T& at(size_type);
//    const T& back() const;
//    const T& front() const;
//    const T& at(size_type) const;
//    T& operator[](size_type i);
//    const T& operator[](size_type i) const;
//
//    void swap(Blob& b) { data.swap(b.data); }
//private:
//    std::shared_ptr<std::vector<T>> data;
//
//    // throws msg if data[i] isn't valid
//    void check(size_type i, const std::string& msg) const;
//};
//
//// constructors
//template <typename T>
//Blob<T>::Blob(T* p, std::size_t n) :
//    data(std::make_shared<std::vector<T>>(p, p + n)) { }
//
//template <typename T>
//Blob<T>::Blob() :
//    data(std::make_shared<std::vector<T>>()) { }
//
//template <typename T>     // type parameter for the class
//template <typename It>    // type parameter for the constructor
//Blob<T>::Blob(It b, It e) :
//    data(std::make_shared<std::vector<T>>(b, e)) { }
//
//#ifdef INITIALIZER_LIST
//template <typename T>
//Blob<T>::Blob(std::initializer_list<T> il) :
//    data(std::make_shared<std::vector<T>>(il)) { }
//#endif
//
//// check member
//template <typename T>
//void Blob<T>::check(size_type i, const std::string& msg) const
//{
//    if (i >= data->size())
//        throw std::out_of_range(msg);
//}
//
//// element access members
//template <typename T>
//T& Blob<T>::front()
//{
//    // if the vector is empty, check will throw
//    check(0, "front on empty Blob");
//    return data->front();
//}
//
//template <typename T>
//T& Blob<T>::back()
//{
//    check(0, "back on empty Blob");
//    return data->back();
//}
//
//template <typename T> void Blob<T>::pop_back()
//{
//    check(0, "pop_back on empty Blob");
//    data->pop_back();
//}
//
//template <typename T>
//const T& Blob<T>::front() const
//{
//    check(0, "front on empty Blob");
//    return data->front();
//}
//
//template <typename T>
//const T& Blob<T>::back() const
//{
//    check(0, "back on empty Blob");
//    return data->back();
//}
//
//template <typename T>
//T& Blob<T>::at(size_type i)
//{
//    // if i is too big, check will throw, preventing access to a nonexistent element
//    check(i, "subscript out of range");
//    return (*data)[i];  // (*data) is the vector to which this object points
//}
//
//template <typename T>
//const T&
//Blob<T>::at(size_type i) const
//{
//    check(i, "subscript out of range");
//    return (*data)[i];
//}
//
//template <typename T>
//T& Blob<T>::operator[](size_type i)
//{
//    // if i is too big, check will throw, preventing access to a nonexistent element
//    check(i, "subscript out of range");
//    return (*data)[i];
//}
//
//template <typename T>
//const T&
//Blob<T>::operator[](size_type i) const
//{
//    check(i, "subscript out of range");
//    return (*data)[i];
//}
//
//// operators
//template <typename T>
//std::ostream&
//operator<<(std::ostream& os, const Blob<T> a)
//{
//    os << "< ";
//    for (size_t i = 0; i < a.size(); ++i)
//        os << a[i] << " ";
//    os << " >";
//    return os;
//}
//
//template <typename T>
//bool
//operator==(const Blob<T> lhs, const Blob<T> rhs)
//{
//    if (rhs.size() != lhs.size())
//        return false;
//    for (size_t i = 0; i < lhs.size(); ++i) {
//        if (lhs[i] != rhs[i])
//            return false;
//    }
//    return true;
//}
////
////// BlobPtr 会在尝试访问不存在的元素时候，抛出一个异常。
////template <typename T>
////class BlobPtr
////{
////public:
////    BlobPtr() : curr(0) {}
////    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
////    T& operator*() const
////    {
////        auto p = check(curr, "dereference past end");
////        return (*p)[curr]; // (*p)为本对象指向的 vector
////    };
////
////    // 递增和递减
////    BlobPtr& operator++ (); // 前置运算符
////    BlobPtr& operator-- ();
////    BlobPtr<T>& operator++();
////    BlobPtr<T>& operator--();
////private:
////    // 若检查成功，check返回一个指向vector的shared_ptr
////    std::shared_ptr<std::vector<T>> check(std::size_t, const std::strings) const;
////    // 保存一个weak_ptr,表示底层vector可能被销毁
////    std::weak_ptr<std::vector<T>> wptr;
////    std::size_t curr; // 数组中的当前位置
////};
//
//
//// BlobPtr throws an exception on attempts to access a nonexistent element 
//template <typename T>
//bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
//
//template <typename T> 
//class BlobPtr : public std::iterator<std::bidirectional_iterator_tag, T> 
//{
//    friend bool
//        operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
//public:
//    BlobPtr() : curr(0) { }
//    BlobPtr(Blob<T>& a, size_t sz = 0) :
//        wptr(a.data), curr(sz) { }
//
//    T& operator[](std::size_t i)
//    {
//        auto p = check(i, "subscript out of range");
//        return (*p)[i];  // (*p) is the vector to which this object points
//    }
//
//    const T& operator[](std::size_t i) const
//    {
//        auto p = check(i, "subscript out of range");
//        return (*p)[i];  // (*p) is the vector to which this object points
//    }
//
//    T& operator*() const
//    {
//        auto p = check(curr, "dereference past end");
//        return (*p)[curr];  // (*p) is the vector to which this object points
//    }
//    T* operator->() const
//    { // delegate the real work to the dereference operator
//        return &this->operator*();
//    }
//
//    // increment and decrement
//    BlobPtr& operator++();       // prefix operators
//    BlobPtr& operator--();
//
//    BlobPtr operator++(int);     // postfix operators
//    BlobPtr operator--(int);
//
//private:
//    // check returns a shared_ptr to the vector if the check succeeds
//    std::shared_ptr<std::vector<T>>
//        check(std::size_t, const std::string&) const;
//
//    // store a weak_ptr, which means the underlying vector might be destroyed
//    std::weak_ptr<std::vector<T>> wptr;
//    std::size_t curr;      // current position within the array
//};
//
//// equality operators
//template <typename T>
//bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
//{
//    return lhs.wptr.lock().get() == rhs.wptr.lock().get() &&
//        lhs.curr == rhs.curr;
//}
//
//template <typename T>
//bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
//{
//    return !(lhs == rhs);
//}
//
//// check member
//template <typename T>
//std::shared_ptr<std::vector<T>>
//BlobPtr<T>::check(std::size_t i, const std::string& msg) const
//{
//    auto ret = wptr.lock();   // is the vector still around?
//    if (!ret)
//        throw std::runtime_error("unbound BlobPtr");
//    if (i >= ret->size())
//        throw std::out_of_range(msg);
//    return ret; // otherwise, return a shared_ptr to the vector
//}
//
//// member operators
//// postfix: increment/decrement the object but return the unchanged value
//// 后置：递增/递减对象但返回原值
//template <typename T>
//BlobPtr<T> BlobPtr<T>::operator++(int)
//{
//    // no check needed here; the call to prefix increment will do the check
//    // 此处无须检查；调用前置递增时会进行检查
//    BlobPtr ret = *this;   // save the current value
//    ++ *this;     // advance one element; prefix ++ checks the increment
//    return ret;  // return the saved state
//}
//
//template <typename T>
//BlobPtr<T> BlobPtr<T>::operator--(int)
//{
//    // no check needed here; the call to prefix decrement will do the check
//    BlobPtr ret = *this;  // save the current value
//    --* this;     // move backward one element; prefix -- checks the decrement
//    return ret;  // return the saved state
//}
//
//// prefix: return a reference to the incremented/decremented object
//template <typename T>
//BlobPtr<T>& BlobPtr<T>::operator++()
//{
//    // if curr already points past the end of the container, can't increment it
//    check(curr, "increment past end of BlobPtr");
//    ++curr;       // advance the current state
//    return *this;
//}
//
//template <typename T>
//BlobPtr<T>& BlobPtr<T>::operator--()
//{
//    // if curr is zero, decrementing it will yield an invalid subscript
//    --curr;       // move the current state back one element
//    check(-1, "decrement past begin of BlobPtr");
//    return *this;
//}
//

//class Vehicle;
//class Student;
//
//typedef Blob<std::string> StrBlob;
//
//template<typename T> using twin = std::pair<T, T>;
//twin<std::string> authors; // authors是一个pair<string, string>
//
//twin<int> win_loss; // win_loss是一个pair<int, int>
//twin<double> area; // area 是一个 pair<double, double>
//
//template <typename T> using partNo = std::pair<T, unsigned >;
//partNo<std::string> books; // books 是一个 pair<string, unsigned>
//partNo<Vehicle> cars; // cars是一pair<Vehicle, unsigned>
//partNo<Student> kids; // kids是一个pair<Student, unsigned> 

#ifdef Section16_1_5_ON
namespace Section_16_1_5
{
    template<typename T, typename F = std::less<T>>
    int compare(const T& vl, const T& v2, F f = F())
    {
        if (f(vl, v2)) return -1;
        if (f(v2, vl)) return 1;
        return 0;
    }

    //
//    template <typename T> class Blob
//    {
//        // each instantiation of Blob grants access to the version of
//        // BlobPtr and the equality operator instantiated with the same type
//        // 每个Blob实例,将访问权限授予,用相同类型实例化的BlobPtr和相等运算符. 
//        friend class BlobPtr<T>;
//        friend bool operator==<T>
//            (const Blob<T>&, const Blob<T>&);
//    public:
//        typedef T value_type;
//        typedef typename std::vector<T>::size_type size_type;
//
//        // constructors
//        Blob();
//#ifdef INITIALIZER_LIST  
//        Blob(std::initializer_list<T> il);
//        // if no initializer_list support use the iterator constructor
//#endif
//        template <typename It> Blob(It b, It e);
//        Blob(T*, std::size_t);
//
//        // return BlobPtr to the first and one past the last elements
//        BlobPtr<T> begin()
//        {
//            return BlobPtr<T>(*this);
//        }
//        BlobPtr<T> end()
//        {
//            auto ret = BlobPtr<T>(*this, data->size());
//            return ret;
//        }
//
//        // number of elements in the Blob
//        size_type size() const
//        {
//            return data->size();
//        }
//        bool empty() const
//        {
//            return data->empty();
//        }
//
//        // add and remove elements
//        void push_back(const T& t)
//        {
//            data->push_back(t);
//        }
//        void push_back(T&& t)
//        {
//            data->push_back(std::move(t));
//        }
//        void pop_back();
//
//        // element access
//        T& front();
//        T& back();
//        T& at(size_type);
//        const T& back() const;
//        const T& front() const;
//        const T& at(size_type) const;
//        T& operator[](size_type i);
//        const T& operator[](size_type i) const;
//
//        void swap(Blob& b)
//        {
//            data.swap(b.data);
//        }
//    private:
//        std::shared_ptr<std::vector<T>> data;
//
//        // throws msg if data[i] isn't valid
//        void check(size_type i, const std::string& msg) const;
//    };
};
#endif


#endif
