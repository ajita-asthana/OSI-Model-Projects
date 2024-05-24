#include<iostream>
using namespace std;

int factorial(int n); 
//Returns factorial of n
//The argument n should be nonnegative

int main() 
{
	int number;
	cout << "Enter the number of which factorial is to be calculated: \n";
	cin >> number;

	int fact;
	fact = factorial(number);

	cout << "The factorial of number " << number << " is " << fact << "\n";
	return 0;
}

//Function Definition
int factorial(int n)
{
	int product = 1;
	while(n >0)
	{
		product = n * product;
		n--;
	}
	return product;
}
