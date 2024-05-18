#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i < n - 1 && s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        maxi = max(maxi, count);
    }

    cout << maxi;

    return 0;
}