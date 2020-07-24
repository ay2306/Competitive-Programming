#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; ++i){
            scanf("%d",&a[i].first);
            a[i].second = i;
        }
        sort(a.begin(),a.end());
        int mn = INT_MAX, mx = INT_MIN;
        bool valid = false;
        for(auto i: a){
            if(mn < i.second && mx > i.second){
                printf("YES\n%d %d %d\n",mn+1,i.second+1,mx+1);
                valid = true;
                break;
            }
            mn = min(mn,i.second);
            mx = max(mx,i.second);
        }
        if(!valid)printf("NO\n");
    }
    return 0;
}