#include <iostream>

using namespace std;

void test1(int* n)
{
	*n = *n + 10;
}

void test2(int* n, int* m)
{
	*n = *m;
}

void test3(int** n, int **m)
{
	*n = *m;
}

int main(int argc, char *argv[]) 
{
	int a = 2;
	int b = 3;
	
	int* pa = &a;
	int* pb = &b;
	
	cout << "a = " << a << " (" << pa << ")" << endl;
	cout << "b = " << b << " (" << pb << ")" << endl;

//	test1(pa);
//	test2(pa, pb);
	test3(&pa, &pb);
	cout << "a = " << *pa << " (" << pa << ")" << endl;
}