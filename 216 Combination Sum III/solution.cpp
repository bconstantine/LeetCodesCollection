#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recursiveFind(int lastNumber, int remainingNumberAmt, int currentRemaining, vector<vector<int>> &ans, vector<int>& temp){
        // for(int i = 0; i < temp.size(); i++){
        //     cout << temp[i] << " ";
        // }
        // cout << "\n";
        if(remainingNumberAmt == 0){
            if(currentRemaining == 0){
                ans.push_back(temp);
            }
            return;
        }

        int maxIteration = currentRemaining / remainingNumberAmt;
        for(int i = lastNumber + 1; i <= maxIteration && i < 10; i++){
            temp.push_back(i);
            recursiveFind(i, remainingNumberAmt-1, currentRemaining - i, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int maxSum = 0;
        int minSum = 0;
        vector<vector<int>> ans; 
        for(int i = 0; i < k; i++){
            minSum += i+1;
            maxSum += 9-i;
        }
        if(n >= minSum && n<= maxSum){
            vector<int> temp;
            if(n == minSum){
                for(int i = 0; i < k; i++){
                    temp.push_back(i+1);
                }
                ans.push_back(temp);
                return ans;
            }
            if(n == maxSum){
                for(int i = 0; i < k; i++){
                    temp.push_back(9-i);
                }
                ans.push_back(temp);
                return ans;
            }
            recursiveFind(0, k, n, ans, temp);
        }
        return ans;
    }
};