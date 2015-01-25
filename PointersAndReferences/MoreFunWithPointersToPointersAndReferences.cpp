#include <iostream>

using namespace std;

// Global variable
int g_One = 1;

// Here, the pInt pointer is passed by value
// The pointer will therefore not change outside this function
void func1( int* pInt )
{
	pInt = &g_One;
}

// Here we pass a pointer to the pointer
// The dereferenced pointer is the pointer which points to the variable
// We assign that to the global variable's address
void func2( int** ppInt )
{
	*ppInt = &g_One;
}

void func3( int*& rpInt )
{
	rpInt = &g_One;	
}

int main( int argc, char *argv[] ) 
{
	int nvar = 2;
	int* pvar = &nvar;
	
	func1( pvar );
	cout << "func1: " << *pvar << endl;

	func2( &pvar );
	cout << "func2: " << *pvar << endl;

	func3( pvar );
	cout << "func3: " << *pvar << endl;
	
	return 0;
}