#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int INF = 9e17;
const int mod = 1e9 + 7;
vector<pair<int, int>> adj[100001];

signed main()
{
    IOS;
    int n, m, k;
    cin >> n >> m >> k;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<vector<int>> dist(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dist[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            dist[i][j] = INF;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1][0] = 0;

    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();
        int node = front.second;
        int cur = front.first;
        if (dist[node][k - 1] < cur)
            continue;

        for (auto it : adj[node])
        {
            if (dist[it.first][k - 1] > cur + it.second)
            {
                dist[it.first][k - 1] = cur + it.second;
                pq.push({dist[it.first][k - 1], it.first});
                sort(dist[it.first].begin(), dist[it.first].end());
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << dist[n][i] << " ";

    return 0;
}