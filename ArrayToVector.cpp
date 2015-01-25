#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int first[] = { 5, 10, 15, 20, 25 };
	int second[] = { 50, 40, 30, 20, 10 };
	vector<int> v( begin( first ), end( first ) );

	for ( vector<int>::iterator it = v.begin(); it != v.end(); ++it )
		cout << " " << *it;
		
	cout << endl;
}