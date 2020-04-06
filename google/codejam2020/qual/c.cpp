#include<bits/stdc++.h>
using namespace std;

void solve(int test){
    int n,ind=0; char ans[10000];
    scanf("%d",&n);
    ans[n]='\0';
    vector<pair<pair<int,int>,int>> a(n);
    for(auto &i: a)scanf("%d%d",&i.first.first,&i.first.second),i.second=ind++;
    pair<int,int> c(-1,-1),j(-1,-1);
    sort(a.begin(),a.end());
    for(auto &i: a){
        if(c.second <= i.first.first)c = i.first,ans[i.second]='C';
        else if(j.second <= i.first.first)j = i.first,ans[i.second]='J';
        else {
            printf("Case #%d: IMPOSSIBLE\n",test);
            return;
        }
    }
    printf("Case #%d: %s\n",test,ans);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; ++i)solve(i+1);
    return 0;
}