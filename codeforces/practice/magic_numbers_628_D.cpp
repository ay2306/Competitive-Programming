//https://codeforces.com/problemset/problem/628/D
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7, N = 2010;
int m,d,n;
vector<int> num;
ll dp[N][N][2], power[N];

ll cal(int pos = 0, int rem = 0, int f = 0){
    if(pos == num.size())return rem == 0;
    ll &res = dp[pos][rem][f];
    if(~res)return res;
    res = 0;
    int lst = f == 0 ? num[pos] : 9;
    if(pos % 2 && d > lst)return 0;
    if(pos % 2)res = cal(pos+1,(rem+d*power[n-1-pos]%m)%m,(f || (d < lst)));
    else{
        for(int i = 0; i <= lst; ++i)
            if(i != d)
                res = (res + cal(pos+1,(rem+i*power[n-1-pos]%m)%m,(f || (i < lst))))%mod;
    }
    return res;
}

int main(){
    cin >> m >> d;
    power[0] = 1;
    for(int i = 1; i < N; ++i)power[i] = power[i-1]*10%m;
    string a,b;
    cin >> a >> b;
    for(char i: b)num.emplace_back(i-'0');
    memset(dp,-1,sizeof(dp));
    n = num.size();
    ll res = cal();
    cout << res << "\n";
    num.clear();
    for(char i: a)num.emplace_back(i-'0');
    memset(dp,-1,sizeof(dp));
    for(int i = num.size()-1; i >= 0; --i){
        if(num[i] == 0)num[i] = 9;
        else{
            num[i]--;
            break;
        }
    }
    n = num.size();
    ll s2 = cal();
    res = (res-s2+mod)%mod;
    return cout << res << "\n",0;
}