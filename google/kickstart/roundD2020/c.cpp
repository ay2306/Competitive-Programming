#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F idx
#define S val
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define int LL
const int maxn = 1e5 + 1;

struct node
{
    int idx;
    int val;
    node(int i, int v) : idx(i), val(v) {}
};

void solve()
{
    int n, q, ans = 0;
    cin >> n >> q;
    vector<int> diff(n);

    for (int i = 1; i < n; i++)
        cin >> diff[i];

    for (int i = 0; i < q; i++)
    {
        int s, k;
        cin >> s >> k;
        struct node prv(0, 0);
        struct node nxt(0, 0);

        prv.idx = s - 1;
        prv.val = s - 1 > 0 ? diff[s - 1] : 1e9;

        nxt.idx = s + 1;
        nxt.val = s + 1, s < n ? diff[s] : 1e9;

        for (int i = 1; i < k; i++)
        {
            if (prv.val > nxt.val)
            {
                s = nxt.idx;
                nxt.idx = s + 1;
                nxt.val = s < n ? diff[s] : (int)1e9;
            }
            else
            {
                s = prv.idx;
                prv.idx = s - 1;
                prv.val = s > 1 ? diff[s - 1] : (int)1e9;
            }
        }

        cout << s << " ";
    }

    cout << "\n";
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
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