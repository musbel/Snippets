#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	char* s = "Bob";
	cout << s << endl;
	cout << *s << endl;
	cout << *(s + 1) << endl;
	cout << *(s + 2) << endl;
}