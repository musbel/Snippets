#include <iostream>

using namespace std;

class X
{
public:
	X() { cout << "Construct X\n"; }
	virtual ~X() { cout << "Destruct X\n"; }
	
	void taco() { cout << "Cheese\n"; }
};

class Y
{
public:
	Y() { cout << "Construct Y\n"; }
	virtual ~Y() { cout << "Destruct Y\n"; }
};

class T1 : public virtual X
{
public:
	T1() { cout << "Construct T1\n"; }
	virtual ~T1() { cout << "Destruct T1\n"; }
};

class T2 : public virtual X
{
public:
	T2() { cout << "Construct T2\n"; }
	virtual ~T2() { cout << "Destruct T2\n"; }
};

// Note here that the destructor for the non-virtual base
// class Y will be called before the destructors for the
// virtual base classes T1 and T2
class TM : virtual public T1, virtual public T2, public Y
{
public:
	TM() { cout << "Construct TM\n"; }
	virtual ~TM() { cout << "Destruct TM\n"; }
};

class A
{
public:
	A() { cout << "Construct A\n"; }
	virtual ~A() { cout << "Destruct A\n"; }
};

class B : public A
{
public:
	B() { cout << "Construct B\n"; }
	virtual ~B() { cout << "Destruct B\n"; }
	
	X x;
};

class C
{
public:
	C() { cout << "Construct C\n"; t.taco(); }
	virtual ~C() { cout << "Destruct C\n"; }
	
	B b;
	X x;
	TM t;
	Y y;
};

int main( int argc, char *argv[] ) 
{
	C c;
}