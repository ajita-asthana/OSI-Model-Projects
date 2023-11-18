#include <vector>
#include <iostream>
#include <utility>
using namespace std;
class Solution {
    public:
    int maxFrequency(vector<int>& nums, int k)
    {
        long sum = 0;
        int i=0, j=0; 

        while (j < nums.size())
        {
            sum += nums[j];
            if(sum + k < (long)(nums[j] * (j-i)))
            {
                sum -= nums[i];
                i++;
            }
            j++;
        }
        cout << j-i << "\n";
        return j-i;
    }
};