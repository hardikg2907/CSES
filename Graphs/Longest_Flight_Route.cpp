#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

void dfs(ll node, vector<ll> &vis, vector<vector<ll>> &g, stack<ll> &s)
{
    vis[node] = 1;
    for (auto child : g[node])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, g, s);
        }
    }
    s.push(node);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n + 1);
    vector<ll> vis(n + 1, 0);
    stack<ll> s;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<ll> dis(n + 1, -1e9);
    vector<ll> par(n + 1, 0);

    // do toposort(ohoho);
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, g, s);
        }
    }
    if (s.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    dis[1] = 0;
    while (!s.empty())
    {
        ll node = s.top();
        s.pop();
        for (auto child : g[node])
        {
            if (dis[node] != -1e9 && dis[child] < dis[node] + 1)
            {
                dis[child] = dis[node] + 1;
                par[child] = node;
            }
        }
    }
    if (dis[n] == -1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<ll> path;
        path.push_back(n);
        while (n != 1)
        {
            n = par[n];
            path.push_back(n);
        }
        cout << path.size() << endl;
        for (ll i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
    }
}

signed main()
{
    // faster input and output
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}