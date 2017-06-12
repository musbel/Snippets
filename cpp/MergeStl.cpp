#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int first[] = { 5, 10, 15, 20, 25 };
	int second[] = { 50, 40, 30, 20, 10 };
	vector<int> v( 10 );
	
	sort( first, first + 5 );
	sort( second, second + 5 );

	merge( first, first + 5, second, second + 5, v.begin() );
	
	cout << "Resulting vector contains: ";
	for ( vector<int>::iterator it = v.begin(); it != v.end(); ++it )
		cout << " " << *it;
		
	cout << endl;
}