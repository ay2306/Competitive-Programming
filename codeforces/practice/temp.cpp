#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int a[1000007];
int ans[1000007];
bool can[1000007];
vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i<n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
const int MOD = 1000000007;
int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int>z = z_function(s);
    z[0] = s.length();
    for (int i = 1; i <= s.length(); i++)
    {
        if (z[i - 1] + i - 1 >= s.length()) can[i] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    int rpos = 1;
    bool ok = true;
    for (int i = 1; i <= m; i++)
    {
        if (ans[a[i]] == 0)
        {
            for (int j = a[i]; j <= a[i] + s.length() - 1; j++)
            {
                ans[j] = j - a[i] + 1;
            }
            rpos = a[i] + s.length();
        }
        else
        {
            //int can = z[ans[a[i]] - 1];
            //if (ans[a[i]] + can - 1 < s.length()) ok = false;     
            if (!can[ans[a[i]]]) ok = false;
            for (int j = rpos; j <= a[i] + s.length() - 1; j++)
            {
                ans[j] = j - a[i] + 1;
            }
            rpos = a[i] + s.length();
        }
    }
    long long ansn = 1;
    if (!ok)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            ansn = (ansn * 26) % MOD;
        }
    }
    cout << ansn << endl;
}