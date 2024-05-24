#include <iostream>
using namespace std;

int main() {
	int number = 88;
	int *p_num = &number;
	cout << "The address of pointer is "<< p_num << "\n";
	cout << "The value being pointed to is  " << *p_num << "\n";
	*p_num = 99;
	cout << *p_num << endl;
	cout << number << endl;
	return 0;
}	
