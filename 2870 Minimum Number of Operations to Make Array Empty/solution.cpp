#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int countSteps(vector<int> &matches, int numberSearch){
        return 0;
    }

    int minOperations(vector<int>& nums) {
        int sze = nums.size();
        map<int, int> numsAmt; 
        for(int i = 0; i < sze; i++){
            if(numsAmt.find(nums[i]) == numsAmt.end()){
                numsAmt[nums[i]] = 1;
            }else{
                numsAmt[nums[i]] += 1;
            }
        }
        int amt = 0;
        for(auto iter = numsAmt.begin(); iter != numsAmt.end(); iter++){
            if(iter->second < 2){
                return -1;
            }else{
                amt += (iter->second-1)/3+1;
            }
        }
        return amt;
    }
};