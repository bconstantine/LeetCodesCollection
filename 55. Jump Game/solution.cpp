#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> possible;
        int bigLen = nums.size(); 
        for(int i = 0; i < bigLen; i++){
            possible.push_back(false);
        }
        possible[bigLen - 1] = true;
        int lastTrue = bigLen - 1;
        for(int i = bigLen - 2; i >= 0; i--){
            if(i+nums[i] >= lastTrue){
                //bigger than the required leap? if yes then it can reach
                possible[i] = true;
                lastTrue = i;
            }
        }
        return possible[0];
    }
};