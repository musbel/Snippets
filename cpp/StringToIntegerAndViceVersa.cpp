#include <iostream>
#include <sstream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	string s = "2";
	int i = stoi( s );
	cout << i << endl;
	
	int i2 = atoi( s.c_str() );
	cout << i2 << endl;

	// Convert int to string using stringstream
	stringstream c;
	int n = 4;
	c << n;
	cout << c.str() << endl;
}