#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int32_t main(){
    int n,q,a,b,f1,f2,l,r;
    cin >> n >> q >> f1 >> f2 >> a >> b;
    vector<int> x(n+10),p(n+10,0),f(n+10,0);
    f[1] = f1;
    f[2] = f2;
    for(int i = 3; i < n+10; ++i)f[i] = (f[i-1]*b%mod + f[i-2]*a%mod)%mod;
    // for(int i = 1; i <= n; ++i)cout << f[i] << " ";
    // cout << "\n" << a << " " << b << endl;
    for(int i = 1; i <= n; ++i)cin >> x[i];
    while(q--){
        cin >> l >> r;
        p[l]=(p[l]+f1)%mod;
        // cout << l << " " << r << " " << p[l] << "\n";
        if(l!=r){
            p[l+1]=(p[l+1]+f2-b*f1%mod+mod)%mod;
            p[r+1]=(p[r+1]-f[r-l+2]+mod)%mod;
            p[r+2]=(p[r+2]-a*f[r-l+1]%mod+mod)%mod;
        }else{
            p[l+1]=(p[l+1]-b*f1%mod+mod)%mod;
            p[l+2]=(p[l+2]-a*f1%mod+mod)%mod;
        }
        // for(int i = 1; i <= n; ++i)cout << p[i] << " ";
        // cout << "\n";
    }
    for(int i = 2; i <= n; ++i)p[i] = (p[i] + p[i-1]*b%mod + p[i-2]*a%mod)%mod;
    for(int i = 1; i <= n; ++i)x[i] = (x[i] + p[i])%mod;
    for(int i = 1; i <= n; ++i)cout << x[i] << " ";
    return 0;
}