#include<bits/stdc++.h>
#define int long long
using namespace std;

int kadane(vector<int> &a){
    int mx = 0, s = 0;
    for(int i : a){
        s+=i;
        s = max(s,0LL);
        mx = max(mx,s);
    }
    return mx;
}

signed main(){
    int n;
    scanf("%lld",&n);
    vector<int> a(n),arr;
    for(int &i: a)scanf("%lld",&i);
    for(int i = 1; i < n; ++i)arr.emplace_back(abs(a[i]-a[i-1]));
    n--;
    for(int i = 0; i < n; i+=2)arr[i]*=-1;
    int ans = kadane(arr);
    for(int i = 0; i < n; i+=2)arr[i]*=-1;
    for(int i = 1; i < n; i+=2)arr[i]*=-1;
    ans = max(ans,kadane(arr));
    printf("%lld\n",ans);
    return 0;
}