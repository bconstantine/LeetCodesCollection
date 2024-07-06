#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        k -= 1;
        string answer = "";
        string letterChoice[3] = {"a", "b", "c"};
        int order = pow(2, n-1);
        if (order*3 <= k){
            return answer;
        }
        int choice = k / order;
        k = k % order;
        int prevIndex = 0;
        if(choice > 1){
            prevIndex = 2;
        }else if(choice > 0){
            prevIndex = 1;
        }
        answer += letterChoice[prevIndex];
        for(int i = 1; i < n; i++){
            order /= 2;
            choice = k / order;
            k %= order;
            int adder = 1;
            if(choice){
                if(!(prevIndex % 2)){
                    adder = 2;
                }
            }else{
                if(prevIndex % 2){
                    adder = 2;
                }
            }
            prevIndex = (prevIndex + adder)%3;
            answer += letterChoice[prevIndex];
        }
        return answer;
    }
};