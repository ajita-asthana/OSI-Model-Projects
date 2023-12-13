#include <iostream> 
#include <cstdlib> // C standard library, defines rand(), srand(), RAND_MAX
#include <ctime>
using namespace std;
int main() {
    srand(time(0));  //set the seed
    int randNum = rand();
    cout << "A random number is " << randNum << "\n";
}
