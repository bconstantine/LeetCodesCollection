#include <iostream>
#include <vector>
#include <climits> //INT_MAX
#include "math.h" //fmod
using namespace std;

int updateOrGetVector(vector<long long int> &mem, long long int requiredNumber){
    if(mem.size() < requiredNumber){
        //update mem until the required amount
        for(long long int nextNumber = mem.size()+1; nextNumber <= requiredNumber; nextNumber++){
            long long int maxAmt = LONG_LONG_MAX;
            if(nextNumber % 2 == 0){
                long long int idx = (nextNumber / 2) - 1;
                if(mem[idx] != -1){
                    maxAmt = min(maxAmt, mem[idx]+1);
                }
            }
            if(nextNumber*2 % 3 == 0){
                long long int idx = (nextNumber*2 / 3) - 1;
                if(mem[idx] != -1){
                    maxAmt = min(maxAmt, mem[idx]+1);
                }
            }
            if(nextNumber*4 % 5 == 0){
                long long int idx = (nextNumber*4 / 5) - 1;
                if(mem[idx] != -1){
                    maxAmt = min(maxAmt, mem[idx]+1);
                }
            }
            if(nextNumber*6 % 7 == 0){
                long long int idx = (nextNumber*6 / 7) - 1;
                if(mem[idx] != -1){
                    maxAmt = min(maxAmt, mem[idx]+1);
                }
            }
            if(maxAmt == INT_MAX){
                maxAmt = -1;
            }
            mem.push_back(maxAmt);
        }
        
    }
    // int counter = 0;
    // for(int i : mem){
    //     cout << "inside " << counter << ": " << i << "\n";
    //     count3er++;
    // }
    return mem[requiredNumber - 1];
}

int main(){
    int testAmt;
    cin >> testAmt;
    vector<long long int> num;
    num.push_back(0);
    for(int i = 0; i < testAmt; i++){
        int interestNumber;
        cin >> interestNumber;
        cout << updateOrGetVector(num, interestNumber) << "\n";
    }
}