#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

vector<int> tree[200001];
int downpath[200001];
int diameter[200001];

void eval_downPaths(int src, int par)
{
    int bestChildPath = 0;
    bool leaf = 1;
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        leaf = 0;
        eval_downPaths(child, src);
        bestChildPath = max(bestChildPath, downpath[child]);
    }
    if (leaf)
        downpath[src] = 0;
    else
        downpath[src] = 1 + bestChildPath;
}

void solve(int src, int par)
{
    int ans = 0;
    vector<int> childrenDownPaths;
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        solve(child, src);
        childrenDownPaths.push_back(downpath[child]);
        ans = max(ans, diameter[child]);
    }

    int numOfChildren = childrenDownPaths.size();
    sort(childrenDownPaths.begin(), childrenDownPaths.end());

    if (numOfChildren == 0)
        diameter[src] = 0;
    else if (numOfChildren == 1)
        diameter[src] = 1 + childrenDownPaths[0];
    else
        diameter[src] = 2 + childrenDownPaths[numOfChildren - 1] + childrenDownPaths[numOfChildren - 2];

    diameter[src] = max(diameter[src], ans);
}

signed main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        eval_downPaths(1, 0);
        solve(1, 0);
        cout << diameter[1];
    }

    return 0;
}