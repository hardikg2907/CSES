#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int INF = 9e17;
vector<vector<int>> adj;
vector<int> vis;
vector<int> indegree;

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    indegree.resize(n + 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for (int i = 1; i < n + 1; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (auto a : ans)
        cout << a << " ";

    return 0;
}