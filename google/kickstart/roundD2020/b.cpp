#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL

void solve()
{
    int k, current, last, i;
    cin >> k;
    int ans = 1e9;
    vector<int> notes(k);
    for (auto &i : notes)
        cin >> i;

    vector<vector<int>> memo(k, vector<int>(5, 1e9));
    for (int i = 1; i <= 4; i++)
    {
        memo[0][i] = 0;
    }

    for (i = 1; i < k; i++)
    {
        //    (i-1) > (i)
        //note last > current
        if (notes[i] < notes[i - 1])
        {
            for (current = 1; current <= 4; current++)
            {
                //breaking rule - last value is lesser or equal
                for (last = 1; last <= current; last++)
                    memo[i][current] = min(memo[i][current], memo[i - 1][last] + 1);

                //okay - last value is greater than current  value
                for (last = current + 1; last <= 4; last++)
                    memo[i][current] = min(memo[i][current], memo[i - 1][last]);
            }
        }
        else if (notes[i] > notes[i - 1])
        {
            for (current = 1; current <= 4; current++)
            {
                //breaking - last value is greater than current  value
                for (last = current; last <= 4; last++)
                    memo[i][current] = min(memo[i][current], memo[i - 1][last] + 1);

                //okay rule - last value is lesser
                for (last = 1; last < current; last++)
                    memo[i][current] = min(memo[i][current], memo[i - 1][last]);
            }
        }
        else
        {
            for (current = 1; current <= 4; current++)
            {
                //okay - last value == current  value
                memo[i][current] = min(memo[i][current], memo[i - 1][current]);

                //breaking - last value is lesser than current  value
                for (last = 1; last < current; last++)
                    memo[i][current] = min(memo[i][current], memo[i - 1][last] + 1);

                //breaking - last value is greater than current  value
                for (last = current + 1; last <= 4; last++)
                    memo[i][current] = min(memo[i][current], memo[i - 1][last] + 1);
            }
        }

        if (i == k - 1)
        {
            for (int j = 1; j <= 4; j++)
                ans = min(ans, memo[i][j]);
        }
    }

    cout << ans << endl;
}

signed main()
{
    int t, i = 1;
    cin >> t;

    while (t--)
    {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }

    return 0;
}