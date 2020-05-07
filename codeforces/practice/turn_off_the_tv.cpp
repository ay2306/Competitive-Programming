//https://codeforces.com/contest/863/problem/E
#include<bits/stdc++.h>
using namespace std;
const int N = 7e5;
int main(){
    int n,l,r,t=0,cnt[N],pref[N];
    scanf("%d",&n);
    map<int,int> m;
    vector<pair<int,int>> a(n);
    for(auto &[x,y]: a)scanf("%d%d",&x,&y);
    for(auto &[x,y]: a)m[x]++,m[y]++,m[x-1]++;
    for(auto &i:m)i.second = ++t;
    for(auto &[x,y]: a){
        x = m[x],y = m[y];
        cnt[x]++, cnt[y+1]--;
    }
    for(int i = 1; i < N; ++i)cnt[i]+=cnt[i-1];
    for(int i = 1; i < N; ++i)pref[i]+=pref[i-1]+(cnt[i] == 1);
    for(int i = 0; i < n; ++i)if(pref[a[i].second]-pref[a[i].first-1] == 0)return printf("%d",i+1),0;
    return printf("-1"),0;
}