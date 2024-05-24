#include <iostream>
using namespace std;;

void square(int *);

int main()
{
	int number = 8;
	cout << "In main(): " << &number << "\n";
	cout << "The number is :" << number << "\n";
	square(&number); //explicit referencing to pass an address
	cout << "The squared number is : " << number << "\n";
}

void square(int *pNumber)
{
	cout << "In square(): " << pNumber << "\n";
	*pNumber *= *pNumber; //Explicit de-refrencing to get the values pointed to
}
