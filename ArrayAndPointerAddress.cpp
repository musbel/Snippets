#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int a[2] = { 5, 10 };
	
	cout << a << endl;
	cout << &a << endl;
	cout << &a[0] << endl;
	cout << a[0] << endl;
}