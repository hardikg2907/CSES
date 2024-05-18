#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int steps = 0;
    while (n)
    {
        steps++;
        int copy = n;
        int maxi = 0;
        while (copy)
        {
            maxi = max(maxi, copy % 10);
            copy /= 10;
        }
        n -= maxi;
    }

    cout << steps;

    return 0;
}