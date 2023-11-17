#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxPair = 0;
        int n = 0;
        int j = nums.size() - 1;
        for(; n < nums.size() / 2; n++, j--){
            maxPair = max(maxPair, nums[n]+nums[j]);
        }
        return maxPair;
    }
};