#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
	string firstName;
	string lastName;
	int age;
	
	Person( const string& firstName, const string& lastName, int age ) :
		firstName( firstName), lastName( lastName ), age( age ) {}
};

void print( const vector<Person>& people, const string& title )
{
	cout << "--" << title << "--\n";
	for_each( people.begin(), people.end(), [] ( const Person& p )
		{
			cout << p.firstName << " " << p.lastName << " | age = " << p.age << endl;
		}
	);
	cout << endl;
}

bool lastNameSort( const Person& p1, const Person& p2 )
{
	return p1.lastName < p2.lastName;
}

struct Sorter
{
	enum
	{
		FIRST_NAME,
		LAST_NAME,
		AGE
	};
	
	int sortType;
	
	Sorter( int sortType = LAST_NAME ) : sortType( sortType ) {}
	
	bool operator() ( const Person& p1, const Person& p2 )
	{
		if( sortType == FIRST_NAME )
		{
			return p1.firstName < p2.firstName;
		}
		else if( sortType == LAST_NAME )
		{
			return p1.lastName < p2.lastName;
		}
		else if( sortType == AGE )
		{
			return p1.age < p2.age;
		}
		
		return false;	
	}
};

int main( int argc, char *argv[] ) 
{
	vector<Person> people;
	people.push_back( Person( "Bob", "Hansen", 10 ) );
	people.push_back( Person( "Thomas", "Sterling", 20 ) );
	people.push_back( Person( "Scott", "Aron", 15 ) );
	people.push_back( Person( "George", "Brown", 32 ) );

	print( people, "Unsorted" );
	
//	sort( people.begin(), people.end(), lastNameSort );
	
	Sorter sorter( Sorter::AGE );
	sort( people.begin(), people.end(), sorter );

	print( people, "Sorted" );
}