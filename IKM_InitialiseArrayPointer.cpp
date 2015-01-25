#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int** a = new int*[2];
	
	for ( int i = 0; i < 2; ++i )
	{
		a[i] = new int[2];
	}
	
	int *(*p)[2];
	p = new int*[2][2];
}