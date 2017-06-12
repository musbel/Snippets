#include <iostream>
#include <stdlib.h>

using namespace std;

int main( int argc, char *argv[] ) 
{
	char *p = (char*) malloc( 15 * sizeof( int ) );
	strcpy( p, "Hello" );
	
	cout << p << endl;
	cout << *p << endl;
	cout << *(p + 1) << endl;
	cout << *(p + 2) << endl;
	cout << *(p + 3) << endl;
	cout << *(p + 4) << endl;
}