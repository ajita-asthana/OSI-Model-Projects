#include <iostream> 
#include <cstdlib> // C standard library, defines rand(), srand(), RAND_MAX
#include <cstring>
using namespace std;

int main() {
    //String manipulation
    char fragment1[] = "I'm a s";
    char fragment2[] = "tring!";
    char fragment3[20];
    char finalstring[20] = "";
    //strcpy(fragment3, fragment1);
    strcat(finalstring, fragment1);
    strcat(finalstring, fragment2);
    cout << finalstring;
    cout << endl;
    return 0;
}
