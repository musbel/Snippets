#include <iostream>

using namespace std;

template <class T>
class Base
{
public:
	virtual ~Base();
};

template <class T, class Q>
class Derived : public Base<T>
{
	
};

int main( int argc, char *argv[] ) 
{
//	Derived<int, int> d;
}