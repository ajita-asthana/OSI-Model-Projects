#include <iostream>
#include <string>

class Animal {
    public:
    //Virtual function
    virtual void makeSound() const {
        std::cout << "Animal makes a sound \n";
    }
};

//Derived class 1
class Dog : public Animal {
    public:
    //Overritde makeSound function
    void makeSound() const override {
        std::cout << "Dog barks\n";
    }
};

//Derived class 2
class Cat : public Animal {
    public:
    //Override makeSound function
    void makeSound() const override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    //Pointer to the base class type
    Animal* animalPtr;

    //Instantiate a Dog object and assign its address to the  base class
    animalPtr = new Dog;

    //call the makeSound function
    animalPtr->makeSound();

    //Instantiate a Cat object and assign its address to the base class
    animalPtr = new Cat;
    //Call the makeSound function
    animalPtr->makeSound();

    //Free memory
    delete animalPtr;
    return 0;
}