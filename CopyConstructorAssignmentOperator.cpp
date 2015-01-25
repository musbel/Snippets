#include <iostream> 
using namespace std; 
class Example 
{ 
    public:
        Example() 
        {
            cout << "Default constructor called.\n";
        }
        Example(const Example &rhs) : aa( rhs.aa )
        {
            cout << "Copy constructor called.\n";
        }
        Example& operator=(const Example &rhs) 
        {
            cout << "Assignment operator called.\n";
			aa = rhs.aa; 
            return *this;
        }
        ~Example()
        {
            cout << "Dtor invoked"<<endl;
        }
        int aa;
};

Example funct() 
{
    Example ob2;
    ob2.aa = 100;
    return ob2;
}

void print( Example e )
{
	cout << e.aa << endl;
}

int main() 
{
	// x and x2 invoke the default constructor (initialisation).
	cout << ">> Example x;" << endl;
    Example x;
	cout << ">> Example x2;" << endl;
	Example x2;
	x.aa = 2;
	
	// This should invoke the copy constructor as it is passing by value
	// so a copy is made. The destructor is also called when the function
	// ends to destroy the local copy. (function argument).
	// This relies on the copy constructor to copy the class member objects.
	cout << ">> print( x );" << endl;
	print( x );
	
	// This invokes the assignment operator as x2 already exists.
	// This relies on the assignment operator to copy the class member objects.
	cout << ">> x2 = x;" << endl;
	x2 = x;
	print( x2 );

	// This invokes the copy constructor as it is constructing a new x3 object
	// from x. This is sometimes called 'initialisation assignment'.
	cout << ">> Example x3( x );" << endl;
	Example x3( x );
	
	// This invokes the copy constructor as it is constructing a new x4 object
	// from x2. This is sometimes called 'initialisation assignment'.
	cout << ">> Example x4 = x2;" << endl;
	Example x4 = x2;

	// This creates a new object with the default constructor in funct, and then
	// should use the copy constructor to create a new object x5, but chances are
	// the compiler optimises this and uses a reference (function return value).
	// The following flag can be set to see the non-optimised behaviour:
	// -fno-elide-constructors
	cout << ">> Example x5 = funct();" << endl;
	Example x5 = funct();

	// This creates a new object with the default constructor in funct, and then
	// uses the assignment operator as the x has already been constructed.
	cout << ">> x = funct();" << endl;
	x = funct();

	cout << "Fin\n";

    return 0;
}