#pragma once
#include <iostream>
class MyString
{
public:
	//Constructors
	MyString();
	MyString(const char * str);
	MyString(const MyString& other);

	//Operators overloading
	MyString operator + (const MyString& other);
	MyString& operator = (const MyString& other);

	//Method for output std::cout
	friend std::ostream& operator << (std::ostream& out, const MyString& other);
	
	//Destructoor
	~MyString();

private:
	char * str;
	size_t CountString(const char * string);
	int length = 0;
	
};

