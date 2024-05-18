#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
vector<int> tree[200001];

int up[2000001][20];

void binary_lifting(int src, int par)
{
    up[src][0] = par;
    for (int i = 1; i < 20; i++)
    {
        if (up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else
            up[src][i] = -1;
    }

    for (int child : tree[src])
    {
        if (child == par)
            continue;
        binary_lifting(child, src);
    }
}

int ans_query(int node, int jump)
{
    if (node == -1 || jump == 0)
        return node;

    for (int i = 19; i >= 0; i--)
    {
        if (jump >= (1 << i))
            return ans_query(up[node][i], jump - (1 << i));
    }
}

signed main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 2; i < n + 1; i++)
    {
        int x;
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    binary_lifting(1, -1);
    while (q--)
    {
        int node, k;
        cin >> node >> k;
        cout << ans_query(node, k) << endl;
    }

    return 0;
}