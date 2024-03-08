#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    void addEntry(vector<vector<string>> &answer, vector<int> &colCombination){
        int boxSize = colCombination.size();
        vector<string> ans;
        for(int i = 0; i < boxSize; i++){
            string toBeInserted(boxSize, '.');
            toBeInserted[colCombination[i]] = 'Q';
            ans.push_back(toBeInserted);
        }
        answer.push_back(ans);
    }

    bool validDiagonal(vector<int>& colCombination){
        int sze = colCombination.size();
        for(int firstComp = 0; firstComp < sze - 1; firstComp++){
            for(int secondComp = firstComp + 1; secondComp < sze; secondComp++){
                if(secondComp - firstComp == abs(colCombination[secondComp] - colCombination[firstComp])){
                    return false;
                }
            }
        }
        return true;
    }

    void coutPartiallyCorrect(vector<int> colCombination, int rowAmount){
        if(colCombination.size() >= rowAmount){
            if(rowAmount >= 1 && colCombination[0] != 1){
                return;
            }
            if(rowAmount >= 2 && colCombination[1] != 3){
                return;
            }
            if(rowAmount >= 3 && colCombination[2] != 0){
                return;
            }
            if(rowAmount >= 4 && colCombination[3] != 2){
                return;
            }
            cout << "partially correct to " << rowAmount << "\n";
        }
    }

    void backTrackQueen(vector<vector<string>> &answer, vector<int> &colCombination, set<int> &colNumbers, int &colAmount){
        if(colCombination.size() >= colAmount ){
            addEntry(answer, colCombination);
            return;
        }

        for(int i = 0; i < colAmount; i++){
            if(!(colNumbers.insert(i).second)){
                //cout << "failed inserting " << i << "\n";
                continue;
            }
            //cout << "success inserting " << i << "\n";
            colCombination.push_back(i);
            //coutPartiallyCorrect(colCombination, 2);
            if(validDiagonal(colCombination)){
                backTrackQueen(answer, colCombination, colNumbers, colAmount);
            }
            colCombination.pop_back();
            colNumbers.erase(i);
            //cout << "success erasing " << i << "\n";
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> colCombination;
        set<int> colExist;
        vector<vector<string>> answer;

        backTrackQueen(answer, colCombination, colExist, n);
        return answer;
    }
};