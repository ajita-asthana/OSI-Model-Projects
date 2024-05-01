#include <iostream>
#include <string>
using namespace std;
struct Person {
    private:
        string name;
        int age;
        float height;

    public:
    // what does "->" mean ?

        void setValues(const std::string &name, int age, float height) {
            this->name = name;
            this->age = age;
            this->height = height;
        } 

        //Method to get name 
        std::string getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }

        float getHeight() const {
            return height;
        }

        void printDetails() const {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Height: " << height << " feet" << std::endl;
        }
};


int main() {
    Person person;

    //use the setValues method to set the values of the person object
    person.setValues("John", 30, 5.9);

    //Access and print the values of the person object
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;
    std::cout << "Height: " << person.getHeight() << " feet" << std::endl;

    //print the details of the person using the printDetails method
    person.printDetails();

    return 0;
}


