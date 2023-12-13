#include <iostream> 
#include <cstdlib> // C standard library, defines rand(), srand(), RAND_MAX
#include <ctime>
using namespace std;

void swap(int& p, int& q)
{
    int t;
    t = p;
    p = q;
    q = t;
}
int main() {
    //swap function
    int a = 3;
    int b = 5;
    swap(a, b);
    cout << "a is " << a << "\n";
    cout << "b is " << b << "\n";
    return 0;
}
