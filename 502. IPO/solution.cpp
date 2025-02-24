#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        struct customSortingRule{
            bool operator() (pair<int, int> &a, pair<int,int> &b){
                return a.first < b.first;
            }
        };
    
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            priority_queue<int> availableCapitals;
            int projCount = 0;
            vector<pair<int, int>> availableProjects;
            for(int i = 0; i < profits.size(); i++){
                availableProjects.push_back(make_pair(capital[i], profits[i]));
            }
            sort(availableProjects.begin(), availableProjects.end(), customSortingRule());
            int roamingIdx = 0;
            while(projCount < k){
                while(roamingIdx < availableProjects.size() && availableProjects[roamingIdx].first <= w){
                    availableCapitals.push(availableProjects[roamingIdx].second);
                    roamingIdx+=1;
                }
                if(availableCapitals.size() < 1){
                    break;
                }
                w += availableCapitals.top();
                availableCapitals.pop();
                projCount += 1;
            }
            return w;
        }
    };