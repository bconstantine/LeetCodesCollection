#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int repeatingNumber = 0;
        int currentNumber = -100000;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(currentNumber < nums[i]){
                repeatingNumber = 1;
                currentNumber = nums[i];
                swap(nums[i], nums[index]);
                index++;
            }else{
                repeatingNumber+=1;
                if(repeatingNumber < 3){
                    swap(nums[i], nums[index]);
                    index++;
                }
            }
        }
        return index;
    }
};