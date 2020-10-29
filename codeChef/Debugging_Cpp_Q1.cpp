#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

int main() {
    FIO;
    int t, n, k, i, j, x, cnt1, cnt2, tmp;
    string s;

    cin >> t;
    while (t--> 0) {
        cin >> n >> k;
        cin >> s;

        int disparity[n][n];

        for (i = 0; i < n; i++) {
            int frequency[26] = {0};

            for (j = i; j < n; j++) {
                int k;
                frequency[s[j] - 'a']++;
                cnt1 = 0;
                cnt2 = 50;
                for (k = 0; k <= 25; k++) {
                    cnt1 = max(cnt1, frequency[k]);
                    if (frequency[k] > 0)
                        cnt2 = min(cnt2, frequency[k]);
                }
                for (k = 0; k <= 25; k++)
                    if (frequency[k] == cnt1)
                        break;
                disparity[i][j] = k;

                for (k = 0; k <= 25; k++)
                    if (frequency[k] == cnt2)
                        break;

                disparity[i][j] -= k;
            }
        }
        
        int dp[k][n];

        for (i = 0; i < n; i++) {
            dp[0][i] = disparity[0][i];
        }

        for (i = 1; i < k; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                for (x = 0; x < j; x++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][x] + disparity[x + 1][j]);
                }
            }
        }
        cout << dp[k - 1][n - 1] << "\n";
    }
    return 0;
}
