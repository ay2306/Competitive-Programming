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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<LL> a(n);
        unordered_set<LL> st;
        bool possible = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (st.find(a[i]) != st.end())
            {
                possible = 0;
            }
            st.emplace(a[i]);
        }

        if (!possible)
        {
            cout << "NO\n";
            continue;
        }
		st.clear();
        LL x = 0;
        for (int i = 0; i < n; i++)
        {
            x |= a[i];
            if (st.find(x) != st.end())
            {
                possible = 0;
                break;
            }
            st.insert(x);
        }

        if (!possible)
        {
            cout << "NO\n";
            continue;
        }

        st.clear();
        x = a[n - 1];
        // for(int i = 0; i < n; i++){
        //     st.insert(a[i]);
        // }
        for (int i = n - 1; i >= 0; i--)
        {
            x |= a[i];
            if (st.find(x) != st.end())
            {
                possible = 0;
                break;
            }
            st.insert(x);
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}