#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0; 
        int currentEnd = 0;
        int farthest = 0;
        for(int i = 0; i < nums.size()-1; i++){
            int farthest = max(farthest, i+nums[i]);
            if(i == currentEnd){
                jumps += 1;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};