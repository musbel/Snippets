#include <iostream>

using namespace std;

class Employee;

class Person
{
	friend class Employee;
	
	string name;

public:	
	Person( const string& name ) : name( name ) {}
};

class Employee
{
	string name;
	
public:
	Employee( const Person& person ) : name( person.name ) {}
	string getName() const { return name; }
};

int main( int argc, char *argv[] ) 
{
	Person p( "Bob" );
	Employee e( p );
	cout << e.getName() << endl;
}