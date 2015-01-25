#include <iostream>

using namespace std;

void allocate( int** pp )
{
	*pp = (int*) malloc( sizeof( int ) );
}

void change( int* p )
{
	*p = 20;
}

void change2( int** p, int** q )
{
	*p = *q;
}

int main()
{
	int* p = NULL;
	int* q = new int( 5 );
	allocate( &p );
	*p = 42;
	cout << p << " : " << *p << endl;
	cout << q << " : " << *q << endl;
	
	cout << "\n-- CHANGE --" << endl;
	change( p );
	cout << p << " : " << *p << endl;

	cout << "\n-- CHANGE --" << endl;
	change2( &p, &q );
	cout << p << " : " << *p << endl;
	free( p );
}