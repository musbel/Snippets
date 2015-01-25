#include <iostream>
#include <vector>

using namespace std;

vector<int> fibs;

int fib( int n )
{
	cout << 
	if ( fibs[n] != 0 )
		return fibs[n];
	
	if ( n < 2 )
	{
		fibs[n] = 1;
	}
	else
	{
		fibs[n] = fib( n - 1 ) + fib( n - 2 );
	}
}

int main( int argc, char *argv[] ) 
{
//	int num;
//	vector<int> numbers;
//	
//	cout << "How many numbers?" << endl;
//	cin >> num;
//	for ( int i = 0; i < num; ++i )
//	{
//		int n;
//		cin >> n;
//		numbers.push_back( n );
//	}
//	
//	for ( int i = 0; i < num; ++i )
//	{
//		cout << numbers[i] << endl;
//		if ( isFib( numbers[i] ) )
//			cout << "IsFibo" << endl;
//		else
//			cout << "IsNotFibo" << endl;
//	}
	
	for ( int i = 1; i < 12; ++i )
		cout << fib( i ) << endl;
//		cout << i << ": " << isFib( i ) << endl;

}