#include <iostream> 

template<int X, int N> 
class f
{
public:
	enum 
	{ 
		result = X * f<X, N-1>::result 
	};
};

template<int X> 
class f<X, 0> 
{
public:
	enum
	{ 
		result = 1 
	};
};

int main() 
{
	std::cout << f<3,2>::result << '\n'; 
}