#include "map"
#include "queue"
#include "algorithm"
using namespace std;


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> numValuePair; 
        priority_queue<int> keys; 
        for(int i = 0; i < nums.size(); i++){
            int currentNumber = nums[i];
            if(numValuePair.find(currentNumber) == numValuePair.end()){
                numValuePair[currentNumber] = 1;
                keys.push(currentNumber);
            }else{
                numValuePair[currentNumber] += 1;
            }
        }
        if(keys.size() < 2){
            return 0;
        }else{
            int minisums = 0;
            int sums = 0;
            while(keys.size() > 1){
                int accessTop = keys.top();
                minisums += numValuePair[accessTop];
                sums += minisums;
                keys.pop();
            }
            return sums;
        }
    }
};