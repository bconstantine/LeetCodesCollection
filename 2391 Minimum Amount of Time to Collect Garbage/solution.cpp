#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int numberOfTrashes = 0;
        int paperLastAppear = 0;
        int metalLastAppear = 0;
        int glassLastAppear = 0;
        int lastTravelSum = 0;
        int garbageSize = garbage.size();

        //handle the first element
        numberOfTrashes += garbage[0].size();
        for(int i = 1; i < garbageSize; i++){
            string garbageStr = garbage[i];
            lastTravelSum += travel[i-1];
            int size = garbageStr.size();
            numberOfTrashes += size;
            bool paperFound = false;
            bool metalFound = false;
            bool glassFound = false;
            for(int j = 0; j < size; j++){
                if(garbageStr[j] == 'P'){
                    paperFound = true;
                    paperLastAppear = lastTravelSum;
                }else if(garbageStr[j] == 'M'){
                    metalFound = true;
                    metalLastAppear = lastTravelSum;
                }else{
                    glassFound = true;
                    glassLastAppear = lastTravelSum;
                }

                if(paperFound && metalFound && glassFound){
                    break;
                }
            }
        }

        return glassLastAppear + metalLastAppear + paperLastAppear + numberOfTrashes;
    }
};