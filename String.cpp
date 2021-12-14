#include <iostream>
#include "MyString.h"


int main()
{
	MyString test("123");
	MyString teste("4565");
	MyString result = test + teste;

	std::cout << result;
	return 0;
}
    
