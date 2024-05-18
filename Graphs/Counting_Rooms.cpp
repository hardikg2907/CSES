#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int mod = 1e9 + 7;

void dfs(int row, int col, vector<vector<int>> &grid, int &n, int &m)
{
    int delrow[4] = {0, 1, 0, -1};
    int delcol[4] = {1, 0, -1, 0};
    grid[row][col] = 0;

    for (int i = 0; i < 4; i++)
    {
        int newr = row + delrow[i];
        int newc = col + delcol[i];
        if (newr < n && newr >= 0 && newc < m && newc >= 0 && grid[newr][newc])
            dfs(newr, newc, grid, n, m);
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '.')
                grid[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
            {
                ans++;
                dfs(i, j, grid, n, m);
            }
        }
    }

    cout << ans;

    return 0;
}