#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void printVector( const vector<T>& v, const string& label = "Vector values" )
{
	cout << "> " << label << " =";
	for ( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it )
		cout << " " << *it;
		
	cout << endl;
}

template <typename T>
void appendVector( vector<T>& r, const vector<T>& v )
{
	for ( typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it )
	{
		r.push_back( *it );
	}
}

vector<int> merge( vector<int> left, vector<int> right )
{
	printVector<int>( left, ">> merge (left)" );
	printVector<int>( right, ">> merge (right)" );
	vector<int> result;
	
	unsigned int leftIt = 0;
	unsigned int rightIt = 0;
	
	// Compare and merge until one vector runs out.
	// Then merge the remaining values of the vector
	// that still has elements left.
	
	while( leftIt < left.size() && rightIt < right.size() )
	{
		if( left[leftIt] < right[rightIt] )
		{
			result.push_back( left[leftIt++] );
		}
		else		
		{
			result.push_back( right[rightIt++] );
		}
	}
	
	while( leftIt < left.size() )
	{
		result.push_back( left[leftIt] );
		++leftIt;
	}

	while( rightIt < right.size() )
	{
		result.push_back( right[rightIt] );
		++rightIt;
	}
	
	printVector<int>( result, "## Merge Sort: Merged" );
	
	return result;
}

vector<int> mergeSort( const vector<int>& a )
{
	printVector<int>( a, "## Merge Sort: Values" );

	// Check base case, i.e. 1 (which is to say, sorted)
	if ( a.size() == 1 )
	{
		return a;
	}
	
	// Divide
	// Find middle
	int middle = a.size() / 2;
	cout << "middle = " << middle << endl;
	
	// Split the vector
	vector<int> left( a.begin(), a.begin() + middle );
	vector<int> right( a.begin() + middle, a.end() );
	printVector<int>( left, "Left" );
	printVector<int>( right, "Right" );
	
	left = mergeSort( left );
	right = mergeSort( right );
	
	// Conquer (merge)
	return merge( left, right );
//	return a;
}

int main( int argc, char *argv[] ) 
{
	int a[] = { 38, 27, 43, 3, 9, 82, 10 };

	vector<int> av( begin(a), end(a) );
	printVector<int>( av, "Unsorted values" );
	
	vector<int> sorted = mergeSort( av );
	printVector<int>( sorted, "Sorted values" );
}