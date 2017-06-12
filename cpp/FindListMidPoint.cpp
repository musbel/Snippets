#include <iostream>

using namespace std;

class List
{
public:
	int value;
	List* next;
	
	List( int value ) : value( value ), next( NULL ) {}
};

void printList( List* list )
{
	if ( !list )
		return;
		
	std::cout << "[" << list->value << "]" << std::endl;
	printList( list->next );
}

// Could use a visitor here
struct MidListVisitor
{
	int length;
	int reverseIndex;
	
	MidListVisitor() : length( 0 ), reverseIndex( 0 ) {}
	
	void visit( List* list )
	{
		if ( list )
		{
			length++;
			std::cout << "List [" << list->value << "] length[" << length << "]\n";
			
			visit( list->next );
			
			reverseIndex++;
			std::cout << "List [" << list->value << "] length[" << length << "] reverseIndex[" << reverseIndex << "]\n";
		}
		
		if ( reverseIndex * 2 == length || reverseIndex * 2 == length + 1 )
		{
			std::cout << "Mid point: " << list->value << std::endl;
		}
	}
};

int main( int argc, char *argv[] ) 
{
	// Should create a List container with a current index and add function
	List* list1 = new List( 1 );
	list1->next = new List( 2 );
	list1->next->next = new List( 3 );
	list1->next->next->next = new List( 4 );
	list1->next->next->next->next = new List( 5 );
		
	printList( list1 );
	
	MidListVisitor visitor = MidListVisitor();
	visitor.visit( list1 );
}