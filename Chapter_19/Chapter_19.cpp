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
    //运行this对象中索引值为cm的元素
    return (this->*Menu[cm])(); // Menu [cm]指向一个成员函数
}

char Section19_4::Screen::get() const
{
    return 'b';
}
