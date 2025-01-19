#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string romanNum = "";
        int divisor[7] = {1000, 500, 100, 50, 10, 5, 1};
        int digitDivisor[4] = {1000, 100, 10, 1};
        string fiveValueSymbol[4] = {"", "D", "L", "V"};
        string oneValueSymbol[4] = {"M", "C", "X", "I"};
        int curIdx = 0;
        while(num){
            int quotient = num / digitDivisor[curIdx];
            while(!quotient){
                curIdx += 1;
                quotient = num / digitDivisor[curIdx];
            }
            if (quotient == 9){
                romanNum += oneValueSymbol[curIdx] + oneValueSymbol[curIdx-1];
            }
            else if (quotient == 4){
                romanNum += oneValueSymbol[curIdx] + fiveValueSymbol[curIdx];
            }else{
                if(quotient >= 5 ){
                    romanNum += fiveValueSymbol[curIdx];
                }
                int remainder = quotient %5;
                for(int i = 0; i < remainder; i++){
                    romanNum += oneValueSymbol[curIdx];
                }
            }
            num -= (digitDivisor[curIdx] * quotient);
            curIdx += 1;
            
        }
        return romanNum;
    }
};