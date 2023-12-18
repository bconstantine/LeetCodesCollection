#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numsize = nums.size();
        return nums[numsize-1]*nums[numsize-2] - nums[0]*nums[1];
    }
};