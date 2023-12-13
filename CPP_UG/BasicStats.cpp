#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cout << "Enter the number N " << "\n";
    cin >> N;

    vector<int> vec;
    double mean;
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        int num;
        cout << "The ith " << i << " number is ";
        cin >> num;
        cout << "\n";
        sum += num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    mean = (sum)/ N;
    cout << "The mean is " << mean << "\n";
    cout << "The maximum value is " << vec[N-1] << "\n";
    cout << "The minimum value is " << vec[0] << "\n";
    return 0;
}