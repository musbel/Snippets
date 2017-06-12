#include <iostream>

using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor\n"; }
	
	class Nested
	{
		public:
			Nested() { cout << "Nested Constructor\n"; }
	};	
};

class Derived : public Base
{
public:
	Derived() { cout << "Derived Constructor\n"; }
};

int main( int argc, char *argv[] ) 
{
	Derived d;
}