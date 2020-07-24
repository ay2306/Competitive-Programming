#include<bits/stdc++.h>
using namespace std;
int nxt[10100][26];
char s[10100],t[1010100];
int main(){
    cin >> (s+1) >> (t+1);
    int n = strlen(s+1);
    int m = strlen(t+1);
    memset(nxt,-1,sizeof(nxt));
    char lst = s[n];
    for(int i = n-1; i >= 0; --i){
        for(int j = 0; j < 26; ++j)nxt[i][j]=nxt[i+1][j];
        nxt[i][lst-'a']=i+1;
        lst=s[i];
    }
    int cur = 0,ans = 0;
    for(int i = 1; i <= m; ){
        if(!cur && nxt[0][t[i]-'a'] == -1)return printf("-1"),0;
        ans += !cur;
        if(~nxt[cur][t[i]-'a'])cur = nxt[cur][t[i]-'a'],i++;
        else cur = 0;
    }
    return printf("%d",ans),0;
}