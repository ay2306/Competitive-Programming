//https://codeforces.com/contest/1118/problem/F1
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;

vector<int> g[N];
int n,rsub[N],bsub[N],arr[N],a,b,blue,red,ans;

void dfs(int s = 1, int p = -1){
    bsub[s]=(arr[s] == 1);
    rsub[s]=(arr[s] == 2);
    for(int &i: g[s]){
        if(i == p)continue;
        dfs(i,s);
        bsub[s] += bsub[i];
        rsub[s] += rsub[i];
        if(bsub[i] == blue && rsub[i] == 0)ans++;
        if(bsub[i] == 0 && rsub[i] == red)ans++;
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&arr[i]);
        blue+=(arr[i] == 1);
        red+=(arr[i] == 2);
    }
    if(red == 0 || blue == 0)return printf("%d",n-1),0;
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs();
    return printf("%d",ans),0;
}