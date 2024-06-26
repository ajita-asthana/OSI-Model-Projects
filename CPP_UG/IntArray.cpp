#include <iostream>

class IntArray {
private:
    int* array;
    int size;

public:
    IntArray(int size) {
        this->size = size;
        array = new int[size];
    }

    ~IntArray() {
        delete[] array;
    }

    void setValue(int index, int value) {
        if(index >= 0 && index < size) {
            array[index] = value;
        }
    }

    int getValue(int index) {
        if(index >= 0 && index < size) {
            return array[index];
        }
        return -1; //indicate error
    }

    void print() {
        for(int i=0; i<size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    void causeMemoryLeak() {
        int* leakyArray = new int[100];
        //Intentionally not deleting the array
    }
};

int main() {
    IntArray arr(10);
    for(int i=0; i<10; i++) {
        arr.setValue(i, i*10);
    }
    arr.print();
    //causeMemoryLeak();
    return 0;
}