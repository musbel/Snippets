#include <iostream>
#include <exception>
#include <memory>

using namespace std;

//struct SomeExc : public exception
//{
//	const char* what() const noexcept
//	{
//		return "Bob";
//	}
//};

struct Person
{
	typedef shared_ptr<Person> Ptr;
	typedef shared_ptr<const Person> ConstPtr;
	typedef unique_ptr<Person> Unique;
	
	string name;

	Person( const string& name ) : name( name ) { cout << "Create [" << name << "]" << endl; }
	virtual ~Person() { cout << "Destroy [" << name << "]" << endl; }
};

struct T
{
	T() { cout << "Create T" << endl; }
	virtual ~T() { cout << "Destroy T" << endl; }
};

class A
{
public:
	Person::Ptr fred;
	Person::Unique uniqueBob;
//	unique_ptr<int> p = unique_ptr<int>( new int( 2 ) );
	T t;
	string name = "Flebbi";

	A()
	{
		cout << "Construct A" << endl;
		fred = make_shared<Person>( "Fred" );
		uniqueBob = Person::Unique( new Person( "Bob" ) );
//		throw SomeExc();
		throw exception();
	}
	
	virtual ~A() { cout << "Destroy A" << endl; }
	
	void print() const
	{
		cout << "name = " << name << endl;
	}
};

class B
{
public:
//	A a;
	A* a;
	
	B()
	{
		cout << "Construct B" << endl;
		
		try 
		{
//			A b;
			a = new A();
		} 
		catch ( ... )
		{
			cout << "Caught exception..." << endl;
		}
	}
	
	virtual ~B()
	{
		cout << "Destroy B: " << a << endl;
		delete a;
		a = NULL;
	}
	
	void speak() const
	{
//		cout << "Morning." << endl;
		if ( a )
			a->print();
	}
};

int main( int argc, char *argv[] ) 
{
	B b;
	b.speak();
}