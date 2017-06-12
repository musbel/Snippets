#include <iostream>

using namespace std;

int gcd( int a, int b )
{
	cout << "gcd: a[" << a << "] b[" << b << "]" << endl;
	if ( b == 0 )
		return a;
	else
		return gcd( a, a % b );
}

int main( int argc, char *argv[] ) 
{
	cout << gcd( 3, 12 ) << endl;
}
