#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< vector<int> > Sequences;

void printSeq( const vector<int>& seq )
{
	for_each( seq.begin(), seq.end(), [] ( int v ) { cout << v << " "; } );
	cout << endl;
}

// Longest Increasing Subsequence
// LIS[0] = seq[0]
// LIS[i] = MAX( LIS[0..j] && seq[i] > seq[j] ) + seq[i]
// 2 4 3 8
// LIS[0] = 2
// LIS[1] = ...
int findLIS( const vector<int>& seq )
{
	Sequences sequences( seq.size() );
	
	if ( seq.size() == 0 )
	{
		return 0;
	}
	
	sequences[0].push_back( seq[0] );
	
	for ( int i = 1; i < seq.size(); ++i )
	{
		for ( int j = 0; j < i; ++j )
		{
			if ( sequences[j].size() > sequences[i].size() && seq[i] > seq[j] )
			{
				sequences[i] = sequences[j];
			}
		}
		
		sequences[i].push_back( seq[i] );
	}

	int lis = 0;
	for ( Sequences::const_iterator it = sequences.begin(); it != sequences.end(); ++it )
	{
		if ( it->size() > lis ) lis = it->size();
		printSeq( *it );
	}
	
	return lis;
}

//int calcLIS_Rec( const vector<int> seq, int i = 0 )
//{
//	
//}

int main( int argc, char *argv[] ) 
{
	unsigned int n;
	cin >> n;
	
	vector<int> seq;
	seq.reserve( n );
	
	for ( unsigned int i = 0; i < n; ++i )
	{
		int num;
		cin >> num;
		seq.push_back( num );
	}

	printSeq( seq );
	
	int lis = findLIS( seq );
	cout << "LIS = " << lis << endl;
	
	
}