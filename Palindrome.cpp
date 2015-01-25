#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>
#include <locale>

using namespace std;

bool isPalindrome( const string& str, bool removeWhiteSpaces = false, bool caseSensitive = false )
{
	string s = str;

	// (Optional) Remove spaces. Required for sentences.
	if ( removeWhiteSpaces )
	{
		s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
	}

	// (Optional) Make everything lower case
	if ( caseSensitive )
	{
		for ( int i = 0; i < s.length(); ++i )
		{
			s[i] = tolower( s[i] );
		}
	}

	// Create a stack for the letters.
	// The idea is to add the first half of the string to the stack
	// and then pop and compare the second half of the string.
	// We return false if the comparison fails.
	// We have a palindrom if the stack is empty after comparing and popping.
	stack<string> letterStack;
	
	int isOdd = s.length() % 2;
	int middle = floor( s.length() / 2 );

	for ( int i = 0; i < middle; ++i )
	{
		const string elm = s.substr( i, 1 );
//		cout << "Push: " << elm << endl;
		letterStack.push( elm );
	}

	for ( int i = middle + isOdd; i < s.length(); ++i )
	{
		string letter = letterStack.top();
		letterStack.pop();
//		cout << "Pop: " << letter << " | " << s.substr( i, 1 ) << endl;
		if ( letter != s.substr( i, 1 ) ) return false;
	}
	
	if ( letterStack.size() > 0 ) return false;
	
	return true;
}

int main( int argc, char *argv[] ) 
{
	string s1 = "ABBA";
	cout << ">> " << s1 << ": " << isPalindrome( s1 ) << endl;

	string s2 = "Eel urbane hen a brulee";
	cout << ">> " << s2 << ": " << isPalindrome( s2, true, true ) << endl;

	string s3 = "Godfrey";
	cout << ">> " << s3 << ": " << isPalindrome( s3, false, true ) << endl;
}