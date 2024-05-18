#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

long long diceCombinations(int n, int x, vector<int> &a)
{
    vector<long long> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= i)
            {
                dp[i] = (dp[i] + dp[i - a[j]]);
                if (dp[i] >= mod)
                    dp[i] -= mod;
            }
        }
    }

    return dp[x] % mod;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << diceCombinations(n, x, a) % mod;

    return 0;
}