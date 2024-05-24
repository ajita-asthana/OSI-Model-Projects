#include <iostream>
using namespace std;

int main() {
	int number1 = 88, number2 = 22;
	
	//Create a pointer pointing to number1
	int *p_num1 = &number1;
	cout << *p_num1 << endl;
	*p_num1 = 99;
	cout << "The value at pointer is " <<  *p_num1 <<"\n";
	cout << "The address of number variable is " << &number1 << "\n";
	cout << "The address pointed to by the pointer "<< p_num1 << "\n";
	cout << "The address of the pointer variable is " << &p_num1 << "\n";

	//Create a reference (alias) to number1
	int &refNumber1 = number1; // Implicit referencing
	refNumber1  = 11; //Implicit dereferencing
	cout << "The alias is " << refNumber1 << "\n";
	cout << "The address of number1 variable is " << &number1 << "\n";
	cout << "The address of alias is " << &refNumber1 << "\n";

	refNumber1 = number2;

	number2++;
	cout << "The refNumber1 is " << refNumber1 << "\n";
	cout << "The variable number1 is " << number1 << "\n";
	cout << "The variable number2 is " << number2 << "\n";
}
