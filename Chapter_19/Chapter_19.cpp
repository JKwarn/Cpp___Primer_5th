#include "Chapter_19.h"

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
