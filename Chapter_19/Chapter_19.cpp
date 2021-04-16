#include "Chapter_19.h"

#ifdef Section19_4_ON
Section19_4::Screen::Action Section19_4::Screen::Menu[] = {
    &Screen::home,
    &Screen::forward,
    &Screen::back,
    &Screen::up,
    &Screen::down
};

Section19_4::Screen::Screen()
{
    this->contents = "china";
    this->cursor = contents.size();
    this->height = 29;
    this->width = 3;
}

char Section19_4::Screen::get(pos ht, pos wd) const
{
    return 'a';
}

Section19_4::Screen& Section19_4::Screen::home()
{
    return *this;
}

Section19_4::Screen& Section19_4::Screen::forward()
{
    return *this;
}

Section19_4::Screen& Section19_4::Screen::back()
{
    return *this;
}

Section19_4::Screen& Section19_4::Screen::up()
{
    return *this;
}

Section19_4::Screen& Section19_4::Screen::down()
{
    return *this;
}

Section19_4::Screen& Section19_4::Screen::move(Directions cm)
{
    //����this����������ֵΪcm��Ԫ��
    return (this->*Menu[cm])(); // Menu [cm]ָ��һ����Ա����
}

char Section19_4::Screen::get() const
{
    return 'b';
}
#endif

#ifdef Section19_6_ON
Section19_6::Token& Section19_6::Token::operator=(int i)
{
    if (tok == STR)
        sval.~basic_string(); // �����ǰ�洢����string,�ͷ���.
    ival = i; // Ϊ��Ա��ֵ
    tok = INT; // �����б�ʽ
    return *this;
}


Section19_6::Token& Section19_6::Token::operator=(const std::string& s)
{
    if (tok == STR) // �����ǰ�洢����string,����ֱ�Ӹ�ֵ
        sval = s;
    else
        new (&sval) std::string(s); // ������Ҫ�ȹ���һ��string
    tok = STR; // �����б�ʽ
    return *this;
}

Section19_6::Token& Section19_6::Token::operator=(const Token& t)
{
    // ���this�����ֵ��string��t��ֵ���ǣ������Ǳ����ͷ�ԭ����string 
    if (tok == STR && t.tok != STR) 
        sval.~basic_string();

    if (tok == STR && t.tok == STR)
        sval = t.sval; // ���빹��һ���� string
    else
        copyUnion(t); // ��� t.tok �� STR,����Ҫ����һ�� string

    tok = t.tok;
    return *this;
}

void Section19_6::Token::copyUnion(const Token& t)
{
    switch (t.tok)
    {
    case Token::INT: 
        ival = t.ival; 
        break;
    case Token::CHAR: 
        eval = t.eval; 
        break;
    case Token::DBL: 
        dval = t.dval; 
        break;
    //Ҫ�뿽��һ��string����ʹ�ö�λnew���ʽ���������μ�19.1.2��(��729ҳ) 
    case Token::STR: 
        new(&sval) std::string(t.sval); 
        break;
    };
}

#endif

#ifdef Section19_7_ON
#endif

#ifdef Section19_8_ON

Section19_8::File& Section19_8::File::open(Section19_8::File::modes m)
{
    mode |= READ; //��Ĭ�Ϸ�ʽ����READ

    // ��������

    if (m & WRITE)// ������� READ �� WRITE
    {
    // ���ն�/д��ʽ���ļ� 
    }

    return *this;
}

void Section19_8::File::write()
{
    modified = 1;
    // ...
};

void Section19_8::File::close()
{
    if (modified)
        //������������
        ;
};
#endif
