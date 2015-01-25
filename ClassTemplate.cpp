#include <iostream>

using namespace std;

template<typename T>
class Storage
{
public:
	Storage( const T& value );
	const T& getFromStorage();
	
private:
	T value;
};

template<typename T>
Storage<T>::Storage( const T& value ) : value( value )
{}

template<typename T>
const T& Storage<T>::getFromStorage()
{
	return value;
}

int main( int argc, char *argv[] ) 
{
	Storage<int> storage( 10 );
	cout << storage.getFromStorage() << endl;
}