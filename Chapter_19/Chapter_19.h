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

#ifdef Section19_5_ON
namespace Section19_5
{
    class TextQuery
    {
    public:
        using line_no = std::vector<std::string>::size_type;

        class QueryResult
        {
        public:
            QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f);
            static int static_mem;
        private:
            std::string sought; // 查询单词
            std::shared_ptr<std::set<line_no>> lines; // 出现的行号
            std::shared_ptr<std::vector<std::string>> file; // 输入文件
        }; //嵌套类稍后定义
           //其他成员与12.3.2节（第432页）一致


        QueryResult query(const std::string& sought) const;

    private:
        std::shared_ptr<std::vector<std::string>> file; // 输入文件
        std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // 每个单词到它到它所在的行号的集合的映射

    };

    // QueryResult是TextQuery的成员，下面的代码负责定义QueryResult
    class TextQuery::QueryResult
    {
        // 位于类的作用域内，因此我们不必对QueryResult形参进行限定
        friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        // 无须定义 QueryResult::
        // 嵌套类可以直接使用外层类的成员，无须对该成员的名字进行限定
        QueryResult(std::string,
            std::shared_ptr<std::set<line_no>>,
            std::shared_ptr<std::vector<std::string>>);
        //其他成员与12.3.2节（第432页）一致
    };

    // QueryResult 类嵌套在 TextQuery 类中
    // 下面的代码为QueryResult类定义名为QueryResult的成员
    TextQuery::QueryResult::QueryResult(std::string s, 
        std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f)
        :sought(s), lines(p), file(f)
    {
    };

    // QueryResult 类嵌套在 TextQuery 类中，
    // 下面的代码为QueryResult定义一个静态成员
    int TextQuery::QueryResult::static_mem = 1024;

    // 返回类型必须指明QueryResult是一个嵌套类
    TextQuery::QueryResult TextQuery::query(const std::string& sought) const
    {
        // 如果我们没有找到sought,则返回set的指针
        static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
        // 使用find而非下标以避免向wm中添加单词
        auto loc = wm.find(sought);
        if (loc == wm.end())
        {
            return QueryResult(sought, nodata, file);	// 没有找到
        }
        else
        {
            return QueryResult(sought, loc->second, file);
        }
    }

}
#endif

#ifdef Section19_6_ON
namespace Section19_6
{
    // Token类型的对象只有一个成员，该成员的类型可能是下列类型中的任意一种
    //union Token
    //{
    //    // 默认情况下成员是公有的
    //    char eval;
    //    int ival;
    //    double dval;
    //};

    // 在命名空间中声明，匿名union需要静态声明
    static union
    {// 匿名 union
        char eval;
        int ival;
        double dval;
    }; //定义一个未命名的对象，我们可以直接访问它的成员

    class Token
    {
    public:
        // 因为union含有一个string成员，所以Token必须定义拷贝控制成员
        // 定义移动构造函数和移动赋值运算符的任务留待本节练习完成
        Token() :tok(INT), ival{0}
        { };
        Token(const Token& t) :tok(t.tok)
        {
            copyUnion(t);
        };

        Token& operator=(const Token&);
        // 如果union含有一个string成员，则我们必须销毁它，参见19.1.2节(第729页)
        ~Token()
        {
            if (tok == STR) 
                sval.~basic_string();
        };
        // 下面的赋值运算符负责设置union的不同成员
        Token& operator=(const std::string&);
        Token& operator=(char);
        Token& operator=(int);
        Token& operator=(double);
    private:
        enum
        {
            INT, CHAR, DBL, STR
        }tok;
        union 
        {
            char eval;
            int ival;
            double dval;
            std::string sval;
        };// 每个Token对象含有一个该未命名union类型的未命名成员 
          
        // 检查判别式，然后酌情拷贝union成员
        void copyUnion(const Token&);
    }; 
}
#endif

#ifdef Section19_7_ON
namespace Section19_7
{

    int a, val;
    void foo(int val)
    {
        static int si;
        enum Loc
        {
            a = 1024, b
        };
        //// Bar是foo的局部类
        //struct Bar
        //{
        //    Loc locVal; //正确：使用一个局部类型名
        //    int barVal;
        //    void fooBar(Loc l = a)
        //    { // 正确：默认实参是 Loc: :a

        //        barVal = ::val; // 正确：使用一个全局对象
        //        barVal = si;    // 正确：使用一个静态局部对象
        //        locVal = b;     // 正确：使用一个枚举成员
        //    }
        //};

        class Bar
        {
        public:
            // ...
            class Nested; // 声明 Nested 类
        };
        //定义Nested类
        class Bar::Nested
        {
            // ...
        };
        // ...
    };
}
#endif

#ifdef Section19_8_ON
namespace Section19_8
{
    typedef unsigned int Bit; 
    class File
    {
        Bit mode : 2; // mode占2位
        Bit modified : 1; // modified 占 1 位
        Bit prot_owner : 3; // prot_owner 占 3 位
        Bit prot_group : 3; // prot_group 占 3 位
        Bit protworld : 3; // prot_world 占 3 位
    // File的操作和数据成员
    public:
        //文件类型以八进制的形式表示，参见2.1.3节(第35页)
        enum modes
        {
            READ = 01, WRITE = 02, EXECUTE = 03
        };
        File& open(modes);
        void close();
        void write();
        bool isRead() const;
        void setWrite();
    };
    inline bool File::isRead() const
    {
        return mode & READ;
    };

    inline void File::setWrite()
    {
        mode |= WRITE;
    };


    class Foo
    {
    public:
        Foo(const volatile Foo&); // 从一个 volatile 对象进行拷贝
        //将一个volatile对象赋值给一个非volatile对象
        Foo& operator=(volatile const Foo&);
        //将一个volatile对象赋值给一个volatile对象
        Foo& operator=(volatile const Foo&) volatile;
        // Foo类的剩余部分
    };

    // 可能出现在C++头文件＜cstring＞中的链接指示
    // 单语句链接指示
    extern "C" size_t strlen(const char*);
    //复合语句链接指宗
    extern "C"{
        int strcmp(const char*, const char*);
        char* strcat(char*, const char*);
    }

    // 复合语句链接指示
    extern "C" {
        #include <string.h> // 操作C风格字符串的C函数
    };

    // pf指向一个C函数，该函数接受一个int返回void
    extern "C" void (*pf) (int);

    //void (*pfl)(int); // 指向一个 C++函数
    //extern "C" void (*pf2)(int); // 指向一个 C 函数
    //pf1 = pf2; // 错误：pfl和pf2的类型不同

    // fl是一个C函数，它的形参是一个指向C函数的指针
    extern "C" void fl(void(*)(int));

    // FC是一个指向C函数的指针
    extern "C" typedef void FC(int);
    // f2是一个C++函数，该函数的形参是指向C函数的指针
    void f2(FC*);

    // calc函数可以被C程序调用
    extern "C" double calc(double dparm)
    { 
        /*...*/
    };

    //错误：两个extern 函数的名字相同
    extern "C" void print(const char*);
    extern "C" void print(int);


    class SmallInt {/*...*/};
    class BigNum {/*...*/};
    // C函数可以在C或C++程序中调用
    // C++函数重载了该函数，可以在C++程序中调用
    extern "C" double calc(double);
    extern SmallInt calc(const SmallInt&);
    extern BigNum calc(const BigNum&);

}
#endif