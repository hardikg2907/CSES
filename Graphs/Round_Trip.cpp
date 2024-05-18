#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
vector<int> adj[100001];
bool vis[100001];
int parent[100001];
vector<int> path;
int sv, ev;
int n, m;

bool dfs(int src, int par)
{
    vis[src] = true;
    parent[src] = par;
    for (auto it : adj[src])
    {
        if (it == par)
            continue;
        if (vis[it])
        {
            sv = it;
            ev = src;
            return true;
        }
        if (!vis[it])
        {
            if (dfs(it, src))
                return true;
        }
    }

    return false;
}

bool visit_all()
{
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
                return true;
        }
    }

    return false;
}

signed main()
{
    IOS;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (visit_all())
    {
        int tv = ev;
        vector<int> ans;
        ans.push_back(ev);
        while (tv != sv)
        {
            ans.push_back(parent[tv]);
            tv = parent[tv];
        }
        ans.push_back(ev);
        cout << ans.size() << endl;
        for (int c : ans)
        {
            cout << c << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}