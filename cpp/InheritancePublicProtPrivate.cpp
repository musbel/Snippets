#include <iostream>

using namespace std;

class A
{
	int a1;
	
protected:
	int a2;
	
public:
	A() : a1( 1 ), a2( 2 ), a3( 3 ) {}
	virtual ~A() {}
	int a3;
};

class B : protected A
{
	int b1;
	
protected:
	int b2;
	
public:
	B() : b4( A::a2 ), b2( A::a3 ) {}
	int b3;
	int b4;
};

class C : private B
{
	int c1;
	
public:
	C() : c2( B::b2 ) {}
	int c2;
	int c3;
};

int main( int argc, char *argv[] ) 
{
	A a;
	B b;
	C c;
	
	cout << b.b4 << endl;
	cout << c.c2 << endl;

}