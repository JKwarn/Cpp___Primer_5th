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
    //运行this对象中索引值为cm的元素
    return (this->*Menu[cm])(); // Menu [cm]指向一个成员函数
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
        sval.~basic_string(); // 如果当前存储的是string,释放它.
    ival = i; // 为成员赋值
    tok = INT; // 更新判别式
    return *this;
}


Section19_6::Token& Section19_6::Token::operator=(const std::string& s)
{
    if (tok == STR) // 如果当前存储的是string,可以直接赋值
        sval = s;
    else
        new (&sval) std::string(s); // 否则需要先构造一个string
    tok = STR; // 更新判别式
    return *this;
}

Section19_6::Token& Section19_6::Token::operator=(const Token& t)
{
    // 如果this对象的值是string而t的值不是，则我们必须释放原来的string 
    if (tok == STR && t.tok != STR) 
        sval.~basic_string();

    if (tok == STR && t.tok == STR)
        sval = t.sval; // 无须构造一个新 string
    else
        copyUnion(t); // 如果 t.tok 是 STR,则需要构造一个 string

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
    //要想拷贝一个string可以使用定位new表达式构造它，参见19.1.2节(第729页) 
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
    mode |= READ; //按默认方式设置READ

    // 其他处理

    if (m & WRITE)// 如果打开了 READ 和 WRITE
    {
    // 按照读/写方式打开文件 
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
        //……保存内容
        ;
};
#endif
