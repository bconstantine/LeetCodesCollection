#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAXN = 100005; // Maximum number of vertices
const int INF = numeric_limits<int>::max(); // Infinity value

//int n = 4; // Number of nodes
//adj[0].push_back({1, 2}); // Node 0 -> Node 1 with weight 2
//adj[0].push_back({2, 4}); // Node 0 -> Node 2 with weight 4
//adj[1].push_back({3, 3}); // Node 1 -> Node 3 with weight 3
//adj[2].push_back({3, 1}); // Node 2 -> Node 3 with weight 1
vector<pair<int, int>> adj[MAXN]; // Adjacency list: pair(node, weight)

vector<int> dijkstra(int source, int n) {
    vector<int> dist(n, INF); // Distance vector filled with INF
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue

    dist[source] = 0; // Distance to source is 0
    pq.push({0, source}); // Push source to priority queue

    while (!pq.empty()) {
        int u = pq.top().second; // Current node
        int d = pq.top().first;  // Current node's distance
        pq.pop();

        if (d > dist[u]) continue; // Skip if the current distance is not optimal

        // Iterate through neighbors
        for (auto &edge : adj[u]) {
            int v = edge.first; // Neighbor node
            int w = edge.second; // Weight of edge

            // Relaxation step
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // Update distance
                pq.push({dist[v], v}); // Push neighbor to priority queue
            }
        }
    }

    return dist; // Return the computed distances
}
