#pragma once
#include "..\pch.h"
#include "Blob.h"

using namespace Section_16_1_5;
//实例化声明与定义
//extern template class Blob<std::string>; // 声明


template
int Section_16_1_5::compare(const int&, const int&, std::less<int>); // 定义

// templateBuild.cc
// 实例化文件，必须为每个在其他文件中声明为 extern 的类型和函数，
// 提供一个(非 extern )的定义
template int Section_16_1_5::compare(const int&, const int&);
template class Blob<string>; //实例化类模板的所有成员