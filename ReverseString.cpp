#include <iostream>

using namespace std;

// Note:
// #include <algorithm>
// std::reverse( s.begin(), s.end() );

string reverse( const string& s )
{
	string reversed;
	
	for ( int i = s.length(); i != 0; --i )
	{
		reversed += s.substr( i - 1, 1 );
	}
	
	return reversed;
}

void reverseInPlace( string& s )
{
	for ( int i = 0, j = s.length() - 1; i > s.length(), j != 0, i < j; ++i, --j )
	{
//		cout << "i[" << i << "] j[" << j << "]" << endl;
//		cout << "s[i] = " << s[i] << endl;
//		cout << "s[j] = " << s[j] << endl;

		char tmp = s[i];
//		cout << "tmp = " << tmp << endl;
		s[i] = s[j];
		s[j] = tmp;

//		cout << "s[i] (after) = " << s[i] << endl;
//		cout << "s[j] (after) = " << s[j] << endl;
	}
}

void reverseOld( char* s )
{
	int length = strlen( s );
	for ( int i = 0, j = length - 1; i > length, j != 0, i < j; ++i, --j )
	{
		cout << s[i] << " | " << s[j] << endl;
		char tmp = s[i];
//		s[i] = s[j];
//		s[j] = tmp;
	}
	
//	char* first = c;
//	char* last = c + strlen( c );

//	while( first < last )
//	{
//		--last;
//		char temp = *first;
//		cout << *first << " | " << *last << " | " << temp << endl;
//		*first = *last;
//		cout << *first << " | " << *last << " | " << temp << endl;
//		*last = temp;
//		++first;
//	}
}

int main( int argc, char *argv[] ) 
{
	// Reverse string
	string s1 = "Bob";
	string s2 = "Greg";
	
	cout << reverse( s1 ) << endl;
	cout << reverse( s2 ) << endl;
	
	reverseInPlace( s1 );
	cout << s1 << endl;

	reverseInPlace( s2 );
	cout << s2 << endl;
	
	char* c = "Trevor";
	cout << c << endl;
	reverseOld( c );
	cout << c << endl;
}