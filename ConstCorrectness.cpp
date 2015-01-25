#include <iostream>

using namespace std;

template<typename T>
class MyArray
{
public:
	MyArray() { cout << "MyArray: Default constructor\n"; }
//	MyArray( MyArray& copy ) { cout << "MyArray: Copy constructor\n"; }
	MyArray( const MyArray& copy ) { cout << "MyArray: Copy constructor\n"; }
	MyArray& operator=( MyArray& copy ) { cout << "MyArray: Assignment operator\n"; }
};

class MyData
{
public:
//	MyData( MyArray<int>& x, MyArray<int>& y ) : x( x ), y( y ) 
	MyData( const MyArray<int>& x, const MyArray<int>& y ) : x( x ), y( y ) 
	{
		cout << "MyData: Constructor\n";	
	}
	
	const MyArray<int>& x;
	const MyArray<int> &y;
};

const MyArray<int> read_data( int*, char** ) 
{
	MyArray<int> a;
	return a;
}

void make_changes( MyData* edit ) {}

int main( int argc, char *argv[] ) 
{
	cout << "const MyArray<int> read_x = read_data( &argc, argv );" << endl;
	const MyArray<int> read_x = read_data( &argc, argv );
	cout << "const MyArray<int> read_y = read_data( &argc, argv );" << endl;
	const MyArray<int> read_y = read_data( &argc, argv );
	
	MyData user_data( read_x, read_y );
	MyData edit_buffer( user_data );
	make_changes( &edit_buffer );
}