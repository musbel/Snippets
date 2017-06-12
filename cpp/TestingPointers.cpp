#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int* foo;
	foo = new (nothrow) int[4];
	
	if ( foo != NULL ) //0x0 ) //nullptr )
	{
		cout << "Foo created\n";
	}
	
	int** M = new int*[2];
	for ( int i = 0; i < 2; ++i )
	{
		M[i] = new int[2];
		M[i][0] = i;
		M[i][1] = i * 2;
	}
	
	for ( int i = 0; i < 2; ++i )
	{
		for ( int j = 0; j < 2; ++j )
		{
			cout << "[" << i << "][" << j << "] = " << M[j][i] << endl;
		}
	}
	
	delete[] foo;
	delete[] M;
}