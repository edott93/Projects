#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	float lower_limit, higher_limit, step_size;
	
	do{
		cout << "Please give in a lower limit, limit >= 0:\n";
		cin >> lower_limit;
	}while(lower_limit < 0);
	do{
		cout << "Please give a higher_limit, 10 < limit <=50000" << endl;
		cin >> higher_limit;
	}while(higher_limit <= 10 || higher_limit > 50000);
	do{
		cout << "Please give a step size, 0 < step <= 10" << endl;
		cin >> step_size;
	}while(step_size <= 0 || step_size > 10);
	
	cout << "Celsius  \t Fahrenheit" << endl;
	cout << "-------  \t ----------" << endl;
	while(lower_limit < higher_limit){

		printf("%.7f \t %.7f\n", lower_limit, lower_limit*(9.0/5.0)+32.0);
		if(lower_limit + step_size > higher_limit)
			break;
		lower_limit+=step_size;
	}
	return 0;
}
