#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

const int INF = 9e17;

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<int> steps(n + 1, 0);
    steps[1] = 1;
    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[ans[i]])
        {
            steps[it] = (steps[it] + steps[ans[i]]) % mod;
        }
    }

    cout << steps[n];

    return 0;
}