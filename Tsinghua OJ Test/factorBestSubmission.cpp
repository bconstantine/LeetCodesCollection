#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// void getFactors(long long int num, vector<long long int> &res){
void getFactors(long long int num,  vector<long long int> &res, int idx){
    long long int amt = 2;
    long long int less = num;
    for(long long int i = 2; i < less; i++){
        if (num%i == 0){
            if(i != (num/i)){
                // cout << num << " " << i <<"\n";
                // cout << num << " " << num/i <<"\n";
                amt+=2;
                less = num/i;
            }else{
                // cout << num << " " << i <<"\n";
                // cout << num << " " << i <<"\n";
                amt += 1;
                less = i;
            }
        }
    }
    //cout << "Final answer: " << num << " " << amt<< "\n";
    // res.push_back(amt);
    res[idx] = amt;
}

int main(){
    vector<long long int> factorsCollection(3,0);
    // long long int* factorsCollection = new long long int[3];
    for(long long int i = 0; i < 3; i++){
        long long int num;
        cin >> num; 
        // getFactors(num, factorsCollection);
        getFactors(num, factorsCollection, i);
    }
    sort(factorsCollection.begin(), factorsCollection.end());
    // sort(factorsCollection[0], factorsCollection[2]);
    cout << factorsCollection[1];
}

