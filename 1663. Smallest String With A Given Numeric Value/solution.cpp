#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string resultString = "";
        for(int index = n-1; index > -1; index--){
            int remainingInFront = index;
            int choosenIndex = min(26, k-remainingInFront);
            k -= choosenIndex;
            resultString.push_back('a'+choosenIndex - 1);
        }
        reverse(resultString.begin(), resultString.end()); 
        return resultString;
    }
};