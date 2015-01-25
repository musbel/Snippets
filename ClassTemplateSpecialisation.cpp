#include <iostream>
#include <map>

using namespace std;

template <typename X, typename Y>
class Mapper
{
	map<X, Y> m;
	
public:
	void insert( const X& x, const Y& y ) 
	{
		m[x] = y;
	}
	
	const Y& operator[] ( const X& x )
	{
		return m[x];
	}
};

template <typename X>
class Mapper<X, int>
{
	map<X, int> m;
	int shiftedValue;	// No warning when returning [] as the variable will still be alive
	
public:
	void insert( const X& x, const int y )
	{
		m[x] = y;
	}
	
	const int& operator[] ( const X& x )
	{
		shiftedValue = m[x] + 100;
		return shiftedValue;
	}
};

int main( int argc, char *argv[] ) 
{
	Mapper<int, string> mapper;
	mapper.insert( 1, "Bob" );
	
	Mapper<int, int> intMapper;
	intMapper.insert( 2, 4 );
	
	cout << mapper[1] << endl;
	cout << intMapper[2] << endl;
}