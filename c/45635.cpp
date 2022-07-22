#include<bits/stdc++.h>
using namespace std;

const int N =2e5+5;
vector<int>g[N];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
        int ans = N;
        for (int i = 1; i <= n; i++)
        {
            if (g[i].empty())
                continue;
            int tmp = 0;
            for (int j = 0; j < g[i].size(); j++)
            {
                if (j == 0 && g[i][j] != 1)
                    tmp++;
                if (j == g[i].size() - 1 && g[i][j] != n)
                    tmp++;
                if (j > 0 && g[i][j] != g[i][j - 1] + 1)
                    tmp++;
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
