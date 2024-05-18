#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

vector<int> tree[200001];
int dp[200001][2];

void solve(int src, int par)
{
    vector<int> prefix, suffix;
    dp[src][0] = dp[src][1] = 0;

    bool leaf = 1;
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        leaf = 0;
        solve(child, src);
    }

    if (leaf)
        return;
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        prefix.push_back(max(dp[child][0], dp[child][1]));
        suffix.push_back(max(dp[child][0], dp[child][1]));
    }

    for (int i = 1; i < (int)prefix.size(); i++)
    {
        prefix[i] += prefix[i - 1];
    }
    for (int i = (int)suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
    }

    dp[src][0] = suffix[0];
    int c_no = 0;
    for (int child : tree[src])
    {
        if (child == par)
            continue;
        int leftChildren = (c_no == 0) ? 0 : prefix[c_no - 1];
        int rightChildren = (c_no == (int)suffix.size() - 1) ? 0 : suffix[c_no + 1];

        dp[src][1] = max(dp[src][1], 1 + leftChildren + rightChildren + dp[child][0]);
        c_no++;
    }
}

signed main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n + 1);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        solve(1, 0);
        cout << max(dp[1][0], dp[1][1]);
    }

    return 0;
}