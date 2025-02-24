#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr, int startIdx, int endIdx){
        while(startIdx < endIdx){
            swap(arr[startIdx++], arr[endIdx--]);
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        if(!k){
            return;
        }
        int arrLen = nums.size();
        k = k % arrLen;
        reverseArray(nums, 0, arrLen - 1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, arrLen - 1);
    }
};