#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define loop(i, a, b) for (LL i = a; i < b; i++)
LL n, m;
LL movex[] = {0, 0, 1, -1};
LL movey[] = {1, -1, 0, 0};

LL f(LL x, LL b)
{
    LL k = b;
    int r = 0;
    while(k){
        k/=2;
        r++;
    } 
    return (x << r) + b;
}

signed main()
{
    static const LL _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL t = 1;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<LL> a(n);
        for (auto &i : a)
        {
            cin >> i;
        }
        LL ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                LL cur = abs(f(a[i], a[j]) - f(a[j], a[i]));
                ans = max(cur, ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
