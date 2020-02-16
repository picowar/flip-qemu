#include <stdio.h>

int main() {
	int a = 1;
	printf("%p\n", (void *) &a);
	int b = 2;
	int c = 3;
	a += b;
	a = a + c;

	printf("Value of A is %d\n", a);

	return 0;
}
