#include <iostream>
#include <vector>

using namespace std;

static vector<int> m;

static int FibonacciRecursive( int n )
{
//	if( n == 0 )
//		return 0;
//	if( n == 1 )
//		return 1;
//	
	if( n < 2 )
		return 1;

	return FibonacciRecursive( n - 1 ) + FibonacciRecursive( n - 2 );
}

static int FibonacciRecursiveDP( int n )
{
	if( n == 0 )
		m[n] = 0;
	else if( n == 1 )
		m[n] = 1;
	else
		m[n] = FibonacciRecursiveDP( n - 1 ) + FibonacciRecursiveDP( n - 2 );
	
	return m[n];
}

static int FibonacciIterative( int n )
{
	if( n == 0 )
		return 0;
	if( n == 1 )
		return 1;

	int prevPrev = 0;
	int prev = 1;
	int result = 0;
	
	for( int i = 2; i <= n; ++i )
	{
		result = prevPrev + prev;
		prevPrev = prev;
		prev = result;
	}
	
	return result;
}

int main( int argc, char* argv[] ) 
{
	m.reserve( 100 );
	for( int i = 1; i < 12; ++i )
		cout << "Fibonacci: " << i << " = " << FibonacciRecursiveDP( i ) << endl;
}