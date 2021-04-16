// Chapter_19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Chapter_19.h"

class BBC
{
public:
    void 胡说八道()
    {
        std::cout << "BBC 又胡说八道了\n";
    }
};

class twitter
{
    void 颠倒是非()
    {
        std::cout << "twitter 又颠倒是非了\n";
    }
};


using namespace Section19_4;


int main()
{
    //auto pdata = &Section19_4::Screen::contents;
    //Section19_4::Screen myScreen;
    //Section19_4::Screen* pScreen = &myScreen;
    //// . *解引用pdata以获得myScreen对象的contents成员
    //auto s = myScreen.*pdata;
    //// ->*解引用pdata以获得pScreen所指对象的contents成员
    //s = pScreen->*pdata;

    //// data ()返回一个指向Screen类的contents成员的指针
    //const std::string Section19_4::Screen::* pdata = Section19_4::Screen::data();

    ////获得myScreen对象的contents成员
    //auto s = myScreen.*pdata;

    // pmf是一个指针，它可以指向Screen的某个常量成员函数
    // 前提是该函数不接受任何实参，并且返回一个char
    auto pmf = &Screen::get_cursor;

    char (Screen::* pmf2)(Screen::pos, Screen::pos) const;
    pmf2 = &Screen::get;


    ////错误：非成员函数p不能使用const限定符
    //char Screen::* p(Screen::pos, Screen::pos) const;

    //// pmf指向一个Screen成员，该成员不接受任何实参且返回类型是char
    //pmf = &Screen::get; // 必须显式地使用取地址运算符
    //pmf = Screen::get; // 错误：在成员函数和指针之间不存在自动转换规则


    //Screen myScreen;
    //Screen* pScreen = &myScreen;
    //// 通过pScreen所指的对象调用pmf所指的函数 
    //char cl = (pScreen->*pmf)();
    //// 通过myScreen时象将实参0, 0传给含有两个形参的get函数
    //char c2 = (myScreen.*pmf2)(0, 0);
    ////myScreen.*pmf();
    ////myScreen.*(pmf());

    //// Action是一种可以指向Screen成员函数的指针，它接受两个pos实参，返回一个char
    //using Action = char(Screen::*)(Screen::pos, Screen::pos) const;
    //Action get = &Screen::get; // get 指向 Screen 的 get 成员

    //// Action接受一个Screen的引用，和一个指向Screen成员函数的指针 
    //Screen& action(Screen&, Action = &Screen::get);

    //Screen myScreen;
    ////等价的调用：
    //action(myScreen); // 使用默认实参
    //action(myScreen, get); // 使用我们之前定义的变量get
    //action(myScreen, &Screen::get); // 显式地传入地址

    Screen myScreen;
    myScreen.move(Screen::HOME); // 调用 myScreen.home
    myScreen.move(Screen::DOWN); // 调用 myScreen.down

    auto fp = &std::string::empty;    // fp 指向 string 的 empty 函数
    //find_if(svec.begin(), svec.end(), fp);    // 错误，必须使用.*或->*调用成员指针

    //// 检查对当前元素的断言是否为真
    //if (fp(*it));    // 错误：要想通过成员指针调用函数，必须使用->*运算符

    //std::function<bool(const std::string&)> fcn = &std::string::empty;
    //find_if(svec.begin(), svec.end(), fcn);

    //// 假设it是find_if内部的迭代器，则*it是给定范围内的一个对象
    //if (fcn(*it))    // 假设fcn是find_if内部的一个可调用对象的名字

    // 假设it是find_if内部的迭代器，则*it是给定范围内的一个对象
    if (fcn(*it).*p())    // 假设p是fcn内部的一个指向成员函数的指针

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
