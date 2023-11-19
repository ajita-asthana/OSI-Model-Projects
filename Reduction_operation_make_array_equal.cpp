#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        //sort the vector in reverse because we are interested in the larger value 
        sort(nums.begin(), nums.end(), greater<int>());

        // Largest Value at lowest index (frequency of larger element)
        int totalSteps = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                totalSteps += i;
            }
        }
        return totalSteps;
        
    }
};