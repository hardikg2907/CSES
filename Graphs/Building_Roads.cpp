#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        ds.unite(u, v);
    }

    int cc = 0;
    vector<int> cities;
    for (int i = 1; i < n + 1; i++)
    {
        if (ds.find(i) == i)
        {
            cc++;
            cities.push_back(i);
        }
    }

    cout << cc - 1 << endl;
    if (cc > 1)
    {
        for (int i = 1; i < cc; i++)
        {
            cout << cities[i - 1] << " " << cities[i] << endl;
        }
    }

    return 0;
}