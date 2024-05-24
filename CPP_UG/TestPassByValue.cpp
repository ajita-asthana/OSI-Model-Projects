#include<iostream>
using namespace std;

int square(int);
int main() {
	int number = 8;
	cout << "In main(): " << &number << "\n";
	cout << "The number is " << number << "\n";
	cout << "The square function is called : "<< square(number) << "\n";
	cout << "The original number is: " << number << "\n";
	return 0;
}

int square(int n ) { //non const 
	cout << "In square(): " << &n << endl; // address of the variable
	n *= n;
	return n;
}
