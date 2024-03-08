#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    const int maxDistance = 1000000;
    bool differenceIsOne(string a, string b){
        bool foundDiff = false;
        for(int i = 0; i < 8; i++){
            if(a[i] != b[i]){
                if(foundDiff){
                    return false;
                }
                foundDiff = true;
            }
        }
        return true;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        for(int i = 0; i < bank.size(); i++){
            if(bank[i] == endGene){
                break;
            }
            if(i == bank.size() - 1){
                return -1;
            }
        }
        map<string, vector<string>> graph;
        //initilaize graph
        graph[startGene] = vector<string>();
        graph[endGene] = vector<string>();
        for(int i = 0; i < bank.size(); i++){
            graph[bank[i]] = vector<string>();
        }
        for(int i = 0; i < bank.size(); i++){
            if(differenceIsOne(startGene, bank[i])){
                graph[startGene].push_back(bank[i]);
                graph[bank[i]].push_back(startGene);
            }
            if(differenceIsOne(endGene, bank[i])){
                graph[endGene].push_back(bank[i]);
                graph[bank[i]].push_back(endGene);
            }
            for(int j = i+1; j < bank.size(); j++){
                if(differenceIsOne(bank[i], bank[j])){
                    graph[bank[i]].push_back(bank[j]);
                    graph[bank[j]].push_back(bank[i]);
                }
            }
        }

        //Djikstra algorithm
        map<string, int> distance;
        for(int i = 0; i < bank.size(); i++){
            distance[bank[i]] = maxDistance;
        }
        distance[startGene] = 0;
        distance[endGene] = maxDistance;
        queue<string> q;
        q.push(startGene);
        while(!q.empty()){
            string current = q.front();
            q.pop();
            for(int i = 0; i < graph[current].size(); i++){
                string neighbor = graph[current][i];
                if(distance[neighbor] > distance[current] + 1){
                    distance[neighbor] = distance[current] + 1;
                    q.push(neighbor);
                }
            }
        }
        return distance[endGene] == maxDistance ? -1 : distance[endGene];
    }
};