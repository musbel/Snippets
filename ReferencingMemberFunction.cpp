#include <iostream>

using namespace std;

class A
{
public:
	void hello( const string& name )
	{
		cout << "Hello " << name << endl;
	}
};

int main( int argc, char *argv[] ) 
{
	A* a = new A();
	
	cout << "a = " << a << endl;
	cout << "*a = " << &*a << endl;		// Reference to pointer
	
	a->hello( "Bob" );
	(*a).hello( "Tod" );
	
	(&*a)->hello( "Tod" );
	
	delete a;
}