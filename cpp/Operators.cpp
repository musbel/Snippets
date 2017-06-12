#include <iostream>

using namespace std;

struct Number
{
	int n;
	
	Number( int n ) : n( n ) {}
	
	int operator-( int i )
	{
		return n - i;
	}
	
	// Pre-increment
	int operator++()
	{
		n++;
		return n;
	}
	
	// Post-increment
	// Expressions using the result will use the old value and then increment
	int operator++( int )
	{
		int tmp( n );		// copy
		operator++();		// pre-increment
		return tmp;			// return old
	}
	
	// Addition assignment operator
	int operator+=( int i )
	{
		n += i;
		return n;
	}

	Number& operator+=( const Number& rhs )
	{
		n += rhs.n;
		return *this;
	}
	
	int operator()()
	{
		return n;
	}
};

// Non-member unary operator
Number operator--( Number& n )
{
	n.n--;
	return n;
}

// Non-member binary operator
Number operator+( const Number& n1, const Number& n2 )
{
	return n1.n + n2.n;
}

int main( int argc, char *argv[] ) 
{
	Number n( 10 );
	cout << n - 2 << endl;
	cout << ++n << endl;
	cout << n++ << endl;	// Prints value before the increment, so actually one more
	cout << n() << endl;	// Print the true value after the post-increment
	
	cout << (n += 2) << endl;
	
	n += Number( 100 );
	cout << n.n << endl;
	
	Number n1( 2 );
	Number n2( 3 );
	cout << (n1 + n2).n << endl;
	
	Number x( 20 );
	--x;
	cout << x() << endl;
}