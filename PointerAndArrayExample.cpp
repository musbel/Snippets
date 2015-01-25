#include <iostream>

using namespace std;

class Point
{
public:
	double x, y, z;
	Point() : x( 0 ), y( 0 ), z( 0 ) {}
	void toString() { cout << "[" << x << ", " << y << ", " << z << "]\n"; }
};

int main( int argc, char *argv[] ) 
{
	Point a[3];
	Point* p;
	p = a;
	
	p[0].x = 1;
	p[0].toString();
	p->toString();
	(p + 1)->toString();
	(p + 2)->toString();
	
	p = NULL;
	
	Point* ppp = new Point[3];
	cout << ppp[0].x << endl;
	
	Point* pt[3];
	pt[0] = new Point();
	pt[1] = new Point();
	pt[2] = new Point();
	
	pt[0]->x = 2;
	pt[0]->toString();
	
	delete[] pt[0];
	delete[] pt[1];
	delete[] pt[2];
	
	// Double pointer fun
	Point **b;
	b = new Point*;
	*b = new Point();
	(*b)->y = 2;
	(*b)->toString();
	b[0]->toString();
	
	delete *b;
	delete b;
	b = NULL;
	
}