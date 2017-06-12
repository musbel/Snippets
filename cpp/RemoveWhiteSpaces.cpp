#include <iostream>

using namespace std;

int main( int argc, char *argv[] ) 
{
	// Remove spaces
	string s = "A man's word is as good as his shoes.";
	s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
	cout << s << endl;
}