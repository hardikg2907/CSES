#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

signed main()
{
    IOS;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, LLONG_MAX));
    for (int i = 1; i < n + 1; i++)
        dist[i][i] = 0;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (dist[u][v] > w)
        {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                // cout << dist[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] >= LLONG_MAX)
            cout << "-1" << endl;
        else
            cout << dist[u][v] << endl;
    }

    return 0;
}