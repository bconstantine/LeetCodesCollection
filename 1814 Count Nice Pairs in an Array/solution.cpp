#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long int reversedValue(int num){
        long long int val = 0;
        while(num > 0){
            val*= 10;
            val += num % 10;
            num /= 10;
        }
        return val;
    }
    int countNicePairs(vector<int>& nums) {
        int numberOfNicePairs = 0;
        map<long long int, int> moduloDiff;
        int numsSize = nums.size();
        for(int i = 0;  i < numsSize; i++){
            long long int key = nums[i] - reversedValue(nums[i]);
            //key %= 1000000007;
            if(moduloDiff.find(key) != moduloDiff.end()){
                numberOfNicePairs += moduloDiff[key];
                numberOfNicePairs %= 1000000007;
                moduloDiff[key] += 1;
                moduloDiff[key] %= 1000000007;
            }else{
                moduloDiff[key] = 1;
            }
        }
        return numberOfNicePairs;
    }
};