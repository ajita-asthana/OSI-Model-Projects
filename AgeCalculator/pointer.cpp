#include <iostream>
using namespace std;
typedef int *IntPtrType;
int main()
{
	IntPtrType ptr_a, ptr_b;
	int num_c = 4, num_d = 7;

	ptr_a = &num_c;
	//cout << "ptr_a is " << ptr_a << "\n";
	//cout << "ptr_a pointer is " << *ptr_a << "\n";	
	ptr_b = ptr_a;
	cout << *ptr_a << " " << *ptr_b << "\n";
	ptr_b = &num_d;

	cout << *ptr_a << " " << *ptr_b << "\n";
	*ptr_a = *ptr_b;
	cout << *ptr_a << " " << *ptr_b << "\n";
	cout << num_c << " " << *&*&*&num_c << "\n";
	return 0;
}
