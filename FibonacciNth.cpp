#include <iostream>

using namespace std;

int fib( int n, int d = 2 )
{
	if ( n < d )
		return 1;

	int result = 0;
	for ( int i = d; i > 0; --i )
	{
		result += fib( n - i, d );
	}

//	return fib( n - 1 ) + fib( n - 2 );
	return result;
}

int main( int argc, char *argv[] ) 
{
	for ( int i = 0; i < 6; ++i )
		cout << fib( i, 3 ) << endl;
}