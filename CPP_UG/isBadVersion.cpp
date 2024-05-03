#include <iostream>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right) {
            long long int mid = left + (right - left) / 2;
            if(firstBadVersion(mid)) {
                ans = mid;
                left = mid - 1; 
            }
            else {
                left = mid + 1;
            }
        }
        return  ans;
    }
};

int main() 
{
    //pointer to the class
    Solution* soln;
    //instantiate the class
    soln = new Solution;
    int n = 5;
    int ans = soln->firstBadVersion(n);
    cout << ans;
    return 0;
}


