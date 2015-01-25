#include <iostream>

using namespace std;

class Outer
{
public:
	static int m_Out;
	class Inner
	{
		public:
			static int m_In;
			void Display();
	};
};

int Outer::m_Out = 10;
int Outer::Inner::m_In = 25;

void Outer::Inner::Display() { cout << m_Out << endl; }

int main( int argc, char *argv[] ) 
{
	Outer objOut;
	Outer::Inner objIn;
	
//	objOut.m_In;
//	objIn.m_Out;
	objIn.Display();
//	objIn.Outer::m_Out;
//	objOut.Inner::m_In;
}