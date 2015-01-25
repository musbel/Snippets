#include <iostream>
#include <bitset>
#include <limits>

using namespace std;

template <typename T>
void printBit( const T& v )
{
	bitset<numeric_limits<T>::digits> bit( v );
	cout << v << " = " << bit << endl;
}

int main( int argc, char* argv[] ) 
{
	printBit<int>( 2 );
	printBit<float>( 5.2f );
	printBit<double>( 4.0 );
}