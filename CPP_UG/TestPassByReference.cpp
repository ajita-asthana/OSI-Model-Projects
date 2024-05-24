#include <iostream>
using namespace std;

void square(int &);
int main() {
	int number = 8;
	cout << "In main(): " << &number << "\n";
	cout << number << "\n";
	square(number);
	cout << "The number after squaring is: " << number << "\n";
}


void square(int &r_value) {
	cout << "In square function " << &r_value << "\n";
	r_value *= r_value;
}
