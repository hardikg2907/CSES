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
stack<int> st;
vector<bool> stFlag;
bool dfs(int node)
{
    vis[node] = 1;
    st.push(node);
    stFlag[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it))
                return true;
        }
        if (stFlag[it])
        {
            st.push(it);
            return true;
        }
    }
    st.pop();
    stFlag[node] = false;
    return false;
}

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    stFlag.resize(n + 1);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
                break;
        }
    }

    if (st.size() == 0 || st.size() == 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    int temp = st.top();
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
        if (temp == ans.back() and ans.size() != 1)
            break;
    }
    if (ans.size() == 0 || ans.size() == 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int a : ans)
        cout << a << " ";

    return 0;
}