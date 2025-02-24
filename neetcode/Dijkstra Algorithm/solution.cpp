#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> distance; 
        map<int, vector< pair<int,int> > > adjacencyMatrix;
        for(int i = 0; i < n; i++){
            distance[i] = -1;
            adjacencyMatrix[i] = vector<pair<int,int>>();
        }        
        for(int i = 0 ; i < edges.size(); i++){
            vector<int> edge = edges[i];
            adjacencyMatrix[edge[0]].push_back(make_pair(edge[2], edge[1]));
            adjacencyMatrix[edge[1]].push_back(make_pair(edge[2], edge[1]));
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> distQueue;
        distQueue.push(make_pair(0, src));
        while(!distQueue.empty()){
            int currentNode = distQueue.top().second;
            int currentDistance = distQueue.top().first;
            distQueue.pop();
            //cout << "Beginning loop: " << currentNode << " " << currentDistance <<"\n";
            if(distance[currentNode] > -1 && distance[currentNode] < currentDistance){
                continue;
            }
            distance[currentNode] = currentDistance;
            //cout << "Updating current distance: " << currentDistance << " " << currentNode << "\n";
            for(auto iter = adjacencyMatrix[currentNode].begin(); iter != adjacencyMatrix[currentNode].end(); iter++){
                distQueue.push(make_pair(iter->first + currentDistance, iter->second));
                // cout << "iter->first: " << iter->first << "\n";
                // cout << "Pushing " << iter->second << " " << iter->first + currentDistance << "\n";
                // cout << "At the inner loop, distQueue length: " << distQueue.size() << "\n";
            }
            // cout << "At the end of array, distQueue length: " << distQueue.size() << "\n";
        }
        return distance;
    }
};
