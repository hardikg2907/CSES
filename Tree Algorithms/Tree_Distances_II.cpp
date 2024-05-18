#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
vector<int> tree[200001];
int ans[200001];
int subtreeAns[200001];
int subtreeSize[200001];

void preprocessing(int src, int par)
{
    int numOfNodes = 1;
    int ansForSubtree = 0;
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        preprocessing(child, src);
        numOfNodes += subtreeSize[child];
        ansForSubtree += subtreeAns[child] + subtreeSize[child];
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}

void solve(int src, int par, int par_ans, int &totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));

    for (int child : tree[src])
    {
        if (child == par)
            continue;
        solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    preprocessing(1, 0);
    solve(1, 0, 0, n);
    for (int i = 1; i < n + 1; i++)
        cout
            << ans[i] << ' ';

    return 0;
}