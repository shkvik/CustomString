#include "MyString.h"


//Конструктор по умолчанию
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

//Считаем строки
size_t MyString::CountString(const char* string) {
	size_t result = 0;
	while (*(string)++) { result++; }
	return result;
}
//Реализация присваивания
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
//Реализация конкантенации
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
//Конструктор копирования 
MyString::MyString(const MyString& other)
{
	length = (int)CountString(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
}

//Оператор для вывода потока в консоль
std::ostream& operator << (std::ostream& out, const MyString& other)
{
	out << other.str;
	return out;
}


//Освобождение области памяти, на которую указывает указатель str в куче
MyString::~MyString()
{
	delete[] this->str;
}

//Удалить потом
void MyString::Print() {
	std::cout << str;
}