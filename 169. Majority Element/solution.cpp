#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int centerNumber = nums[nums.size() / 2];
        return centerNumber;
    }
};