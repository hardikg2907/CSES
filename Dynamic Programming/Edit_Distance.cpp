#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    cout << "/";
    for (int j = 0; j < m; j++)
        cout << " " << t[j];
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = 1 + dp[i][j];
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            cout << dp[i + 1][j + 1] << " ";
        }
        cout << endl;
    }

    cout << m - dp[n][m];

    return 0;
}