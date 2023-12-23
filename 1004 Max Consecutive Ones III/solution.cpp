#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sze = nums.size();
        int limit = 0;
        for(int roam = 0; roam < sze; roam++){
            //case 1: Meet 1, continue
            //case 2: Meet 0, reserves still enough, continue but decrement reserve
            //case 3: Meet 0, reserve not enough, 
                //- if the front is 0, then safely move the reserve to the back
                //- if the front is 1, then do not add the window size (even when negative, it is okay because if in the back there is better case (more consecutive 0 which cause higher score), it will restore the size)
            if(!nums[roam]){
                k--;
            }
            //contradict reserve 0, check whether
            if(k < 0 && nums[limit++]==0) k++;
        }
        return sze - limit;
    }
};