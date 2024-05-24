#include<iostream>
using namespace std;

double unitprice(int diameter, double price);
//determines which of the two pizzas is a better choice.
int main()
{
	int diameter_small, diameter_large;
	double price_small, price_large, 
	       unitprice_small, unitprice_large;

	cout << "Welcome to the Pizza Consumers Union \n";
	cout << "Enter diameter of a small pizza \n";
	cin >> diameter_small;
	cout << "Enter diameter of a large pizza \n";
	cin >> diameter_large;
	cout << "Enter the price of small pizza \n";
	cin >> price_small;
	cout << "Enter the price of large pizza \n";
	cin >> price_large;

	unitprice_small = unitprice(diameter_small, price_small);
	unitprice_large = unitprice(diameter_large, price_large);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Small pizza:\n"
	     << "Diameter = " << diameter_small << " inches\n"
	     << "Price = $" << price_small 
	     << " Per square inch = $" << unitprice_small << endl
	     << "Large pizza:\n" 
	     << "Diameter = " << diameter_large << " inches\n"
	     << "Price = $" << price_large
	     << "\nPer square inch = $" << unitprice_large << endl;

	if(unitprice_large < unitprice_small)
		cout << "The larger one is a better buy\n";
	else
		cout << "The smaller one is a better buy\n";
	
	cout << "Buon Appetito\n";
	return 0;
}

double unitprice(int diameter, double price)
{
	const double PI = 3.14159;
	double radius, area;

	radius = static_cast<double>(diameter)/2;
	area = PI * radius * radius;
	return (price/area);
}

