#include <stdio.h>
#include <iostream>

void update(int *a, int *b) 
{
	int ta = *a;
	*a += *b;
	*b = abs(ta - *b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    a = 4;
	b = 5;
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

