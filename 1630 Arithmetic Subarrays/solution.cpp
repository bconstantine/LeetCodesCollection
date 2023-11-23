#include <vector> 
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int indexSize = l.size();
        vector<bool> returnResult;
        for(int indexGroup = 0; indexGroup < indexSize; indexGroup++){
            vector<int> newVec(nums.begin() + l[indexGroup], nums.begin() + r[indexGroup]+1);
            
            sort(newVec.begin(), newVec.end());
            int newVecSize = newVec.size();
            bool ans = true;
            if(newVecSize > 1){
                int diff = newVec[1] - newVec[0];
                for(int startArr = 2; startArr < newVecSize; startArr++){
                    if(newVec[startArr] - newVec[startArr-1] != diff){
                        ans = false;
                        break;
                    }
                }
            }
            returnResult.push_back(ans);
        }
        return returnResult;
    }
};