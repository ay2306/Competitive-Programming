#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    scanf("%d",&n);
    int prv = 0, row = 0, lst = -1;
    vector<pair<int,int>> ans;
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a);
        if(a == 0)continue;
        if(a == 2 && lst == 2)return printf("-1"),0;
        if(prv == 0)row++;
        ans.emplace_back(row,i);
        prv--;
        if(prv == 1)
            ans.emplace_back(++row,i);
        prv = a-1;
        lst = a;
    }
    if(prv)return printf("-1\n"),0;
    for(auto [x,y]: ans){
        if(x < 1 || x > n || y < 1 || y > n)return printf("-1\n"),0;
    }
    printf("%d\n",ans.size());
    for(auto [x,y]: ans)printf("%d %d\n",x,y);
    return 0;
}