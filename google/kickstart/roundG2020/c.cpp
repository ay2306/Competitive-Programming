
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
#define int LL
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
#define int LL
int w, n;
vector<int> x;

multiset<int> leftBackward, leftForward, rightBackward, rightForward;
int leftBackwardSum = 0, leftForwardSum = 0, rightBackwardSum = 0, rightForwardSum = 0;

int calAns(int target)
{
    int ans = 0;

    ans += leftBackward.size() * (n - target) + leftBackwardSum;
    ans += abs((long long)(rightBackward.size() * (n + target) - rightBackwardSum));
    ans += abs((long long)(leftForward.size() * target - leftForwardSum));
    ans += abs((long long)(rightForward.size() * target - rightForwardSum));

    return ans;
}

//target = value jiske equal baaki sabko bana rahe hai
int helper(int target)
{
    int mnVal, gap, BackwardGap;
    while (1)
    {
        if (leftForward.empty())
            break;
        mnVal = *leftForward.begin();
        gap = abs(mnVal - target);
        BackwardGap = n - gap;
        if (BackwardGap > gap)
            break;
		auto iterator = leftForward.find(mnVal);
        leftForward.erase(iterator);
        leftBackward.emplace(mnVal);
        leftForwardSum -= mnVal;
        leftBackwardSum += mnVal;
    }

    while (1)
    {
        if (rightBackward.empty())
            break;
        mnVal = *rightBackward.begin();
        gap = abs(mnVal - target);
        BackwardGap = n - gap;
        if (gap > BackwardGap)
            break;
		auto iterator = rightBackward.find(mnVal);
        rightBackward.erase(iterator);
        rightForward.emplace(mnVal);
        rightBackwardSum -= mnVal;
        rightForwardSum += mnVal;
    }

    int ans = calAns(target);
	auto iterator = rightForward.find(target);
    rightForward.erase(iterator);
    leftForward.emplace(target);

    rightForwardSum -= target;
    leftForwardSum += target;

    return ans;
}

void cleaning()
{
    x.clear();
    leftBackward.clear();
    leftForward.clear();
    rightBackward.clear();
    rightForward.clear();
    leftBackwardSum = 0, leftForwardSum = 0, rightBackwardSum = 0, rightForwardSum = 0;
}

void solve()
{
    cleaning();
    cin >> w >> n;
    x.resize(w);
    for (auto &i : x)
        cin >> i;
    sort(x.begin(), x.end());
    int ans = LONG_LONG_MAX;
    for (auto val : x)
        rightBackwardSum += val, rightBackward.emplace(val);
    for (auto val : x)
        ans = min(ans, helper(val));
    cout << ans << "\n";
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