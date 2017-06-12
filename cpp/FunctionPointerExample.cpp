#include <iostream>

using namespace std;

void printInt( int x )
{
	cout << "x = " << x << endl;
}

int main( int argc, char *argv[] ) 
{
	void (*foo)(int);
	foo = &printInt;
	
	foo( 2 );
	(*foo)( 4 );
	
	return 0;
}