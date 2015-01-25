#include <iostream>

using namespace std;

class A
{
	int type;
	
public:
	A( int type ) : type( type ) {}
	
	friend ostream& operator<<( ostream& out, const A& a );

//	ostream& operator<<( ostream& out )
//	{
//		out << "Type: " << type;
//		return out;
//	}
	
	bool operator==( const A& rhs )
	{
		return type == rhs.type;
	}
	
//	bool operator==( const A& rhs, int l )
//	{
////		return type == rhs.type;
//		return true;
//	}

	bool operator==( int rhsType )
	{
		return type == rhsType;
	}
	
	int getType() const { return type; }
};

bool operator==( const int lhs, A& rhs )
{
	bool l = (rhs == 2);
	return l;
}

//bool operator==( const A& lhs, const A& rhs )
//{
//	return lhs.getType() == rhs.getType();
//}

ostream& operator<<( ostream& out, const A& a )
{
	out << "Type: " << a.type;
	return out;
}

int main( int argc, char *argv[] ) 
{
	A a1( 2 );
	cout << a1 << endl;
	
	A a2( 3 );
	cout << ( a1 == a2 ) << endl;
	cout << ( a1 == 2 ) << endl;
	cout << ( 2 == a1 ) << endl;
}