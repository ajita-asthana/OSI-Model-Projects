#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        int num;
        cout << "Enter a number " << "\n";
        cin >> num;
        if(num > 0 && num%5 == 0)
            cout << num/5  << "\n";
        else if(num > 0 )
        {
            cout << "-1 \n";
            continue;
        }
        else if(num < 0)
        {
            cout << "GoodBye" << "\n";
            break;
        }
    }
    return 0;
}