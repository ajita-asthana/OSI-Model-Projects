#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

typedef int *IntPtrType;

int main(void)
{
    std::vector<int> myVector(10);
    try {
        myVector.at(20) = 100;
    }
    catch(const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << "\n";
    }
    return 0;
}