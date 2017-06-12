#include <iostream>

using namespace std;

template<typename T>
class A
{
public:
	static int x;	
};

template<typename T> 
int A<T>::x = 10;

int main( int argc, char *argv[] ) 
{
	A<int>::x = 5;
	cout << A<int>::x << endl;
	cout << A<char>::x << endl;
	cout << A<float>::x << endl;
	cout << A<long>::x << endl;
//	A<int> a;
//	A<double> b;
//	
//	a.x = 5;
//	
//	cout << "a.x = " << a.x << endl;
//	cout << "b.x = " << b.x << endl;
}