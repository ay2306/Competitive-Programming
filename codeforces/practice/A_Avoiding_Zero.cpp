#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s = 0;
    scanf("%d",&n);
    vector<int> a(n);
    for(int &i: a)scanf("%d",&i);
    s = accumulate(a.begin(),a.end(),0);
    if(s == 0)return void(printf("NO\n"));
    if(s < 0)sort(a.begin(),a.end());
    if(s > 0)sort(a.rbegin(),a.rend());
    printf("YES\n");
    for(int i: a)printf("%d ",i);
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}