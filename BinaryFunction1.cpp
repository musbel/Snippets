#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Person
{
	string name;
	int age;
	Person();
	Person( string name, int age ) : name( name ), age( age ) {}
};

struct Compare : public binary_function<Person, int, bool>
{
	bool operator() ( const Person& p, int age ) const
	{
		return ( p.age == age );
	}
};

struct Bah : public unary_function<Person, bool>
{
	bool operator() ( const Person& p )
	{
		return p.name == "Ted";
	}
};

bool isTed( const Person& p )
{
	return p.name == "Ted";
}

int main( int argc, char *argv[] ) 
{
//	Compare compareObject;
//	Compare::first_argument_type input1;
//	Compare::second_argument_type input2;
//	Compare::result_type result;
//	
//	int num1 = 2;
//	int num2 = 2;
//	
//	result = compareObject( num1, num2 );
//	cout << result << endl;
	
	vector<Person> v;
	v.push_back( Person( "Bob", 22 ) );
	v.push_back( Person( "Ted", 34 ) );
	v.push_back( Person( "Alf", 22 ) );
	v.push_back( Person( "Greg", 41 ) );
	
	vector<int> ages;
	ages.push_back( 10 );
	ages.push_back( 22 );
	
	vector<Person>::iterator it = find_if( v.begin(), v.end(), bind2nd<Compare>( Compare(), 34 ) );
	cout << "Look for age: " << it->name << endl;

	Person p( "Anne", 22 );
	vector<int>::iterator itAge = find_if( ages.begin(), ages.end(), bind1st<Compare>( Compare(), p ) );
	cout << "Look for person: " << *itAge << endl;

	cout << "Num = 22: " << count_if( v.begin(), v.end(), bind2nd<Compare>( Compare(), 22 ) ) << endl;
	cout << "Num = 34: " << count_if( v.begin(), v.end(), bind2nd<Compare>( Compare(), 34 ) ) << endl;
	
	find_if( v.begin(), v.end(), Bah() );
	cout << "Is Ted: " << count_if( v.begin(), v.end(), isTed ) << endl;
}