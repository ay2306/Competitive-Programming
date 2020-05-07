//https://codeforces.com/contest/1059/problem/B
#include<bits/stdc++.h>
using namespace std;

string a[1010],b[1010];
int main(){
    int n,m;
    cin >> n >> m;
    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};
    for(int i = 0; i < n; ++i)cin >> a[i],b[i] = string(m,'.');
    for(int i = 1; i+1 < n; ++i){
        for(int j = 1; j+1 < m; ++j){
            int cnt = 0;
            for(int k = 0; k < 8; ++k)cnt+=(a[i+dx[k]][j+dy[k]]=='#');
            if(cnt == 8)
                for(int k = 0; k < 8; ++k)b[i+dx[k]][j+dy[k]]='#';
        }
    }
    for(int i = 0; i < n; ++i)
        if(a[i] != b[i])return cout << "NO\n",0;
    return cout << "YES\n",0;
}