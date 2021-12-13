#pragma once
#include <iostream>
class MyString
{
public:
	MyString();
	MyString(const char * str);
	MyString(const MyString& other);

	MyString operator + (const MyString& other);
	MyString& operator = (const MyString& other);

	friend std::ostream& operator << (std::ostream& out, const MyString& other);
	
	void Print();
	~MyString();
private:
	char * str;
	size_t CountString(const char * string);
	int length = 0;
	
};

