#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> a(n);
    for(int &i: a)scanf("%d",&i);
    if(is_sorted(a.begin(),a.end()))return void(printf("0\n"));
    int ans = INT_MAX;
    for(int remove = 0; remove < n; ++remove){
        vector<int> b(a.begin(),a.end());
        b[remove] = x;
        sort(b.begin(),b.end());
        int res = 0, cur = x;
        for(int i = 0; i < n; ++i){
            if(a[i] == b[i])continue;
            if(b[i] != cur || a[i] < cur){
                res = INT_MAX;
                break;
            }
            res++;
            cur = a[i];
        }
        ans = min(ans,res);
    }
    if(ans == INT_MAX)ans = -1;
    printf("%d\n",ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}