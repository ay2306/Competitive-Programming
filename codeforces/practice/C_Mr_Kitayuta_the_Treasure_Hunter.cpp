#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> islands;
int n, d, p, mx = -1;

int helper(vector<vector<int>> &dp, int prev, int curr)
{
    if (curr <= 0 || curr > mx)
        return 0;
    if (dp[prev][curr] != -1)
        return dp[prev][curr];

    int ans = 0;
    if (islands.find(curr) != islands.end())
        ans += islands[curr];

    int l = curr - prev;
    int op1 = helper(dp, curr, curr + l - 1);
    int op2 = helper(dp, curr, curr + l);
    int op3 = helper(dp, curr, curr + l + 1);

    ans += max({op1, op2, op3});
    dp[prev][curr] = ans;
    return ans;
}

int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        mx = max(mx, p);
        islands[p]++;
    }
    vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, -1));
    cout << helper(dp, 0, d);
    return 0;
}