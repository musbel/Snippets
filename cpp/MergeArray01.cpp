#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printArray( int n, int v[] )
{
	cout << "> Array values =";
	for ( int i = 0; i < n; ++i )
		cout << " " << v[i];
		
	cout << endl;
}

template <typename T>
void printVector( const vector<T>& v )
{
	cout << "> Vector values =";
	for ( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it )
		cout << " " << *it;
		
	cout << endl;
}

template <typename T>
void appendVector( vector<T>& r, const vector<T>& v )
{
	for ( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it )
	{
		r.push_back( *it );
	}
}

void mergeVectors( vector<int>& r, const vector<int>& a, const vector<int>& b )
{
	int n = a.size();
	int m = b.size();
	
	r.reserve( n + m );
	
	int i = 0;	// Keeps track of A
	int j = 0;	// Keeps track of B
	
	while ( i < n && j < m )
	{
		if ( a[i] <= b[j] )
		{
			r.push_back( a[i] );
			++i;
		}
		else
		{
			r.push_back( b[j] );
			++j;
		}
	}
	
	if ( i < n )
	{
		vector<int> rest( a.begin() + i, a.end() );
		appendVector( r, rest );
	}

	if ( j < m )
	{
		vector<int> rest( b.begin() + j, b.end() );
		appendVector( r, rest );
	}
}

//void mergeArrays( int n, int m, int r[], int a[], int b[] )
void mergeArrays( int n, int m, int* r, int* a, int* b )
{
	int i = 0;	// Keeps track of A
	int j = 0;	// Keeps track of B
	int k = 0;	// Keeps track of the merged array
	
	while ( i < n && j < m )
	{
		if ( a[i] <= b[j] )
		{
			r[k] = a[i];
			++i;
		}
		else
		{
			r[k] = b[j];
			++j;
		}
		
		++k;
	}
	
	if ( i < n )
	{
		for ( int c = i; c < n; ++c )
		{
			r[k] = a[c];
			++k;
		}
	}

	if ( j < m )
	{
		for ( int c = j; c < m; ++c )
		{
			r[k] = b[c];
			++k;
		}
	}
}

int main( int argc, char *argv[] ) 
{
	int a[5] = { 1, 3, 4, 7, 9 };
	int b[3] = { 2, 4, 10 };
	
	vector<int> av( a, a + sizeof( a ) / sizeof( a[0] ) );
	printVector<int>( av );
	
	vector<int> bv( begin(b), end(b) );
	printVector<int>( bv );
	
	vector<int> r;
	mergeVectors( r, av, bv );
	printVector<int>( r );
	
	printArray<int>( 5, a );
//	int ar[8];
	int* ar = new int[8];
	mergeArrays( 5, 3, ar, a, b );
	printArray<int>( 8, ar );
	delete [] ar;
	
	vector<int> r2;
	r2.reserve( av.size() + bv.size() );
	mergeVectors( r2, av, bv );
	printVector<int>( r2 );
	
	return 0;
}