#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            vector<int> transactionProfit(k+1, INT_MIN);
            vector<int> minBuyPrice(k+1, INT_MAX);
            transactionProfit[0] = 0;
            minBuyPrice[0] = 0;
            for(int i = 0; i < prices.size(); i++){
                for(int trans = 1; trans <= k; trans++){
                    minBuyPrice[trans] = min(minBuyPrice[trans], prices[i]-transactionProfit[trans-1]);
                    transactionProfit[trans] = max(transactionProfit[trans], prices[i] - minBuyPrice[trans]);
                }
            }
            return transactionProfit[k];
        }
    };