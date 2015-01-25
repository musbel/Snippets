#include <iostream>

using namespace std;

class Base
{
public:
	Base() : topping( "cheese" )
	{
		topping += " and onion";
		cout << "Base" << endl; 
	}
	
	virtual ~Base() { cout << "Destroy Base" << endl; };

	virtual void taco()
	{
		cout << "Base taco with " << topping << endl;
	}
	
protected:
	string topping;
};

class Derived : public Base
{
public:
	Derived() { cout << "Derived" << endl; }
	~Derived() { cout << "Destroy Derived" << endl; }
	
	virtual void taco()
	{
		cout << "Derived taco with " << topping << endl;
	}
};

int main( int argc, char *argv[] ) 
{
	Derived d;
	d.taco();
}