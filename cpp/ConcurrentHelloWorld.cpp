#include <iostream>
#include <thread>

using namespace std;

void hello()
{
	cout << "Hello Concurrent World\n";
}

int main( int argc, char *argv[] ) 
{
	thread t( hello );
	t.join();
	
	return 0;
}