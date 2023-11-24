#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater());
        int total = 0;
        int front = 0;
        int back = piles.size() - 1;
        while(front < back){
            total += piles[++front];
            front++; 
            back--;
        }
        return total;
    }
};