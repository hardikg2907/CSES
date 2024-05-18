#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int INF = 9e17;
int n;

signed main()
{
    IOS;
    int m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    vector<int> dist(n + 1, INF), disc(n + 1, INF);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[1] = 0;
    disc[1] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty())
    {
        auto top = pq.top();
        int cost = top.first;
        int node = top.second.first;
        int coupon = top.second.second;
        pq.pop();

        if (coupon == 1) // coupon used
        {
            if (disc[node] < cost)
                continue;
        }
        else
        {
            if (dist[node] < cost)
                continue;
        }

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;
            if (coupon == 0)
            {
                if (dist[adjNode] > cost + edgeWt)
                {
                    dist[adjNode] = cost + edgeWt;
                    pq.push({dist[adjNode], {adjNode, 0}});
                }
                if (disc[adjNode] > cost + edgeWt / 2)
                {
                    disc[adjNode] = cost + edgeWt / 2;
                    pq.push({disc[adjNode], {adjNode, 1}});
                }
            }
            else
            {
                if (disc[adjNode] > cost + edgeWt)
                {
                    disc[adjNode] = cost + edgeWt;
                    pq.push({disc[adjNode], {adjNode, 1}});
                }
            }
        }
    }

    cout << disc[n];
    return 0;
}