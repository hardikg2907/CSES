#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

bool dfs(int node, vector<int> adj[], vector<int> &marked, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it] && !marked[it])
        {
            if (dfs(it, adj, marked, vis))
                return true;
        }
        else if (marked[it])
            return true;
    }
    return false;
}

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<int> revAdj[n + 1];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        revAdj[v].push_back(u);
    }
    vector<int> dist(n + 1, LLONG_MIN);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != LLONG_MIN && dist[u] + wt > dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    vector<int> marked(n + 1, 0);
    vector<int> vis(n + 1, 0);
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != LLONG_MIN && dist[u] + wt > dist[v])
        {
            marked[v] = 1;
            dist[v] = dist[u] + wt;
        }
    }
    if (dfs(n, revAdj, marked, vis))
    {
        cout << -1;
        return 0;
    }
    cout << dist[n];
    return 0;
}