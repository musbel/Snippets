#include <iostream>

using namespace std;

//class ExDer1;

class ExBase
{
//	friend class ExDer1;
private:
	static int stat;
public:
	static int GetStat()
	{
		return stat;
	}
};

int ExBase::stat = 25;

class ExDer1 : public ExBase
{
public:
	// Access error unless we use the friend class above	
	friend int Der1Fn() { return ExBase::stat; }
};

class ExDer2 : public ExBase {};

class ExDer : public ExDer1, public ExDer2 {};

int main( int argc, char *argv[] ) 
{
	// Will print: No member 'Der1Fn' in 'ExDer'
//	ExDer d;
//	cout << d.Der1Fn() << endl;

	// Will print: 25	
//	ExDer d;
//	cout << d.GetStat() << endl;

	// Will print: 25	
//	cout << ExDer1::GetStat() << endl;

	// Will print: 25
//	cout << ExDer1::ExBase::GetStat() << endl;
}