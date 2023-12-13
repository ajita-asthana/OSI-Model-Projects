#include <iostream> 
#include <cstdlib> // C standard library, defines rand(), srand(), RAND_MAX
#include <cctype>
using namespace std;

int main() {
    //String manipulation
    char messyString[] = "t6H0I9s6.iS.999a9.STRING";
    char current = messyString[0];
    for(int i=0; current != '\0'; current = messyString[++i])
    {
        if(isalpha(current))
            cout << char(isupper(current) ? tolower(current) : current);
        else if(ispunct(current))
            cout << ' ';
    }
    cout << endl;
    return 0;
}
