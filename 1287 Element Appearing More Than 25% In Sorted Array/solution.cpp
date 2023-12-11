#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0;
        int prev = -1;
        int size = arr.size();
        int quarterSize = size/4;
        for(int i = 0; i < size; i++){
            if(arr[i] != prev){
                prev = arr[i];
                count = 0;
            }
            count +=1;
            if(count > quarterSize){
                return prev;
            }
        }
        return prev;
    }
};