#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{

    LL n, bad = 0;
    cin >> n;
    vector<LL> a(n), prefix(n + 1, 0);
    unordered_map<LL, LL> mp; //
    cin >> a[0];
    for (LL i = 1; i < n; i++)
    {
        cin >> a[i];
        prefix[i] += a[i - 1] + prefix[i - 1];
    }
    prefix[n] = a[n - 1] + prefix[n - 1];

    for (LL i = 0; i <= n; i++)
    {
        if (mp.find(prefix[i]) != mp.end())
            bad += 1 + n - i;
            
        mp[prefix[i]] = i;
    }

    LL total = n * (n + 1) / 2;
    cout << total - bad << "\n";

    return 0;
}
