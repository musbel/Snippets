#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main( int argc, char *argv[] ) 
{
	int n = 3;
	int s = 1;
	int p = 2;
	int q = -1;
	
	long a[n];
	a[0] = s;
	for ( int i = 1; i < n; ++i )
	{
		a[i] = a[i - 1] * p + q;
	}
	
	for ( int i = 0; i < n; ++i )
		cout << a[i] << endl;
	
}