#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,cur;
    scanf("%d%d%d",&n,&a,&b);
    map<int,int> m;
    vector<int> arr(n),mask(n),ans(n,-1),q;
    for(int i = 0; i < n; ++i){
        scanf("%d",&arr[i]);
        m[arr[i]] = i;
        if(m.count(a-arr[i]))mask[m[a-arr[i]]] |= 1,mask[i] |= 1;
        if(m.count(b-arr[i]))mask[m[b-arr[i]]] |= 2,mask[i] |= 2;
    }
    for(int i = 0; i < n; ++i){
        if(mask[i] == 0)return printf("NO"),0;
        if(mask[i] < 3)q.emplace_back(i);
    }
    if(a == b){
        cur = 1;
        for(int i = 0; i < n; ++i){
            if(~ans[i])continue;
            int x = a-arr[i];
            ans[i] = cur;
            ans[m[x]] = cur;
            cur = 3-cur;
        }
    }else{
        if(q.empty()){
            int x = a-arr[0];
            ans[0] = 1;
            ans[m[x]] = 1;
            x = b-x;
            mask[m[x]] ^= 1;
            q.emplace_back(m[x]);
        }
        while(q.size()){
            
        }
    }
    printf("YES\n");
    for(int i : ans)printf("%d ",i-1);
    return 0;
}