#include <stdio.h>

void convertToBinary(int num)
{
	if(num == 0)
		return;
	convertToBinary(num/2);
	printf("%d", num%2);

}
int main()
{
	int test;
	printf("Enter a number to convert\n");
	scanf("%d",&test);
	convertToBinary(test);
	printf("\n");
	return 0; 

}
