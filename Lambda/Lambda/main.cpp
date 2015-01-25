//
//  main.cpp
//  Lambda
//
//  Created by Orn Gunnarsson on 14/09/2014.
//
//

#include <iostream>
#include <vector>

using namespace std;

int main( int argc, const char * argv[] )
{
    // Shortest lambda functions ever (parameter list is optional)
    [] {};
    [] () {};
    
    // A simple lambda function in C++11
    {
        auto func = [] () { cout << "Hello\n"; };
        func();
    }
    
    // Other variations
    // - The [] represents local context of variables we are in control of when constructing
    //   the lambda.
    // - The () parameter list corresponds to the parameters that are passed to the function
    //   by whoever calls it (not in our control).
    {
        std::string text = "Flebbi";
        auto func = [&text] () { cout << "Bob says: " << text << endl; };
        func();
    }
    {
        auto func = [] ( int n ) { cout << "Number = " << n << endl; };
        func( 2 );
    }

    // A more involved example of a lambda function
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    
    // Transform all vector elements with a value less than 4 to 0, and 1
    // otherwise
    transform( numbers.begin(), numbers.end(), numbers.begin(),
              []( double n ) -> double
              {
                  if ( n < 4 )
                      return 0;
                  else
                      return 1;
              } );
    
    // Print the vector using for_each and a lambda function
    for_each( numbers.begin(), numbers.end(), []( int i ) { cout << i << endl; } );
    
    return 0;
}

