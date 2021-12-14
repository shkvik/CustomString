#include "MyString.h"


//����������� �� ���������
MyString::MyString()
{
	str = nullptr;
}

//Constructor for take const char[]
MyString::MyString(const char* string)
{
	length = (int)CountString(string);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = string[i];
	}
	this->str[length] = '\0';
}

//������� ������
size_t MyString::CountString(const char* string) {
	size_t result = 0;
	while (*(string)++) { result++; }
	return result;
}
//���������� ������������
MyString& MyString::operator = (const MyString& other)
{
	if (this->str != nullptr) delete[] str;
	length = (int)CountString(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
	return *this;
}
//���������� �������������
MyString MyString::operator + (const MyString& other)
{
	MyString newStr;

	int thisLength = (int)CountString(this->str);
	int otherLengh = (int)CountString(other.str);

	newStr.str = new char[thisLength + otherLengh + 1];

	int i = 0;
	for (; i < thisLength; i++) {
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLengh; j++, i++) {
		newStr.str[i] = other.str[j];
	}
	newStr.str[thisLength + otherLengh] = '\0';

	return newStr;
}
//����������� ����������� 
MyString::MyString(const MyString& other)
{
	length = (int)CountString(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
}

//�������� ��� ������ ������ � �������
std::ostream& operator << (std::ostream& out, const MyString& other)
{
	out << other.str;
	return out;
}


//������������ ������� ������, �� ������� ��������� ��������� str � ����
MyString::~MyString()
{
	delete[] this->str;
}

//������� �����
void MyString::Print() {
	std::cout << str;
}