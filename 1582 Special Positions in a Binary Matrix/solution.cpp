#include <vector>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int matRowSize = mat.size();
        int matColSize = mat[0].size();
        vector<int> rowAmt;
        vector<int> colAmt;
        for(int i = 0; i < matColSize; i++){
            colAmt.push_back(0);
        }
        for(int i = 0; i < matRowSize; i++){
            rowAmt.push_back(0);
        }
        for(int i = 0; i < matRowSize; i++){
            for(int j = 0; j < matColSize; j++){
                colAmt[j] += mat[i][j];
                rowAmt[i] += mat[i][j];
            }
        }

        int amt = 0;
        for(int i = 0; i < matRowSize; i++){
            if(rowAmt[i] != 1) continue;
            for(int j = 0; j < matColSize; j++){
                if(colAmt[j] != 1) continue;
                if(mat[i][j]) amt += 1; 
            }
        }
        return amt; 
    }
};