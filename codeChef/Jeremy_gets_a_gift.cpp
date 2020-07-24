#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
char s[N];
char ans[N];
int vis[N];
int n,m;

vector<pair<int,int>> q[2];

int readInt(){
	char c;
	int x = 0;
	while((c = getchar()) >= '0' && c <= '9')x = x*10 + c - '0';
	return x;
}


int main(){
    int t = readInt();
    while(t--){
        n = readInt();
        m = readInt();
        int kk = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)s[kk++]=getchar();
            getchar();
        }
        q[0] = vector<pair<int,int>> ();
        q[1] = vector<pair<int,int>> ();
        q[0].emplace_back(0,0);
        int cur = 0;
        int sz = 1;
        ans[0] = s[0];
        while(q[cur].size()){
            int i,j;
            tie(i,j) = q[cur].front();
            q[cur].erase(q[cur].begin());
            if(sz == i+j+1)ans[i+j+1]='z',sz++;
            if(i+1 < n && s[(i+1)*m+j] != '#'){
                if(ans[i+j+1] > s[(i+1)*m+j]){
                    q[cur^1] = vector<pair<int,int>> ();
                    ans[i+j+1] = s[(i+1)*m+j];
                    q[cur^1].emplace_back(i+1,j);
                
                }else if(ans[i+j+1] == s[(i+1)*m+j]){
                    ans[i+j+1] = s[(i+1)*m+j];
                    q[cur^1].emplace_back(i+1,j);
                }
            }
            if(j+1 < m && s[i*m+j+1] != '#'){
                if(ans[i+j+1] > s[i*m+j+1]){
                    q[cur^1] = vector<pair<int,int>> ();
                    ans[i+j+1] = s[i*m+j+1];
                    q[cur^1].emplace_back(i,j+1);
                }else if(ans[i+j+1] == s[i*m+j+1]){
                    ans[i+j+1] = s[i*m+j+1];
                    q[cur^1].emplace_back(i,j+1);
                }
            }
            if(q[cur].size() == 0)cur^=1;
        }
        ans[n+m-1] = '\0';
        for(int i = 0; i < n+m-1; ++i)putchar(ans[i]);
        putchar('\n');
    }
    return 0;
}