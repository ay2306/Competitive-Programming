#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int N = 1e6+10;
int power(int a, int n){
    if(a == 1 || n == 0)return 1LL;
    if(n == 1)return a%mod;
    int p = power(a,n/2);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

int f[N],inv[N];

int32_t main(){
    string a;
    cin >> a;
    int n = a.size()+5;
    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= n; ++i){
        f[i] = i*f[i-1]%mod;
        inv[i] = inv[i-1]*power(i,mod-2)%mod;
    }
    map<char,int> m;
    for(char i: a)m[i]++;
    string ans = "";
    char c = 'z'+1;
    for(auto &i: m){
        ans+=string(i.second/2,i.first);
        if(i.second & 1)c = min(i.first,c);
    }
    string res = ans;
    if(c != 'z'+1)res += c;
    reverse(ans.begin(),ans.end());
    res += ans;
    int cnt = 1;
    for(char i: res){
        cnt = cnt * m[i] % mod;
        m[i]--;
    }
    cnt = cnt * f[a.size() - res.size()] % mod;
    cnt = cnt * inv[a.size()] % mod;
    cout << cnt << "\n";
    return 0;
}