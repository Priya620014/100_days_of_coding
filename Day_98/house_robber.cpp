#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int prev1 = 0;
        int prev2 = 0;
        int current = 0;
        
        for (int i = 0; i < n; ++i) {
            current = max(prev2, nums[i] + prev1);
            prev1 = prev2;
            prev2 = current;
        }
        
        return current;
    }
};
