#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
            }
        }
    }

    cout << (dp[x] < 1e9 ? dp[x] : -1) << endl;
    return 0;
}