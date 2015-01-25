#include <iostream>
#include <exception>

using namespace std;

int main( int argc, char *argv[] ) 
{
	try 
	{
		cout << "sum";
		throw 3;	
	} 
	catch ( exception e )
	{
		cout << "exception";
	}
	catch ( int a )
	{
		cout << a;
	}
	catch ( ... ) 
	{
		cout << "dot";
	}
	
	return 0;
}