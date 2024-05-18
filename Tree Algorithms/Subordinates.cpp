#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

void solve(int src, int par, vector<int> &ans, vector<int> tree[])
{
    int subords = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {
            solve(child, src, ans, tree);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}

int main()
{
    int n;
    cin >> n;
    vector<int> employees(n, 0);
    vector<int> tree[n + 1];
    int x;
    for (int i = 2; i < n + 1; i++)
    {
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    vector<int> ans(n + 1, 0);
    solve(1, 0, ans, tree);
    for (int i = 1; i < n + 1; i++)
        cout << ans[i] << " ";

    return 0;
}