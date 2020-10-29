#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int A = INT_MAX, B = INT_MAX;
        long long ans = 0;
        vector<int> a(n),b(n);
        for(int &i: a)scanf("%d",&i);
        for(int &i: b)scanf("%d",&i);
        A = *min_element(a.begin(),a.end());
        B = *min_element(b.begin(),b.end());
        for(int i = 0 ; i < n; ++i){
            ans += max(a[i]-A,b[i]-B);
        }
        printf("%lld\n",ans);
    }
    return 0;
}