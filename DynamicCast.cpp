#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	virtual ~A() {}
	A& getA() { return *this; }
};

class B : public A
{
public:
	B& getB() { return *this; }
	
	void printFle() { cout << "Fle!\n"; }
};

class C
{
};

int main( int argc, char *argv[] ) 
{
	A* a = new A;
	B* b = new B;
	A* c = new B;
//	B* d = new A;	This is not allowed
	
	// Only b, instantiated as B can print fle
	b->printFle();
	
	std::vector<A*> v;
	v.push_back( a );
	v.push_back( b );
	v.push_back( c );
	
	cout << dynamic_cast<A*>( b ) << endl;
	
	// Can't cast from derived to base when constructed
	// as the derived class
	cout << dynamic_cast<B*>( a ) << endl;

	// Casting is fine in both directions when the object
	// is instantiated as the base
	cout << dynamic_cast<A*>( c ) << endl;
	cout << dynamic_cast<B*>( c ) << endl;
	
	A& aref = a->getA();
	B& bref = b->getB();
	
	A& bref2 = dynamic_cast<A&>( bref );

	try
	{
		dynamic_cast<B&>( aref );
	}
	catch( bad_cast& e )
	{
		cout << "Bad allocation exception caught: " << e.what() << "\n";
//		throw;	Throw again
//		throw bad_alloc();	// Throw some other exception
	}
	catch( ... ) 
	{
		cout << "General exception caught!\n";
	}
}