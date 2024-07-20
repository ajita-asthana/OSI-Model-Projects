#include <iostream>
#include <string>
using namespace std;

//Define the Car class
class Car {
private:
	//Private attributes
	string brand;
	string model;
	int years;

public:
	//Constructor to initialize the car object
	Car(string b, string m, int y) {
		brand = b;
		model = m;
		years = y;
	}
	
	Car(const Car &other) {
		brand = other.brand;
		model = other.model;
		years = other.years;
	}

	//Public member functions to display car details
	void displayDetails() {
		cout << "Brand: " << brand << endl;
		cout << "Model: " << model << endl;
		cout << "Year: " << years << endl;
	}

	//Public member function to start the car
	void start() {
		cout << "The car " << brand << " " << model << " is starting..." << endl;
	}
};

//Function to display pass-by-value
void displayCar(Car car) {
	car.displayDetails();
}

int main() {
	//Create car objects
	Car car1("Toyota", "Corolla", 2020);
	Car car2("Honda", "Civic", 2018);

	//Display details and start the cars
	cout << "Car 1 details: " << endl;
	car1.displayDetails();
	car1.start();

	cout << "\n Car2 Details: " << endl;
	car2.displayDetails();
	car2.start();
	
	//Demonstrate the copy constructor
	cout << "\nCreating Car3 as a copy of Car1 \n" << endl;
	Car car3 = car1;
	car3.displayDetails();

	//Demonstrate pass-by-value (calls copy constructor)
	cout << "\nPassing car2 to displayCar function (calls copy constructor)" << endl;
	displayCar(car2);
	return 0;
}
