#include <iostream>
#include <limits>

using namespace std;

double multiply( double n )
{
	double mult = n * 2;
	return mult;
}

std::string greet( const std::string& name )
{
	std::string greeting = string( "Hello " ) + name;
	return greeting;
}

const char* evil( std::string s )
{
	const char* t = s.c_str();
	return t;
}

int getBit( int n, int index )
{
	return ( ( n & ( 1 << index ) ) > 0 );
}

int setBit( int n, int index, bool b )
{
	if( b )
	{
		// Set bit
		return n | ( 1 << index );
	}
	else
	{
		// Clear bit
		int mask = ~( 1 << index );
		return n & mask;	
	}
}

//void printBin( int n )
//{
//	for( int i = 31; i >= 0; --i )
//	{
//		cout << getBit( n, i );
//	}
//	
//	cout << endl;
//}

template <typename T>
void printBin( T n )
{
	int numDigits = numeric_limits<T>::digits;
	
	for( int i = numDigits; i >= 0; --i )
	{
		cout << getBit( n, i );
	}
	
	cout << endl;
}

void printLimits()
{
	cout << "-- LIMITS --\n";
	cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
	cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
	cout << "int is signed: " << numeric_limits<int>::is_signed << endl;
	cout << "Non-sign bits in int: " << numeric_limits<int>::digits << endl;
	cout << "int has inifinity: " << numeric_limits<int>::has_infinity << endl;
	
	cout << endl;
	
	cout << "Non-sign bits in float: " << numeric_limits<float>::digits << endl;
	cout << "Non-sign bits in double: " << numeric_limits<double>::digits << endl;
	cout << "Minimum value for unsigned int: " << numeric_limits<unsigned int>::min() << endl;
	cout << "Maximum value for unsigned int: " << numeric_limits<unsigned int>::max() << endl;
}

int main( int argc, char* argv[] ) 
{
	double x = multiply( 2 );
	cout << "x = " << x << endl;
	
	cout << greet( "Smith" ) << endl;
	
	// Evil
	//const char* s = evil( "Hello" );
	//cout << s << endl;
	
	cout << endl;
	cout << "int = " << sizeof( int ) << endl;
	cout << "short = " << sizeof( short ) << endl;
	cout << "long = " << sizeof( long ) << endl;
	cout << "double = " << sizeof( double ) << endl;
	cout << "float = " << sizeof( float ) << endl;
	cout << "string = " << sizeof( string ) << endl;
	cout << "char = " << sizeof( char ) << endl;
	
	cout << endl;
	
	int a = 7;
	printBin( a );
	
	int b1 = setBit( a, 4, true );
	printBin( b1 );
	
	int b2 = a;
	b2 = setBit( b2, 2, false );
	//for( int i = 31; i >= 0; --i )
	//	b2 = setBit( b2, i, false );
	printBin( b2 );
	
	cout << endl;
	printLimits();
	
	int x1 = numeric_limits<int>::max();
	int x2 = numeric_limits<int>::max();
	int x3 = x1 + x2;
	cout << "x1 = " << x1 << endl;
	cout << "x3 = " << x3 << endl;
	printBin( x3 );
}