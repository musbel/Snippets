#include <iostream>

using namespace std;

union Taco
{
	int i;
	float f;
};

void printTaco( const Taco& taco )
{
	cout << "taco.i = " << taco.i << endl;
	cout << "taco.f = " << taco.f << endl;
	cout << endl;
}

int main( int argc, char *argv[] ) 
{
	Taco taco = { 2 };
	printTaco( taco );
	
	taco.f = 4.0f;
	printTaco( taco );
}