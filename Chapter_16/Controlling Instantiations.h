#pragma once
#include "..\pch.h"
#include "Blob.h"

using namespace Section_16_1_5;
//ʵ���������붨��
//extern template class Blob<std::string>; // ����


template
int Section_16_1_5::compare(const int&, const int&, std::less<int>); // ����

// templateBuild.cc
// ʵ�����ļ�������Ϊÿ���������ļ�������Ϊ extern �����ͺͺ�����
// �ṩһ��(�� extern )�Ķ���
template int Section_16_1_5::compare(const int&, const int&);
template class Blob<string>; //ʵ������ģ������г�Ա