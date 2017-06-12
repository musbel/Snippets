#include <iostream>

using namespace std;

// Syntax of Reference to Pointer

// Note: RTTI (typeid) does not support reference types

void funcRP( int*& rpInt )
{
	cout << *rpInt << endl;	
}

void funcPP( int** ppInt )
{
	**ppInt = 3;
	cout << **ppInt << " | " << ppInt << endl;
}

int main( int argc, char *argv[] ) 
{
	int nvar = 2;
	
	// Reference to pointer
	int* pvar = &nvar;
	funcRP( pvar );
	
	// Pointer to pointer
	int* ppvar = &nvar;
	funcPP( &ppvar );
	
	return 0;
}