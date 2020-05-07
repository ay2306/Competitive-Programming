#include<bits/stdc++.h>
#define ll long long 
#define pb emplace_back
#define mp make_pair
#define V vector
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define xx first
#define yy second
#define all(a) a.begin(),a.end()
#define loop(a,b,c) for(int a = b; a < c; ++a)
using namespace std;

const int N = 1e9;
const int mod = 1e9+7;
const long double pi = acos(-1.0);
int solve(){
    int n,k;
    cin >> n >> k;
    V<int> ans,a(n);
    loop(i,0,n)cin >> a[i];
    int s = 0,s1 = 0;
    for(int i = 0; i < k; ++i){
        s1 += a[i];
        ans.pb(a[i]);
    }
    s = s1;
    for(int i = k; i < n;){
        int j = ans.size();
        if(a[i] == ans[j-k])ans.pb(a[i++]);
        else ans.pb(ans[j-k]);
        if(ans.size() > 100001)return cout << -1 << "\n",0;
    }
    cout << ans.size() << "\n";
    for(int &i: ans)cout << i << " ";
    cout << "\n";
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}