//
//  main.cpp
//  Functor
//
//  Created by Orn Gunnarsson on 14/09/2014.
//
//

#include <iostream>

using namespace std;

struct AddNumber
{
    AddNumber( int number ) : number( number ) {}
    
    int operator() ( int someNumber )
    {
        return number + someNumber;
    }
    
private:
    int number;
};

int main(int argc, const char * argv[])
{
    // A Functor is a class that defines the operator(). Functors are nifty as
    // unlike functions they can have a state.
    
    AddNumber adder( 10 );
    
    int result = adder( 4 );
    cout << "Functor returned: " << result << endl;
    
    return 0;
}

