#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
vector<pair<int, int>> adj[100001];

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> dist(n + 1, LLONG_MAX);
    set<pair<int, int>> st;
    st.insert({0, 1});
    dist[1] = 0;

    while (!st.empty())
    {
        auto front = *st.begin();
        st.erase(front);
        int node = front.second;
        int cur = front.first;

        for (auto it : adj[node])
        {
            if (dist[it.first] > cur + it.second)
            {
                if (dist[it.first] != 1e9)
                    st.erase({dist[it.first], it.first});
                dist[it.first] = cur + it.second;
                st.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
        cout << dist[i] << " ";

    return 0;
}