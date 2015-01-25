#include <iostream>

using namespace std;

static int FactorialRecursive( int n )
{
	if( n <= 1 )
		return 1;
	
	return n * FactorialRecursive( n - 1 );
}

static int FactorialIterative( int n )
{
	int sum = 1;
	if( n <= 1 )
		return sum;
	
	for( int i = n; i > 1; --i )
	{
		sum *= i;
	}
	
	return sum;
}

int main( int argc, char* argv[] ) 
{
	cout << "Recursive: " << FactorialRecursive( 4 ) << endl;
	cout << "Iterative: " << FactorialIterative( 4 ) << endl;
}