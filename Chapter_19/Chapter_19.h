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
//
//namespace Section19_5
//{
//
//}