#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 0,n;
        string s;
        cin >> n >> s;
        vector<int> d1(n),d2(n);
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while(i-k >= 0 && i+k < n && s[i-k] == s[i+k])k++;
            d1[i] = k--;
            if(i+k > r)l = i - k, r = i + k;
            ans += d1[i];
        }
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while(i-k-1 >= 0 && i+k < n && s[i-k-1] == s[i+k])k++;
            d2[i] = k--;
            if(i+k > r)l = i - k - 1, r = i + k;
            ans += d2[i];
        }
        // for(char i : s)cout << i << " ";
        // cout << "\n";
        // for(int i : d1)cout << i << " ";
        // cout << "\n";
        // for(int i : d2)cout << i << " ";
        // cout << "\n";
        cout << ans-n << "\n";
    }
    return 0;
}