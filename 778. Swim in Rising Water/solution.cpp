#include <bits/stdc++.h>
using namespace std;
class coordinate{
    public: 
    int time;
    int row;
    int col; 
}; 

bool operator< (const coordinate &a, const coordinate &b) {
    return a.time > b.time;
}


class Solution {
public:
    int positionHashing(int row, int col){
        return row*50+col;
    }

    int swimInWater(vector<vector<int>>& grid) {
        //use djikstra
        priority_queue<coordinate> pq;
        set<int> seen; 
        pq.push({grid[0][0], 0,0});
        auto validIndex = [&](int row, int col){
            return row >= 0 && row < grid.size() && col >= 0 && col < grid.size();
        };

        int timeTook = 0;
        int direction[] = {-1, 0, 1, 0, -1};
        seen.insert(positionHashing(0,0));
        while(pq.size() > 0){
            coordinate current = pq.top();
            pq.pop();
            timeTook = max(timeTook, current.time);
            if(current.row == (grid.size() - 1) && current.col == (grid.size() - 1)){
                return timeTook;
            }

            for(int i=0; i<4; i++){
                int newRow = current.row+direction[i];
                int newCol = current.col+direction[i+1];
                int hashNewPos = positionHashing(newRow,newCol); 
                if(validIndex(newRow, newCol) && seen.find(hashNewPos) == seen.end()){
                    seen.insert(hashNewPos);
                    pq.push({grid[newRow][newCol], newRow, newCol});
                }
            }

        }
        return -1;
    }
};