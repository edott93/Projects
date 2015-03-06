#include <iostream>
using namespace std;
void open_doors(int list_of_doors[],int size);
int main()
{
	int list_of_doors[100];
	for(int i = 0; i < 100; i++)
	{
		list_of_doors[i] = 0;
	}
	open_doors(list_of_doors, 100);
	return 0;
}
void open_doors(int list_of_doors[], int size)
{
	int scale = 1;
	int count = 0;
	while(count < 100)
	{
		for(int i = 0; i < 100; i+=scale)
		{
			list_of_doors[i] = !list_of_doors[i];
		}
		scale++;
		count++;
	}
	for(int i = 0; i < 100; i++)
	{
		if(list_of_doors[i] == 0)
			cout << "Closed" << endl;
		else
			cout << "Open" << endl;
	}
}
