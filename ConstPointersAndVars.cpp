#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int a = 2;
	int b = 4;
	
	////
	// Pointer to a const (read-only) variable
	// const int* ptr = &a;
	const int *ptr = &a;	// Same as above but easier to remember
	cout << "ptr = " << *ptr << " | " << ptr << " | " << &ptr << endl;
	
	ptr = &b;
	cout << "ptr = " << *ptr << " | " << ptr << " | " << &ptr << endl;

	// This is not allowed as the variable is const
	// *ptr = 1;
	// cout << "ptr = " << *ptr << " | " << ptr << " | " << &ptr << endl;

	////
	// A const pointer to a non-const variable
	// int* const constPtr = &a
	int const *constPtr = &a;	// Same as above but easier to remember
	cout << "constPtr = " << *constPtr << " | " << constPtr << " | " << &constPtr << endl;
	
	// This is not allowed as the pointer is const
	// and can't be reassigned to a different address
	// constPtr = &b;

	////
	// Const pointer to a const (read-only) variable
	const int* const ccPtr = &a;
	cout << "ccPtr = " << *ccPtr << " | " << ccPtr << " | " << &ccPtr << endl;
	
	// Now I can neither change the pointer address nor the variable value
	// ccPtr = &b;
	// *ccPtr = 5;
}