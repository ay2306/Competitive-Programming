#include<bits/stdc++.h>
using namespace std;
int a[200][200],n,m,k,ans,del;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)scanf("%d",&a[i][j]);
    for(int j = 0; j < m; ++j){
        int mx = 0, s = 0, one = 0, delone = 0;
        for(int i = 0; i < k; ++i)s+=a[i][j];
        mx = s;
        for(int i = k; i < n; ++i){
            s+=a[i][j]-a[i-k][j];
            one+=a[i-k][j];
            if(mx < s)mx=s,delone=one;
        }
        ans+=mx,del+=delone;
    }
    return printf("%d %d",ans,del),0;
}