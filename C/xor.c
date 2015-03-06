#include <stdio.h>
int main()
{
	int x, y;
	x = 5;
	y = 10;
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("X is %d and y is %d", x, y);
	return 0;

}
