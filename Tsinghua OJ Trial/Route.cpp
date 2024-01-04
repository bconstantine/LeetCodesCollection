#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> t;
vector<vector<int> > adj;

void solve()
{
    cin >> n >> m;
    t.resize(n);
    for(int &i: t)
        cin >> i;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dijkstra
    priority_queue<pair<ll, int> > q;
    vector<bool> visited(n, false);
    vector<ll> dist(n, 1e18);

    dist[0] = 0;
    q.push({0, 0});

    while(!q.empty()){
        ll cur_dist = -q.top().first;
        int tp = q.top().second;
        q.pop();

        if(visited[tp])
            continue;

        visited[tp] = true;
        
        for(auto u: adj[tp]){
            ll new_dist = (cur_dist/t[tp] + (cur_dist % t[tp] != 0))*t[tp] + 1;
            //cout << ' ' << t[tp] << ' ' << new_dist << endl;
            if(new_dist < dist[u]){
                dist[u] = new_dist;
                q.push({-new_dist, u});
            }
        }
    }

    for(int i=1;i<n;i++)
        cout << dist[i] << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int t;
    // cin >> t;
    // while (t--)
        solve();
}
