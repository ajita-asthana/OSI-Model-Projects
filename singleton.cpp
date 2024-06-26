#include <iostream>

/**
 * Private constructor: ensures that the class cannot be instantiated from outside the class
 * Static getInstance: ensures that the instance is created once and provides global access to it
 * Deleted Copy constructor and assignment operator, prevent copying the singleton instance
 * Static local variable within getInstance() ensures that the instance is created only once, when it * is first accessed. 
**/

class Singleton {
private:
	//Private constructor to prevent instantiation
	Singleton() {
		std::cout << "Singleton instance created" << std::endl;
	}

	//Delete copy constructor and assignment operator to prevent copies
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	// Destructor
	~Singleton() {
		std::cout << "Singleton instance destroyed" << std::endl;
	}

public:
	// Public method to access the singleton instance
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}

	//Any other public methods
	void showMessage() const {
		std::cout << "Helllo from Singleton\n" << std::endl;
	}
};

int main() {
	//Access the singleton instance and call a method
	Singleton& singleton = Singleton::getInstance();
	singleton.showMessage();

	return 0;
}
