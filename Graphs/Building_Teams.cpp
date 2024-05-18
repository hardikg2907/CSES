#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
vector<int> adj[100001];
int vis[100001] = {0};

bool dfs(int node, int team)
{
    vis[node] = team;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (!dfs(it, team == 1 ? 2 : 1))
                return false;
        }
        else if (vis[it] == vis[node])
            return false;
    }

    return true;
}

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool poss = false;
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            poss = dfs(i, 1);
            if (!poss)
            {
                cout << "IMPOSSIBLE";
                break;
            }
        }
    }

    if (poss)
    {
        for (int i = 1; i < n + 1; i++)
        {
            cout << vis[i] << " ";
        }
    }

    return 0;
}