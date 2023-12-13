#include<iostream>
#include<vector>

using namespace std;
bool isPrime(int num)
{
    bool res = true;
    for(int j=2; j<num; j++)
    {
        if(num%j == 0)
        {
            res = false;
            break;
        }
    }
    return res;
}
int main()
{
    int N;
    cout << "Enter the value of N: " << "\n";
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int num;
        cout << "Enter the num " << "\n";
        cin >> num;
        if(isPrime(num))
            cout << num << " is a prime number" << "\n";
        else
            cout << num << " is not a prime number" << "\n";
    }
    return 0;
}