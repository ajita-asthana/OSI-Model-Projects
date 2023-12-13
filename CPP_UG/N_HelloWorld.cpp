#include<iostream>
using namespace std;
int main()
{
    const char* str = "Hello World!";
    int n;
    cout << "Enter a number N " << endl;
    cin >> n;

    //For loop
    for(int i=0; i<n; i++)
    {
        cout << str << "\n";
    }

    //While loop
    int j=0;
    while(j<n)
    {
        cout << str << "\n";
        j++;
    }

    //Do-While loop
    int k=0;
    do {
        cout << str << "\n";
        k++;
    } while(k < n);

    return 0;
}