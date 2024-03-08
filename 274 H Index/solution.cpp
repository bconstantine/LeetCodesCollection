#include <vector> 
#include <algorithm>
using namespace std; 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int>());
        int sze = citations.size();
        int i = 0;
        for(; i < sze; i++){
            if(citations[i] < i+1){
                break;
            }
        }
        return i;
    }
};