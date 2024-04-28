#include <iostream>

//function that takes an integer and prints it
void printNumber(int num) {
    std::cout << "Number: " << num << std::endl;
}

//Function that takes a string and prints it
void printString(const std::string& str) {
    std::cout << "String: " << str << std::endl;
}

typedef void (*func)(int);
//Function that takes a function pointer and calls it
void callback(func func_) {
    func_(42); //call the function pointer with an integer argument
}

int main() {
    //declare function pointers
    void(*intCallback)(int) = &printNumber;
    void(*stringCallback)(const std::string&) = printString;

    //call the callback function with function pointers
    callback(intCallback);
}