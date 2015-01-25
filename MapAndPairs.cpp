#include <iostream>
#include <map>

using namespace std;

struct Compare
{
	string str;
	Compare( const string& str ) : str( str ) {}
};

bool operator==( const pair<int, string>& p, const Compare& c )
{
	return c.str == p.second;
}

bool operator==( const Compare& c, const pair<int, string>& p )
{
	return c.str == p.second;
}

void printFunction( pair<int, string> p )
{
	cout << "[" << p.first << "] = " << p.second << endl;
}

struct PrintClass
{
	void operator() ( pair<int, string> p )
	{
		cout << "[" << p.first << "] = " << p.second << endl;
	}
} printClass;

int main( int argc, char *argv[] ) 
{
	// Note: A key cannot be deleted
	
	map<int, string> m;
	pair<int, string> p1 = make_pair( 1, "Bob" );
	m.insert( p1 );
	m.insert( pair<int, string>( 2, "Ted" ) );
	m.insert( pair<int, string>( 3, "Bob" ) );
	
//	for ( map<int, string>::iterator it = m.begin(); it != m.end(); ++it )
//		cout << "[" << (*it).first << "] = " << (*it).second << endl;
	for_each( m.begin(), m.end(), printFunction );
	for_each( m.begin(), m.end(), printClass );
	
	cout << m.count( 1 ) << endl;
	
	int numBobs = count( m.begin(), m.end(), Compare( "Bob" ) );
	cout << "Found " << numBobs << " with the name Bob\n";
	
	map<int, string>::iterator findTed = find( m.begin(), m.end(), Compare( "Ted" ) );
	if ( findTed != m.end() )
	{
		int tedsNum = findTed->first;
		cout << "Found Ted! -> " << tedsNum << "\n";
	}
	findTed->second = "Teddie";
	cout << findTed->second << endl;
	cout << m.size() << endl;
}