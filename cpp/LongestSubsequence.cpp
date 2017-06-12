#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > M;

void readSequence( vector<int>& seq, const int seqLength )
{
	for ( int i = 0; i < seqLength; ++i )
	{
		int num;
		cin >> num;
		seq.push_back( num );
	}
}

void printSequence( const vector<int>& seq )
{
	cout << "-- SEQUENCE --" << endl;
	vector<int>::const_iterator it = seq.begin();
	for( ; it != seq.end(); ++it )
	{
		cout << *it << " ";
	}
	
	cout << endl;
}

void printReverseSequence( const vector<int>& seq )
{
	cout << "-- REVERSE SEQUENCE --" << endl;
	vector<int>::const_reverse_iterator it = seq.rbegin();
	for( ; it != seq.rend(); ++it )
	{
		cout << *it << " ";
	}
	
	cout << endl;
}

void printMatrix( const M& m )
{
	cout << "-- MATRIX --" << endl;
	for ( M::const_iterator it = m.begin(); it != m.end(); ++it )
	{
		vector<int> elm = *it;
		for ( vector<int>::iterator elmIt = elm.begin(); elmIt != elm.end(); ++elmIt )
		{
			cout << *elmIt << " ";
		}
		
		cout << endl;
	}
}

void findLCS( 
	std::vector<int>& longestSeq,
	const M& lcs, 
	const std::vector<int>& seq1, 
	const std::vector<int>& seq2, 
	int i, 
	int j 
	)
{
	if ( i == 0 || j == 0 )
	{
		// We've reached the end so return
		return;
	}
	else if ( seq1[i - 1] == seq2[j - 1] )
	{
		// Found an element in LCS
		longestSeq.push_back( seq1[i - 1] );
		return findLCS( longestSeq, lcs, seq1, seq2, i - 1, j - 1 );
	}
	else
	{
		// Keep looking
		if ( lcs[i][j - 1] > lcs[i - 1][j] )
		{
			return findLCS( longestSeq, lcs, seq1, seq2, i, j - 1 );
		}
		else
		{
			return findLCS( longestSeq, lcs, seq1, seq2, i - 1, j );
		}
	}
}

void longestCommonSubsequence( 
	const vector<int>& seq1,
	const vector<int>& seq2,
	vector<int>& longestSeq
	)
{
	M lcs;	// M[r][c]
	int n = seq1.size();
	int m = seq2.size();
	lcs.resize( n + 1 );

	for ( int i = 0; i <= n; ++i )
	{
		lcs[i].resize( m + 1 );
		lcs[i][0] = 0;
	}

	for ( int j = 0; j <= m; ++j )
	{
		lcs[0][j] = 0;
	}

	for ( int i = 1; i <= n; ++i )
	{
		for ( int j = 1; j <= m; ++j )
		{
			if ( seq1[i - 1] == seq2[j - 1] )
			{
				lcs[i][j] = 1 + lcs[i - 1][j - 1];
			}
			else
			{
				lcs[i][j] = max( lcs[i - 1][j], lcs[i][j - 1] );
			}
		}
	}
	
	printMatrix( lcs );

	findLCS( longestSeq, lcs, seq1, seq2, n, m );
	reverse( longestSeq.begin(), longestSeq.end() );
}

int main( int argc, char *argv[] ) 
{
	int n, m;
	vector<int> seq1;
	vector<int> seq2;
	cin >> n;
	cin >> m;

	readSequence( seq1, n );
	readSequence( seq2, m );
	
	printSequence( seq1 );
	printSequence( seq2 );
	
	vector<int> longestSeq;
	longestCommonSubsequence( seq1, seq2, longestSeq );
	printSequence( longestSeq );
}