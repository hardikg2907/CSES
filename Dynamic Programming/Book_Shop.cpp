#include <bits/stdc++.h>
using namespace std;

int f(int sum, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp)
{

    for (int ind = prices.size() - 1; ind >= 0; ind--)
    {
        for (int x = 0; x <= sum; x++)
        {
            int pick = 0;
            if (prices[ind] <= x)
                pick = pages[ind] + dp[ind + 1][x - prices[ind]];
            int notPick = dp[ind + 1][x];
            dp[ind][x] = max(pick, notPick);
        }
    }

    return dp[0][sum];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << f(x, prices, pages, dp);

    return 0;
}