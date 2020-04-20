//https://codeforces.com/contest/501/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,a,b;
int deg[N],s[N];
queue<int> q;
vector<pair<int,int>> ans;
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d%d",deg+i,s+i);
    for(int i = 0; i < n; ++i)if(deg[i] == 1)q.push(i);
    while(!q.empty()){
        if(deg[q.front()] == 0){q.pop();continue;}
        ans.emplace_back(q.front(),s[q.front()]);
        s[s[q.front()]]^=q.front();
        deg[s[q.front()]]--;
        if(deg[s[q.front()]] == 1)q.push(s[q.front()]);
        q.pop();
    }
    printf("%d\n",(int)ans.size());
    for(auto &i : ans)printf("%d %d\n",i.first,i.second);
    return 0;
}