#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buy1 = INT_MAX;
            int buy2 = INT_MAX;
            int maxProfit1 = INT_MIN;
            int maxTotalProfit = INT_MIN;
            for(int i = 0; i < prices.size(); i++){
                buy1 = min(buy1, prices[i]);
                maxProfit1 = max(prices[i]-buy1, maxProfit1);
                buy2 = min(buy2, prices[i]-maxProfit1);
                maxTotalProfit = max(maxTotalProfit, prices[i]-buy2);
            }
            return maxTotalProfit;
        }
    };