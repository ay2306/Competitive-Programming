#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,int>> arr(2*n);
        for(int i = 0; i < 2*n; ++i){
            scanf("%d",&arr[i].first);
            arr[i].second = i;
        }
        sort(arr.begin(),arr.end());
        int cur = 2*n;
        vector<int> a;
        while(arr.size()){
            if(cur > arr.back().second)a.emplace_back(cur-arr.back().second);
            cur = min(cur,arr.back().second);
            arr.pop_back();
        }
        vector<int> dp(n+1,false);
        dp[0] = true;
        for(auto i: a){
            vector<int> temp(dp.begin(),dp.end());
            for(int j = i; j <= n; ++j)
                if(dp[j-i])temp[j] = true;
            dp = temp;
        }
        if(dp[n])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}