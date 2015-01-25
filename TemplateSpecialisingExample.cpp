#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// Function specialisation
template <typename T>
void printVector( vector<T>& list )
{
	typename vector<T>::iterator it = list.begin();
	typename vector<T>::const_iterator itEnd = list.end();
	
	for ( ; it != itEnd; ++it ) 
	{
		cout << *it << endl;	
	}
}

template <>
void printVector<int>( vector<int>& list )
{
	typename vector<int>::iterator it = list.begin();
	typename vector<int>::const_iterator itEnd = list.end();

	for ( ; it != itEnd; ++it ) 
	{
		cout << *it * 2 << endl;	
	}
}

// Note: This partial specialisation is not allowed.
//       Functions have to be fully specialised -> <>
//template <typename T>
//void printVector<string>( vector<T>& list )
//{
//	typename vector<T>::iterator it = list.begin();
//	typename vector<T>::const_iterator itEnd = list.end();
//
//	cout << "Printing a string...\n"
//
//	for ( ; it != itEnd; ++it ) 
//	{
//		cout << *it << endl;	
//	}
//}

int main( int argc, char *argv[] ) 
{
	string letters[] = { "a", "b" };
	vector<string> stringList( begin( letters ), end( letters ) );
	printVector<string>( stringList );
	
	int numbers[] = { 0, 1, 2, 4, 12 };
	vector<int> numberList( begin( numbers ), end( numbers ) );
	
	printVector<int>( numberList );
	// Note: Also allowed
	// printVector<>( numberList );
	// printVector( numberList );	// Allowed for function templates only
}