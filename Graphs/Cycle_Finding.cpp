#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int INF = 9e17;
vector<int> cycle;

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v);
    }
    vector<int> dist(n + 1, 0);
    vector<int> relaxant(n + 1);
    // dist[1] = 0;

    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                relaxant[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        x = relaxant[x];
    }

    for (int i = x;; i = relaxant[i])
    {
        cycle.push_back(i);
        if (i == x && cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for (auto c : cycle)
        cout << c << " ";
    return 0;
}