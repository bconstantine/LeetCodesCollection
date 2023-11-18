#include "algorithm"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //sort to numerical
        sort(nums.begin(), nums.end());
        long long int leftEnd = 0;
        long long int rightEnd = 1;
        long long int maxLength = 1;
        long long int previousSum = nums[0];
        int wholeSize = nums.size(); 
        for(; rightEnd < wholeSize; rightEnd++){
            previousSum += nums[rightEnd];
            while((rightEnd-leftEnd+1) * nums[rightEnd] - previousSum > k){
                previousSum -= nums[leftEnd];
                leftEnd++;
            }
            maxLength = max(maxLength, rightEnd-leftEnd+1);
        }
        return maxLength;
    }
};