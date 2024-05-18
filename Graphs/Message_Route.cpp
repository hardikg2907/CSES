#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
vector<int> adj[200001];
int par[200001];
int vis[200001] = {0};

void bfs(int node)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int it : adj[front])
        {
            if (!vis[it])
            {
                par[it] = front;
                q.push(it);
                vis[it] = 1;
            }
        }
    }
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

    bfs(1);
    if (!vis[n])
        cout << "IMPOSSIBLE";
    else
    {
        vector<int> path;
        path.push_back(n);
        while (path.back() != 1)
        {
            path.push_back(par[path.back()]);
        }
        cout << (int)path.size() << endl;
        reverse(path.begin(), path.end());
        for (int it : path)
            cout << it << " ";
    }

    return 0;
}