#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

bool isEqual( double a, double b )
{
	cout << "isEqual: a = " << a << ", b = " << b << endl;
	const double eps = 1e-5;
	return abs( a - b ) <= eps * abs( a ); 
}

template<class T>
bool isEqual( T a, T b )
{
	cout << "isEqual (template): a = " << a << ", b = " << b << endl;	const T eps = 1e-5;
	return abs( a - b ) <= eps * ( a );
}

int main( int argc, char *argv[] )
{
	const double eps = 1e-5;
	cout << "custom epsilon = " << eps << endl;
	cout << "float epsilon = " << numeric_limits<float>::epsilon() << endl;
	cout << "double epsilon = " << numeric_limits<double>::epsilon() << endl;
	
	double x = 1.0 / 10.0;
	double y = x * 10.0;
	
	if ( y == 1.0 )
	{
		cout << y << " == 1.0 | Clever compiler\n";
	}
	else
	{
		cout << "Typical double/float issue.\n";
	}
	
	if( isEqual( y, 1.0 ) )
	{
		cout << "isEqual says " << y << " and 1.0 is indeed equal.\n";
	}
	else
	{
		cout << "isEqual says not equal!\n";	
	}

	if( isEqual<double>( y, 1.0 ) )
	{
		cout << "isEqual template says " << y << " and 1.0 is indeed equal.\n";
	}
	else
	{
		cout << "isEqual template says not equal!\n";	
	}
}