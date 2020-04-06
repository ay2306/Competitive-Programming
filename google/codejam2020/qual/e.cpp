#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n,k;
vector<vector<int>> a;
unordered_set<int> r[100],c[100];
int tr;
int p;

bool any_magic_square(int i, int j){
    if(i == n-1 && j == n)return tr==k;
    if(i < n-1 && j == n)j=0,i++;
    for(int ip = 1; ip <= n; ++ip){
        if(r[i].find(ip) != r[i].end())continue;
        if(c[j].find(ip) != c[j].end())continue;
        r[i].insert(ip);
        c[j].insert(ip);
        a[i][j] = ip;
        if(i == j)tr+=ip;
        if(any_magic_square(i,j+1))return true;
        if(i == j)tr-=ip;
        r[i].erase(ip);
        c[j].erase(ip);   
    }
    return false;
}

void solve(int test){
    tr = 0;
    loop(i,0,100){
        c[i].clear();
        r[i].clear();
    }   
    cin >> n >> k;
    p = n*(n+1);
    p>>=1;
    a.resize(n,vector<int>(n,0));
    if(any_magic_square(0,0)){
        printf("Case #%d: POSSIBLE\n",test);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)printf("%d ",a[i][j]);
            printf("\n");
        }
    }else{
        printf("Case #%d: IMPOSSIBLE\n",test);
    }
}
int main()
{
    int t;
    int i = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve(i);
    }

    return 0;
}
