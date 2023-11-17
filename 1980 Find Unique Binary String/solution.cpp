#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 
class Solution {
public:
    int binaryToInt(string input){
        int returnVal = 0;
        int multiplier = 1;
        for(int i = input.size() -1; i > -1; i--){
            returnVal += (input[i]=='1') * multiplier;
            multiplier *= 2;
        }
        return returnVal;
    }

    string intToBinary(int number, int requiredLength){
        string binaryString = "";
        int divisor = pow(2, requiredLength - 1);
        while(number > 0){
            if(number / divisor){
                binaryString += "1";
            }
            else{
                binaryString += "0";
            }
            number %= divisor; 
            divisor /= 2;
        }
        
        for(int i = binaryString.length(); i < requiredLength; i++){
            binaryString += "0";
        }
        return binaryString;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        std::sort(nums.begin(), nums.end());
        int numCheck = 0;
        for(; numCheck < nums.size(); numCheck++){
            if(numCheck != binaryToInt(nums[numCheck])){
                break;
            }
        }

        return intToBinary(numCheck, nums[0].size());
    }
};