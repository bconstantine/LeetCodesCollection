#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int numberOfSubstr = words.size();
        unordered_map<string, int> substrCount;
        for(auto word: words){
            if(substrCount.find(word) == substrCount.end()){
                substrCount[word] = 1;
            }else{
                substrCount[word] += 1;
            }
        }
        unordered_map<string, int> substrFastReset = substrCount;


        vector<int> answer;
        queue<string> emptyQueue;
        for(int offset = 0; offset < wordLength; offset++){
            int successOp = 0;
            queue<string>seenWords;
            substrCount = substrFastReset;
            for(int subStart = offset; subStart + wordLength <= s.size(); subStart+=wordLength){
                string substring = s.substr(subStart, wordLength);
                if(substrCount.find(substring) != substrCount.end()){
                    if(substrCount[substring] <= 0){
                        while(seenWords.front() != substring){
                            //cout << "When index is : " << subStart << " , the seenwWords are popped: " << seenWords.front() << "\n";
                            substrCount[seenWords.front()]+=1;
                            seenWords.pop();
                        }
                        //cout << "When index is : " << subStart << " , the seenwWords are popped: " << seenWords.front() << "\n";
                        substrCount[substring]+=1;
                        seenWords.pop();
                    }
                    //cout << "When index is : " << subStart << " , encounter and subtract " << substring << "\n";
                    substrCount[substring]--;
                    seenWords.push(substring);
                }else{
                    substrCount = substrFastReset;
                    seenWords = emptyQueue;
                }
                if(seenWords.size() >= numberOfSubstr){
                    int startIdx = subStart - wordLength*(numberOfSubstr-1);
                    answer.push_back(startIdx);
                    substrCount[s.substr(startIdx, wordLength)]++;
                    seenWords.pop();
                }
            }
        }
        return answer;
    }
};