#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int f(int i, int j, int n, vector<vector<char>> &grid, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = 0, down = 0;
    if (j < n - 1 && grid[i][j + 1] == '.')
        right = f(i, j + 1, n, grid, dp);
    if (i < n - 1 && grid[i + 1][j] == '.')
        down = f(i + 1, j, n, grid, dp);

    return dp[i][j] = (right + down) % mod;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    if (grid[0][0] == '.')
        cout << f(0, 0, n, grid, dp);
    else
        cout << 0;

    return 0;
}