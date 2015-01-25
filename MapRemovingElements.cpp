#include <iostream>
#include <map>

using namespace std;

void printMap( const map<int, string>& m )
{
	for_each( m.begin(), m.end(), [] ( pair<int, string> p ) 
		{
			cout << "[" << p.first << "] " << p.second << endl; 
		} 
	);
}

int main( int argc, char *argv[] ) 
{
	map<int, string> people;
	people.insert( pair<int, string>( 1, "Bob" ) );
	people[2] = "Ted";
	people[3] = "Tom";
	people[4] = "Bob";
	people[5] = "Phil";
	
	printMap( people );
	
	map<int, string>::iterator it = people.begin();
	for( ; it != people.end() ; )
	{
		if( it->second == "Bob" )
		{
			it = people.erase( it );
//			people.erase( it++ );
		}
		else
			++it;
	}
	
	cout << endl;
	printMap( people );
}