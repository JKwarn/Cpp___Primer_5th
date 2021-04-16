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
        // 19.2.3 ʹ��RTTI
        class Base
        {
        public:
            friend bool operator==(const Base&, const Base&);

            // ʹ�� dynamic_cast����������Ҫһ���麯����
            // ����2����
            // 1. ����ʱ dynamic_cast �Ĳ��������������̬������ 
            // 2. ��dynamic_cast�� : ��Base�����Ƕ�̬����	�������� 
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
        // 19.2.3 ʹ��RTTI
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
    // ���޶��������ö������
    enum color
    {
        red,
        yellow,
        green
    };

    // δ���������޶��������ö������
    enum
    {
        floatPrec = 6,
        doublePrec = 10,
        double_doubleprec = 10
    };
    /************************************************************************/

    // ���޶��������ö������
    enum color
    {
        red,
        yellow,
        green
    };

    // �����ظ�������ö�ٳ�Ա��color��stoplight��ͻ����Ϊ���޶��������ö�ٹ����������
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
    }; // ��ȷ�� ö�ٳ�Ա��������


    color eyes = green; // ��ȷ�����޶��������ö�����͵�ö�ٳ�Աλ����Ч����������
    peppers p = green;  // ����peppers��ö�ٳ�Ա������Ч��������
                        // color::green����Ч���������У��������ʹ���
    color hair = color::red; // ��ȷ��������ʽ�ط���ö�ٳ�Ա
    peppers p2 = peppers::red; // ��ȷ�� ʹ�� pappers �� red

    enum class intTypes
    {
        charTyp = 8,
        shortTyp = 16,
        intTyp = 16,
        LongTyp = 32,
        long_longTyp = 64
    };

    constexpr intTypes charbits = intTypes::charTyp;

    open_modes om = 2;    // ����2 ���������� open_modes
    open_modes om = open_modes::input;    // ��ȷ��input �ǡ�pen_modes ��һ��ö�ٳ�Ա

    int i = color::red; //��ȷ�����޶��������ö�����͵�ö�ٳ�Ա��ʽ��ת����
    int j = peppers::red; //�����޶��������ö�����Ͳ��������ʽת��

    enum intValues : unsigned long long
    {
        charTyp = 255,
        shortTyp = 65535,
        intTyp = 65535,
        longTyp = 4294967295UL,
        long_longTyp = 18446744073709551615ULL
    };

    //���޶��������ö������intValues��ǰ������
    enum intValues : unsigned long long; //���޶�������ģ�����ָ����Ա���� 
    enum class open_modes; //�޶��������ö�����Ϳ���ʹ��Ĭ�ϳ�Ա����int

    //�������е������Ͷ������Ը�enum���޶�������Ļ��ǲ��޶�������ı���һ�� 
    enum class intValues;
    enum intValues;	//����intValues�Ѿ����������޶��������enum
    enum intValues : long; // ����intValues �Ѿ��������� int

    //���޶��������ö�����ͣ�Ǳ���������������
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
        ff(128);    // ��ȷƥ�� ff(int)
        ff(INLINE); // ��ȷƥ�� ff(Tokens)
        ff(curTok); // ��ȷƥ�� ff(Tokens)

        return 0;
    }

    void newf(unsigned char);
    void newf(int);
    unsigned char uc = VIRTUAL;
    newf(VIRTUAL);  // ���� newf(int)
    newf(uc);   // ���� newf(unsigned char)
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
        Screen& home();	//����ƶ�����
        Screen& forward();
        Screen& back();
        Screen& up();
        Screen& down();

    public:
        // �����ӿں�ʵ�ֳ�Ա��֮ǰһ��
        // Action��һ��ָ�룬����������һ������ƶ��������丳ֵ 
        using Action = Screen& (Screen::*)();
        // ָ������Ҫ�ƶ��ķ�������enum�μ�19.3��(��736ҳ) 
        enum Directions
        {
            HOME, FORWARD, BACK, UP, DOWN
        };
        Screen& move(Directions);

    private:
        static Action Menu[]; // ������

    public:
        // data��һ����̬��Ա������һ����Աָ��
        static const std::string Screen::* data()
        {
            return &Screen::contents;
        }
        //������Ա��֮ǰ�İ汾һ��
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
            std::string sought; // ��ѯ����
            std::shared_ptr<std::set<line_no>> lines; // ���ֵ��к�
            std::shared_ptr<std::vector<std::string>> file; // �����ļ�
        }; //Ƕ�����Ժ���
           //������Ա��12.3.2�ڣ���432ҳ��һ��


        QueryResult query(const std::string& sought) const;

    private:
        std::shared_ptr<std::vector<std::string>> file; // �����ļ�
        std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // ÿ�����ʵ����������ڵ��кŵļ��ϵ�ӳ��

    };

    // QueryResult��TextQuery�ĳ�Ա������Ĵ��븺����QueryResult
    class TextQuery::QueryResult
    {
        // λ������������ڣ�������ǲ��ض�QueryResult�βν����޶�
        friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        // ���붨�� QueryResult::
        // Ƕ�������ֱ��ʹ�������ĳ�Ա������Ըó�Ա�����ֽ����޶�
        QueryResult(std::string,
            std::shared_ptr<std::set<line_no>>,
            std::shared_ptr<std::vector<std::string>>);
        //������Ա��12.3.2�ڣ���432ҳ��һ��
    };

    // QueryResult ��Ƕ���� TextQuery ����
    // ����Ĵ���ΪQueryResult�ඨ����ΪQueryResult�ĳ�Ա
    TextQuery::QueryResult::QueryResult(std::string s, 
        std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f)
        :sought(s), lines(p), file(f)
    {
    };

    // QueryResult ��Ƕ���� TextQuery ���У�
    // ����Ĵ���ΪQueryResult����һ����̬��Ա
    int TextQuery::QueryResult::static_mem = 1024;

    // �������ͱ���ָ��QueryResult��һ��Ƕ����
    TextQuery::QueryResult TextQuery::query(const std::string& sought) const
    {
        // �������û���ҵ�sought,�򷵻�set��ָ��
        static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
        // ʹ��find�����±��Ա�����wm����ӵ���
        auto loc = wm.find(sought);
        if (loc == wm.end())
        {
            return QueryResult(sought, nodata, file);	// û���ҵ�
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
    // Token���͵Ķ���ֻ��һ����Ա���ó�Ա�����Ϳ��������������е�����һ��
    //union Token
    //{
    //    // Ĭ������³�Ա�ǹ��е�
    //    char eval;
    //    int ival;
    //    double dval;
    //};

    // �������ռ�������������union��Ҫ��̬����
    static union
    {// ���� union
        char eval;
        int ival;
        double dval;
    }; //����һ��δ�����Ķ������ǿ���ֱ�ӷ������ĳ�Ա

    class Token
    {
    public:
        // ��Ϊunion����һ��string��Ա������Token���붨�忽�����Ƴ�Ա
        // �����ƶ����캯�����ƶ���ֵ���������������������ϰ���
        Token() :tok(INT), ival{0}
        { };
        Token(const Token& t) :tok(t.tok)
        {
            copyUnion(t);
        };

        Token& operator=(const Token&);
        // ���union����һ��string��Ա�������Ǳ������������μ�19.1.2��(��729ҳ)
        ~Token()
        {
            if (tok == STR) 
                sval.~basic_string();
        };
        // ����ĸ�ֵ�������������union�Ĳ�ͬ��Ա
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
        };// ÿ��Token������һ����δ����union���͵�δ������Ա 
          
        // ����б�ʽ��Ȼ�����鿽��union��Ա
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
        //// Bar��foo�ľֲ���
        //struct Bar
        //{
        //    Loc locVal; //��ȷ��ʹ��һ���ֲ�������
        //    int barVal;
        //    void fooBar(Loc l = a)
        //    { // ��ȷ��Ĭ��ʵ���� Loc: :a

        //        barVal = ::val; // ��ȷ��ʹ��һ��ȫ�ֶ���
        //        barVal = si;    // ��ȷ��ʹ��һ����̬�ֲ�����
        //        locVal = b;     // ��ȷ��ʹ��һ��ö�ٳ�Ա
        //    }
        //};

        class Bar
        {
        public:
            // ...
            class Nested; // ���� Nested ��
        };
        //����Nested��
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
        Bit mode : 2; // modeռ2λ
        Bit modified : 1; // modified ռ 1 λ
        Bit prot_owner : 3; // prot_owner ռ 3 λ
        Bit prot_group : 3; // prot_group ռ 3 λ
        Bit protworld : 3; // prot_world ռ 3 λ
    // File�Ĳ��������ݳ�Ա
    public:
        //�ļ������԰˽��Ƶ���ʽ��ʾ���μ�2.1.3��(��35ҳ)
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
        Foo(const volatile Foo&); // ��һ�� volatile ������п���
        //��һ��volatile����ֵ��һ����volatile����
        Foo& operator=(volatile const Foo&);
        //��һ��volatile����ֵ��һ��volatile����
        Foo& operator=(volatile const Foo&) volatile;
        // Foo���ʣ�ಿ��
    };

    // ���ܳ�����C++ͷ�ļ���cstring���е�����ָʾ
    // ���������ָʾ
    extern "C" size_t strlen(const char*);
    //�����������ָ��
    extern "C"{
        int strcmp(const char*, const char*);
        char* strcat(char*, const char*);
    }

    // �����������ָʾ
    extern "C" {
        #include <string.h> // ����C����ַ�����C����
    };

    // pfָ��һ��C�������ú�������һ��int����void
    extern "C" void (*pf) (int);

    //void (*pfl)(int); // ָ��һ�� C++����
    //extern "C" void (*pf2)(int); // ָ��һ�� C ����
    //pf1 = pf2; // ����pfl��pf2�����Ͳ�ͬ

    // fl��һ��C�����������β���һ��ָ��C������ָ��
    extern "C" void fl(void(*)(int));

    // FC��һ��ָ��C������ָ��
    extern "C" typedef void FC(int);
    // f2��һ��C++�������ú������β���ָ��C������ָ��
    void f2(FC*);

    // calc�������Ա�C�������
    extern "C" double calc(double dparm)
    { 
        /*...*/
    };

    //��������extern ������������ͬ
    extern "C" void print(const char*);
    extern "C" void print(int);


    class SmallInt {/*...*/};
    class BigNum {/*...*/};
    // C����������C��C++�����е���
    // C++���������˸ú�����������C++�����е���
    extern "C" double calc(double);
    extern SmallInt calc(const SmallInt&);
    extern BigNum calc(const BigNum&);

}
#endif