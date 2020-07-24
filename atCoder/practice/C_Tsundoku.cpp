#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(int &i: a)cin >> i;
    for(int &i: b)cin >> i;
    int lo = 0, hi = n+m, ans = 0;
    while(lo <= hi){
        int sum = 0,mid = lo + hi >> 1;
        int i = min(mid,n)-1, j = mid - min(mid,n) - 1;
        for(int k = 0; k <= i; ++k)sum+=a[k];
        for(int k = 0; k <= j; ++k)sum+=b[k];
        bool pos = sum <= k;
        while(i >= 0 && j+1 < m && !pos){
            sum-=(a[i--]-b[++j]);
            pos = (sum <= k);
        }
        if(pos)ans=mid,lo=mid+1;
        else hi = mid-1;
    }
    return cout << ans << "\n",0;
}