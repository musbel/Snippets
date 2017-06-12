#include <iostream>
#include <vector>

using namespace std;

class Person
{
public:
	Person()
	{
//		test();
//		greet();	
	}
	
	virtual ~Person() {}
	
	virtual void greet() = 0;
	void test();
};

class Spanish : public Person
{
public:
	void greet() { cout << "Hola!" << endl; }
};

class English : public Person
{
public:
	void greet() { cout << "Hello!" << endl; }
};

int main( int argc, char *argv[] ) 
{
	vector<Person*> people;
	people.push_back( new Spanish() );
	people.push_back( new English() );
	
	for ( vector<Person*>::iterator it = people.begin(); it != people.end(); ++it )
		(*it)->greet();
}