#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,q,x;
        scanf("%lld%lld",&n,&q);
        vector<int> arr(n),pref(n),pos;
        for(int &x: arr)scanf("%lld",&x);
        sort(arr.begin(),arr.end());
        for(int i = 0; i < n; ++i)pref[i] = arr[i] + (i ? pref[i-1] : 0);
        function<void(int,int)> f = [&](int l, int r){
            if(r < l)return;
            pos.emplace_back(pref[r] - (l ? pref[l-1] : 0));
            if(arr[l] == arr[r])return;
            int mid = arr[l] + arr[r] >> 1;
            int r1 = upper_bound(arr.begin(),arr.end(),mid) - arr.begin();
            f(l,r1-1);
            f(r1,r);
        };
        f(0,n-1);
        sort(pos.begin(),pos.end());
        while(q--){
            scanf("%lld",&x);
            printf(binary_search(pos.begin(),pos.end(),x) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}