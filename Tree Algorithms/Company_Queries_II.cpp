#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
vector<int> tree[200001];

int up[2000001][20];
int lvl[2000001];

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

int lift_node(int node, int jump)
{
    if (node == -1 || jump == 0)
        return node;

    for (int i = 19; i >= 0; i--)
    {
        if (jump >= (1 << i))
            return lift_node(up[node][i], jump - (1 << i));
    }
}

void laeval_niklenge(int node, int par, int level = 0)
{
    lvl[node] = level;
    for (int child : tree[node])
    {
        if (child == par)
            continue;
        laeval_niklenge(child, node, level + 1);
    }
}

// log^2 N approach
// int LCA(int u, int v)
// {
//     if (lvl[u] < lvl[v])
//         swap(u, v);

//     u = lift_node(u, lvl[u] - lvl[v]);
//     int low = 0, high = lvl[u];
//     while (low != high)
//     {
//         int mid = (low + high) / 2;
//         int x1 = lift_node(u, mid);
//         int x2 = lift_node(v, mid);
//         if (x1 == x2)
//             high = mid;
//         else
//             low = mid + 1;
//     }
//     return lift_node(u, low);
// }

// logN approach
int LCA(int u, int v)
{
    if (lvl[u] < lvl[v])
        swap(u, v);

    u = lift_node(u, lvl[u] - lvl[v]);
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1);
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
    laeval_niklenge(1, 0, 0);
    while (q--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        cout << LCA(node1, node2) << endl;
    }

    return 0;
}