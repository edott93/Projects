#include <iostream>
using namespace std;

int main()
{
    long double sum;
	for(int i = 50; i > 0; --i)
	{
		for(int j = i- 1; i > 0; --j)
		{
			sum+=j;
		}
	}
	cout << sum << endl;
	return 0;
}