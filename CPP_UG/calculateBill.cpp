#include<iostream>
using namespace std;

//function declaration
double total_cost(int number_par, double price_par);
//Computes total cost, including 5% sales tax, 
//on number_par items at a cost of price_par each.
//
int main() 
{
	double price, bill;
	int number;

	cout << "Enter the number of items purchased" << "\n";
	cin >> number;

	cout << "Enter the price per item $" << "\n";
	cin >> price;

	bill = total_cost(number, price);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << number << " items at "
	     << "$" << price << " each. \n"
	     << "Final Bill, including tax, is $" << bill
	     << endl;
	return 0;

}

//function definition
double total_cost(int number_par, double price_par)
{
	const double TAX_RATE = 0.05;
	double subtotal;

	subtotal = price_par * number_par;
	return subtotal + (subtotal*TAX_RATE);
}
