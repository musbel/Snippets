#include <iostream>

using namespace std;

struct A
{
	A() : value( 10 ) { cout << "Construct A\n"; }
	virtual ~A() { cout << "Destruct A\n"; }
	int value;
};

class B : public A
{
public:
	int getValue()
	{
		return value;
	}
};

int main( int argc, char *argv[] ) 
{
	B b;
	cout << b.getValue() << endl;
	
	B* bs = new B[2];
	cout << bs[0].getValue() << endl;
	cout << (bs + 1)->getValue() << endl;
	cout << &bs[1] << endl;
	cout << &*(bs + 1) << endl;
//	cout << *(bs + 1)->getValue() << endl;
	delete[] bs;
}