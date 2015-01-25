#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node( int data = 0 ) : data( data ), next( NULL ) {}
};

Node* recursiveMergeLists( Node* headA, Node* headB )
{
    Node* result = NULL;
    
    if ( !headA ) return headB;
    if ( !headB ) return headA;
    
    if ( headA->data <= headB->data )
    {
        result = headA;
        result->next = recursiveMergeLists( headA->next, headB );
    }
    else
    {
        result = headB;
        result->next = recursiveMergeLists( headA, headB->next );
    }
    
    return result;
}

Node* mergeLists( Node* headA, Node* headB )
{
    Node result;
    Node* tail = &result;
    
    while ( true )
    {
        if ( headA == NULL )
        {
            tail->next = headB;
            break;
        }
        else if ( headB == NULL )
        {
            tail->next = headA;
            break;
        }
        
        if ( headA->data <= headB->data )
        {
            Node* temp = headA;
            headA = headA->next;
//            temp->next = tail->next;
			temp->next = NULL;
            tail->next = temp;
        }
        else
        {
            Node* temp = headB;
            headB = headB->next;
//            temp->next = tail->next;
			temp->next = NULL;
            tail->next = temp;
        }
        
        tail = tail->next;
    }
    
    return result.next;
}

void printList( Node* node )
{
    if ( node )
    {
        cout << node->data << " ";
        printList( node->next );
    }
    else
    {
        cout << endl;
    }
}

Node* reverseList( Node* head )
{
    Node* prev = NULL;
    Node* next = NULL;
    
    while ( head )
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

Node* RemoveDuplicates( Node *head )
{
    if( !head )
        return NULL;
    
    Node *curr = head, *prev = head;
    int currValue = curr->data;
    
    while( curr->next )
    {
        curr = curr->next;
        
        if( curr->data != currValue )
        {
            currValue = curr->data;
            prev->next = curr;
            prev = curr;
        }
    }

	// This occurs if the list ends with items containing
	// the same value so we never update the prev pointer,
	// e.g. 1->1->1->NULL
	if( prev != curr )
	{
		prev->next = NULL;
	}
    
    curr = NULL;
    prev = NULL;
    return head;
}

Node* insertNode( int value, Node* head = NULL )
{
	Node* newNode = new Node( value );
	if( !head )
	{
		return newNode;
	}
	
	Node* temp;
	for( temp = head; temp->next != NULL; temp = temp->next );
	temp->next = newNode;	// Append at the back
	
	return head;
}

Node* appendNode( int value, Node* node = NULL )
{
	Node* newNode = new Node( value );
	if( node )
	{
		node->next = newNode;
	}

	return newNode;
}

Node* sortList( Node* head )
{
	if( !head || !head->next )
		return head;

	return head;
}

int main( int argc, char *argv[] )
{
    Node* n1 = new Node( 1 );
    n1->next = new Node( 3 );
    n1->next->next = new Node( 5 );
    n1->next->next->next = new Node( 6 );
    printList( n1 );

    Node* n2 = new Node( 2 );
    n2->next = new Node( 4 );
    n2->next->next = new Node( 7 );
    printList( n2 );
    
    Node* m = recursiveMergeLists( n1, n2 );
	cout << "\nrecursiveMergeLists: " << endl;
    printList( m );
    
    Node* m2 = mergeLists( n1, n2 );
	cout << "\nmergeLists: " << endl;
    printList( m2 );
    
	cout << endl;

    //	Node* m3 = mergeLists( NULL, n2 );
    //	printList( m3 );
    
    Node* n = NULL;
    Node* revM = reverseList( m2 );
    printList( revM );
    
    Node* sl = insertNode( 1 );
    insertNode( 1, sl );
	insertNode( 3, sl );
	insertNode( 3, sl );
	insertNode( 5, sl );
	insertNode( 6, sl );
    cout << endl;
    printList( sl );
    sl = RemoveDuplicates( sl );
    printList( sl );
    
    Node* sl2 = insertNode( 1 );
	sl2 = insertNode( 1, sl2 );
	sl2 = insertNode( 1, sl2 );
	sl2 = insertNode( 1, sl2 );
	printList( sl2 );
    sl2 = RemoveDuplicates( sl2 );
    printList( sl2 );
    
	cout << "\nSort list:" << endl;
//	int a[] = { 38, 27, 43, 3, 9, 82, 10 };
	Node* l = insertNode( 38 );
	insertNode( 27, l );
	insertNode( 43, l );
	insertNode( 3, l );
	insertNode( 9, l );
	insertNode( 82, l );
	insertNode( 10, l );
    printList( l );

    // Delete all pointers
}