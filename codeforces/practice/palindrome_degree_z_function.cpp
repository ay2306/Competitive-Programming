//https://codeforces.com/contest/7/problem/D
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin >> s;
    t = s;
    reverse(s.begin(),s.end());
    t = t + "$" + s;
    vector<int> dp(s.size(),0),z(t.size(),0);
    for(int i = 1, l = 0, r = 0; i < t.size(); ++i){
        if(i <= r)z[i] = min(r-i+1,z[i-l]);
        while(i+z[i] < (int)t.size() && t[i+z[i]] == t[z[i]])z[i]++;
        if(i + z[i] - 1 > r)l = i, r = z[i]+i-1;
    }
    dp[0] = 1;
    for(int i = 1; i < (int)s.size(); ++i){
        if(z[(int)t.size()-1-i] == i+1)dp[i] = dp[(i-1)/2]+1;
    }
    int res = accumulate(dp.begin(),dp.end(),0);
    return printf("%d",res),0;
}