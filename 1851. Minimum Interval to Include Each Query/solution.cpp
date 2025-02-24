#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        enum EVENTTYPE {
                    STARTINTERVAL,
                    QUERY,
                    ENDINTERVAL
        };
        vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            //sort the intervals based on the starting point
            
            vector<int> ans(queries.size(), -1);
            vector<vector<int>> items;
            
            for(int i = 0; i < intervals.size(); i++){
                int startInterval = intervals[i][0];
                int endInterval = intervals[i][1];
                int length = endInterval - startInterval + 1;
                items.push_back({startInterval, STARTINTERVAL, length});
                items.push_back({endInterval, ENDINTERVAL, length});
            }
            for(int i = 0; i < queries.size(); i++){
                items.push_back({queries[i], QUERY, i});
            }
            sort(items.begin(), items.end());
            multiset<int> sizes;
            for(int i = 0; i < items.size(); i++){
                EVENTTYPE curEvent = static_cast<EVENTTYPE>(items[i][1]);
                if(curEvent == STARTINTERVAL){
                    sizes.insert(items[i][2]);
                }else if(curEvent == QUERY){
                    if(sizes.size()){
                        ans[items[i][2]] = *sizes.begin();
                    }
                }else{
                    sizes.erase(sizes.lower_bound(items[i][2]));
                }
            }
            return ans;
        }
    };