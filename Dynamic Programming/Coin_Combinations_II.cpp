#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (ind == arr.size())
    {
        return sum == 0;
    }

    int notPick = f(ind + 1, sum, arr, dp);
    int pick = 0;
    if (arr[ind] <= sum)
        pick = f(ind, sum - arr[ind], arr, dp);

    return dp[ind][sum] = (pick + notPick) % mod;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[n][0] = 1;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int sum = 0; sum <= x; sum++)
        {
            int notPick = dp[ind + 1][sum];
            int pick = 0;
            if (arr[ind] <= sum)
                pick = dp[ind][sum - arr[ind]];
            dp[ind][sum] = (pick + notPick) % mod;
        }
    }
    cout << dp[0][x];

    return 0;
}