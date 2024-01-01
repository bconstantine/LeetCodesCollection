#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int countVowels(string s, int startIndex, int endIndex){
        int count = 0;
        for(int i = startIndex; i < endIndex; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                count += 1;
            }
        }
        return count;
    }

    int maxVowels(string s, int k) {
        int maxAmt = countVowels(s, 0, 0+k);
        int before = maxAmt; 
        int sze = s.size();
        for(int leftPtr = 1; leftPtr < sze-k+1; leftPtr++){
            int idx = leftPtr-1;
            int rightPtr = leftPtr+k-1;
            bool leftIsVowel = s[idx]=='a' || s[idx]=='e' || s[idx]=='i' || s[idx]=='o' || s[idx]=='u';
            bool rightIsVowel = s[rightPtr]=='a' || s[rightPtr]=='e' || s[rightPtr]=='i' || s[rightPtr]=='o' || s[rightPtr]=='u';
            if(leftIsVowel != rightIsVowel){
                if(leftIsVowel){
                    before -= 1;
                }else{
                    before += 1;
                }

                maxAmt = max(before, maxAmt);
            }
        }

        return maxAmt;
    }
};