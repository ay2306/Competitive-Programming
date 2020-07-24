#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair
#define LL long long

#define pii pair<LL, LL>

LL n, m;

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<LL> a(n), b(m);
        LL x, k, y;
        LL l, r;
        vector<pii> segments;
        unordered_map<LL, LL> indices;
        cin >> x >> k >> y;
        for (LL i = 0; i < n; i++)
        {
            cin >> a[i];
            indices[a[i]] = i;
        }
        bool possible = 1;
        for (auto &i : b)
        {

            cin >> i;
            if (segments.size())
                l = segments.back().S;
            else
                l = -1;

            r = indices[i];
            segments.emplace_back(l, r);
            if (l > r)
            {
                possible = 0;
            }
        }

        if (segments.size())
            l = segments.back().S;
        else
            l = -1;
        r = n;
        segments.emplace_back(l, r);

        /* Impossible
        1. a aur b me order same hona chahiye warna impossible
        2. m > n , impossible
        3. m = n , but a != b => Impossible 
        */
        if (!possible || m > n || (m == n && a != b))
        {
            cout << -1 << "\n";
            continue;
        }
        if (m == n && a == b)
        {
            cout << 0 << "\n";
            continue;
        }

        // st,end - each segment to be removed
        // (i,j) me max_elt ya to bada ho A[i] ya A[j] se aur agar aisa nhi hai to j-i-1 >= k
        // aur dono hi nahi hai to ans = -1

        LL ans = 0;
        for (auto p : segments)
        {
            LL l = p.F;
            LL r = p.S;

            // cout << l << " " << r << "\n";
            LL len = r - l - 1;
            if (len <= 0)
                continue;
            LL mx = *max_element(a.begin() + l + 1, a.begin() + r);
            // cout << len << "\n";
            if (len % k == 0)
            {
                LL op1 = x * (len / k);
                LL op2 = LONG_LONG_MAX;
                LL op3 = LONG_LONG_MAX;
                if ((l >= 0 && a[l] > mx) || (r < n && a[r] > mx))
                {
                    op2 = len * y;
                }
                else
                {
                    op3 = x + y * (len - k);
                }

                ans += min(op1, (op2, op3));
            }
            else
            {
                LL op1 = LONG_LONG_MAX, op2 = LONG_LONG_MAX, op3 = LLONG_MAX;
                if (len < k)
                {
                    if ((l >= 0 || a[l] < mx) && (r >= n || a[r] < mx))
                    {
                        ans = -1;
                        break;
                    }
                    op2 = len * y;
                }
                else
                {
                    LL c1 = x * (len / k);
                    LL c2 = y * (len % k);
                    op1 = c1 + c2;
                    if ((l >= 0 && a[l] > mx) || (r < n && a[r] > mx))
                    {
                        op2 = len * y;
                    }
                    else
                    {
                        op3 = x + y * (len - k);
                    }
                }
                ans += min(op1, min(op2, op3));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
