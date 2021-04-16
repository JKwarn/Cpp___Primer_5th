#pragma once
//class Chapter_19
//{
//};
//
#include "..\pch.h"

#ifdef Section19_1_ON

namespace Section19_1
{
    //void* operator new(size_t size)
    //{
    //    if (void* mem = malloc(size))
    //        return mem;
    //    else
    //        throw std::bad_alloc::bad_alloc();
    //}

    //void operator delete(void* mem) noexcept
    //{
    //    free(mem);
    //}
}

#endif // DEBUG

#ifdef Section19_2_ON
namespace Section19_2
{

    namespace Section19_2_2
    {
        // 19.2.3 使用RTTI
        class Base
        {
        public:
            friend bool operator==(const Base&, const Base&);

            // 使用 dynamic_cast，则至少需要一个虚函数，
            // 否则报2个错。
            // 1. 运行时 dynamic_cast 的操作数必须包含多态类类型 
            // 2. “dynamic_cast” : “Base”不是多态类型	测试用例 
        protected:
            virtual bool equal(const Base&) const;

        private:

        };

        class Derived :public Base
        {
        public:

        protected:
            bool equal(const Base&) const;

        private:

        };
    }


    namespace Section19_2_3
    {
        // 19.2.3 使用RTTI
        class Base
        {
        public:
            friend bool operator==(const Base&, const Base&);

        protected:
            virtual bool equal(const Base&) const;

        private:

        };

        class Derived :public Base
        {
        public:

        protected:
            bool equal(const Base&) const;

        private:

        };
    }
}
#endif

#ifdef Section19_3_ON
namespace Section19_3
{
    enum class open_modes
    {
        input,
        output,
        append
    };
    /************************************************************************/
    // 不限定作用域的枚举类型
    enum color
    {
        red,
        yellow,
        green
    };

    // 未命名、不限定作用域的枚举类型
    enum
    {
        floatPrec = 6,
        doublePrec = 10,
        double_doubleprec = 10
    };
    /************************************************************************/

    // 不限定作用域的枚举类型
    enum color
    {
        red,
        yellow,
        green
    };

    // 错误，重复定义了枚举成员。color与stoplight冲突，因为不限定作用域的枚举共享变量名。
    enum stoplight
    {
        red,
        yellow,
        green
    };

    enum class peppers
    {
        red,
        yellow,
        green
    }; // 正确： 枚举成员被隐藏了


    color eyes = green; // 正确：不限定作用域的枚举类型的枚举成员位于有效的作用域中
    peppers p = green;  // 错误：peppers的枚举成员不在有效的作用域
                        // color::green在有效的作用域中，但是类型错误
    color hair = color::red; // 正确：允许显式地访问枚举成员
    peppers p2 = peppers::red; // 正确： 使用 pappers 的 red

    enum class intTypes
    {
        charTyp = 8,
        shortTyp = 16,
        intTyp = 16,
        LongTyp = 32,
        long_longTyp = 64
    };

    constexpr intTypes charbits = intTypes::charTyp;

    open_modes om = 2;    // 错误：2 不属于类型 open_modes
    open_modes om = open_modes::input;    // 正确：input 是。pen_modes 的一个枚举成员

    int i = color::red; //正确：不限定作用域的枚举类型的枚举成员隐式地转换成
    int j = peppers::red; //错误：限定作用域的枚举类型不会进行隐式转换

    enum intValues : unsigned long long
    {
        charTyp = 255,
        shortTyp = 65535,
        intTyp = 65535,
        longTyp = 4294967295UL,
        long_longTyp = 18446744073709551615ULL
    };

    //不限定作用域的枚举类型intValues的前置声明
    enum intValues : unsigned long long; //不限定作用域的，必须指定成员类型 
    enum class open_modes; //限定作用域的枚举类型可以使用默认成员类型int

    //错误：所有的声明和定义必须对该enum是限定作用域的还是不限定作用域的保持一致 
    enum class intValues;
    enum intValues;	//错误：intValues已经被声明成限定作用域的enum
    enum intValues : long; // 错误：intValues 已经被声明成 int

    //不限定作用域的枚举类型，潜在类型因机器而异
    enum Tokens
    {
        INLINE = 128,
        VIRTUAL = 129
    };

    void ff(Tokens);
    void ff(int);

    int main()
    {
        Tokens curTok = INLINE;
        ff(128);    // 精确匹配 ff(int)
        ff(INLINE); // 精确匹配 ff(Tokens)
        ff(curTok); // 青确匹配 ff(Tokens)

        return 0;
    }

    void newf(unsigned char);
    void newf(int);
    unsigned char uc = VIRTUAL;
    newf(VIRTUAL);  // 调用 newf(int)
    newf(uc);   // 调用 newf(unsigned char)
}
#endif

#ifdef Section19_4_ON
namespace Section19_4
{
    class Screen
    {
    public:
        Screen();
        typedef std::string::size_type pos;
        char get_cursor() const
        {
            return contents[cursor];
        }
        char get() const;
        char get(pos ht, pos wd)const;
        Screen& home();	//光标移动函数
        Screen& forward();
        Screen& back();
        Screen& up();
        Screen& down();

    public:
        // 其他接口和实现成员与之前一致
        // Action是一个指针，可以用任意一个光标移动函数对其赋值 
        using Action = Screen& (Screen::*)();
        // 指定具体要移动的方向，其中enum参见19.3节(第736页) 
        enum Directions
        {
            HOME, FORWARD, BACK, UP, DOWN
        };
        Screen& move(Directions);

    private:
        static Action Menu[]; // 函数表

    public:
        // data是一个静态成员，返回一个成员指针
        static const std::string Screen::* data()
        {
            return &Screen::contents;
        }
        //其他成员与之前的版本一致
    private:
        std::string contents;
        pos cursor;
        pos height, width;
    };
}
#endif
//
//namespace Section19_5
//{
//
//}