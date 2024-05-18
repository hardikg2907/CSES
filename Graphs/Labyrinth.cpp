#include <bits/stdc++.h>
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

int delrow[4] = {0, 1, 0, -1};
int delcol[4] = {1, 0, -1, 0};
char dirs[4] = {'R', 'D', 'L', 'U'};

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 0));
    queue<pair<pair<int, string>, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                q.push({{0, ""}, {i, j}});
                grid[i][j] = '#';
                // break;
            }
        }
    }

    bool flag = false;
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int row = front.second.first;
        int col = front.second.second;
        string curPath = front.first.second;
        int curDist = front.first.first;

        for (int i = 0; i < 4; i++)
        {
            int newr = row + delrow[i];
            int newc = col + delcol[i];
            if (newr < n && newr >= 0 && newc < m && newc >= 0)
            {
                if (grid[newr][newc] == '.')
                {
                    q.push({{curDist + 1, curPath + dirs[i]}, {newr, newc}});
                    grid[newr][newc] = '#';
                }
                else if (grid[newr][newc] == 'B')
                {
                    flag = true;
                    cout << "YES\n";
                    cout << curDist + 1 << endl;
                    cout << curPath + dirs[i];
                    break;
                }
            }
        }
        if (flag)
            break;
    }

    if (!flag)
        cout << "NO";

    return 0;
}