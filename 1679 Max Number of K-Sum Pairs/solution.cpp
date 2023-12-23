#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int end = nums.size(); 
        int lastIdx = end - 1;
        int ans = 0;
        for(int i = 0; i < lastIdx; i++){
            int sum = nums[i] + nums[lastIdx];
            if(sum > k){
                i -= 1;
                lastIdx -=1;
            }else if(sum < k){

            }else{
                ans += 1;
                lastIdx--;
            }
        }
        return ans; 
    }
};