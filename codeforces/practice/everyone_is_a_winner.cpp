//https://codeforces.com/contest/1263/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        set<int> ans;
        for(i = 1; i*i <= n; ++i)ans.emplace(n/i);
        for(i = 1; i*i < n; ++i)
            if(n/(n/i) == i)ans.emplace(i);
        ans.emplace(0);
        printf("%d\n",(int)ans.size());
        for(const int &i: ans)printf("%d ",i);
        printf("\n");
    }
    return 0;
}