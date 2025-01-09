#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        int count = 0;
        vector<char> translationKeys(26, '0');
        for(int i = 0; i < key.size(); i++){
            if(count == 26) break;
            if(key[i] == ' ') continue;
            int idx = key[i] - 'a'; 
            if(translationKeys[idx] != '0'){
                continue;
            }else{
                translationKeys[idx] = 'a'+ count++;
            }
        }
        string res = "";
        for(int i = 0;  i < message.size(); i++){
            if(message[i] == ' ') res.push_back(' ');
            else res.push_back(translationKeys[message[i] - 'a']);
        }
        return res;
    }
};