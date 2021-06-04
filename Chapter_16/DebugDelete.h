/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <cstddef>
#include <iostream>
#include <string>

// function-object class that calls delete on a given pointer
// 函数对象类，对给定指针执行delete
namespace Section_16_1_4
{
    class DebugDelete
    {
    public:
        DebugDelete(const std::string& s = "unique_ptr",
                    std::ostream& strm = std::cerr) : os(strm), type(s)
        {}
        // as with any function template, the type of T is deduced by the compiler
        // 与任何函数模板相同，T的类型由编译器推断
        template <typename T> void operator()(T* p) const
        {
            os << "deleting " << type << std::endl; delete p;
        }
    private:
        std::ostream& os;  // where to print debugging info
        std::string type;  // what type of smart pointer we're deleting
    };

    // DebugDelete的成员模板实例化样例
    template <>
    void DebugDelete::operator() (int* p) const
    {
        delete p;
    };

    template <>
    void DebugDelete::operator() (std::string* p) const
    {
        delete p;
    };


    //template <typename T> class Blob
    //{
    //    template <typename It> Blob(It b, It e);
    //    //...
    //};

    //// 类外定义，类的成员模板函数
    //template <typename T> // 类的类型参数
    //template <typename It> // 构造函数的类型参数
    //Blob<T>::Blob(It b, It e) :
    //    data(std::make_shared<std::vector<T>>(b, e))
    //{};

}

#endif
