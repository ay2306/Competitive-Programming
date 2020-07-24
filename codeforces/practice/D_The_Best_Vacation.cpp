#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define int LL
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m, x;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> n >> x;

    vector<int> arr(n);
    vector<int> days = {0}, hugs = {0};
    loop(i, 0, n)
    {
        cin >> arr[i];
    }

    loop(i, 0, n)
    {
        days.push_back(days.back() + arr[i]);
        hugs.push_back(hugs.back() + ((arr[i] * (arr[i] + 1)) / 2));
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int end_month = i;
        int start_day = days[i] - x + 1;
        if (start_day <= 0)
            start_day += days[n];
        int start_month = lower_bound(days.begin(), days.end(), start_day) - days.begin();
        int res;
        if (start_month <= end_month)
        {
            res = hugs[end_month] - hugs[start_month];
            int days_in_start_month = x - (days[end_month] - days[start_month]);
            int end_day_in_start_month = arr[start_month-1];
            int start_day_in_start_month = end_day_in_start_month - days_in_start_month + 1;
            res += (end_day_in_start_month * (end_day_in_start_month + 1)) / 2 - (start_day_in_start_month * (start_day_in_start_month - 1)) / 2;
        }
        else
        {
            res = hugs[end_month] + (hugs[n] - hugs[start_month]);
            int days_in_start_month = x - (days[end_month] + days[n] - days[start_month]);
            int end_day_in_start_month = arr[start_month-1];
            int start_day_in_start_month = end_day_in_start_month - days_in_start_month + 1;
            res += (end_day_in_start_month * (end_day_in_start_month + 1)) / 2 - (start_day_in_start_month * (start_day_in_start_month - 1)) / 2;
        }
        ans = max(res, ans);
    }

    cout << ans << "\n";
    return 0;
}
