#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> result;
        map<int, vector<int>> totalKey;
        int numSize = nums.size();
        for(int i = 0; i < numSize; i++){
            vector<int> currentVec = nums[i];
            int currentSize = currentVec.size();
            for(int j = 0; j < currentSize; j++){
                if(totalKey.find(i+j) == totalKey.end()){
                    totalKey[i+j] = vector<int>(1, currentVec[j]);
                }else{
                    totalKey[i+j].push_back(currentVec[j]);
                }
            }
        }

        for(auto iter = totalKey.begin(); iter != totalKey.end(); iter++){
            for(auto innerIter = iter->second.rbegin(); innerIter != iter->second.rend(); innerIter++){
                result.push_back(*innerIter);
            }
        }
        return result; 
    }
};