#include <iostream>

using namespace std;

class Person
{
public:
	Person() {}
	Person( const string& name ) : name( name ) {}
	virtual ~Person() {}

	string name;
};

class Employee : public Person
{
public:
	Employee( const string& name ) : Person( name ) {}
};

int main( int argc, char *argv[] ) 
{	
	Person bob( "Bob" );
	Person* bobsTwin = &bob;
	const std::type_info& infoBob = typeid(bob);
	const std::type_info& infoBob2 = typeid(* bobsTwin);
	cout << infoBob.name() << endl;
	cout << infoBob2.name() << endl;
	cout << ( infoBob == infoBob2 ) << endl;
	cout << "Person (bob) = " << bob.name << endl;
	
	Employee e( "Tod" );
	cout << "Employee (e) = " << e.name << endl;
	
//	cout << typeid(Person) << endl;
}