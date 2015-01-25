#include <iostream>

using namespace std;

class Object
{
public:
	Object() {}
	void print() const { cout << "Const\n"; }
	void print() { cout << "Mutable\n"; }
	
	void print() volatile
	{
		cout << "Volatile" << endl;
	}

	void print() const volatile
	{
		cout << "Volatile const" << endl;
	}
};

void printObject( const Object& obj )
{
	obj.print();
}

int main( int argc, char *argv[] ) 
{
	Object o1;
	const Object o2;
	Object* const po1 = &o1;	// Const pointer to a mutable object
	const Object *po2 = &o1;	// Pointer to a const (read-only) object
	
	volatile Object vo;
	vo.print();
	
	cout << ">> Const print function\n";
	printObject( o1 );
	printObject( o2 );
	
	cout << "<< Object print function\n";
	o1.print();
	o2.print();
	
	cout << ">> Pointers\n";
	po1->print();
	po2->print();
	
	return 0;
}