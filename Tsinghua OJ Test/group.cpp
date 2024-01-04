#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int rep;
    cin >> rep;
    vector<int> currentLevel; 
    bool consequtiveAns = true;
    for(int i = 0; i < rep; i++){
        int inNum;
        cin >> inNum;
        currentLevel.push_back(inNum);
    }
    int verifyLevel = 1;
    while(verifyLevel < rep){
        bool foundMatch = false;
        bool nextFoundSubsequent = false;
        int checkIdx = 0;
        vector<int> nextLevel; 
        int len = currentLevel.size();
        for(int start = 0; start < len - 1; start++){
            int res = currentLevel[start] & currentLevel[start+1];
            nextLevel.push_back(res);
            if(res) {
                foundMatch = true;
                if(!nextFoundSubsequent && start > 1 && nextLevel[start-1]){
                    nextFoundSubsequent=true;
                }
            }
        }
        if(!foundMatch){
            break;
        }
        if(!nextFoundSubsequent){
            verifyLevel+=1;
            break;
        }
        
        currentLevel = nextLevel;
        verifyLevel += 1;
    }
    cout << verifyLevel;
    return 0;

    // int leftPointers = 0;
    // int rightPointers = 0;
    // int maxAmt = 0;
    // int currentAnds = INT_MAX;
    // for(; rightPointers < rep; rightPointers++){

    // }

    // int bitwiseAnds = 5 & 3 & 2 & 10 & 7 & 6;
    // int notBitwise = ~5 & 3;
    // cout << notBitwise << "\n";
}