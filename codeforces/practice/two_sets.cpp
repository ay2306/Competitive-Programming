//https://codeforces.com/problemset/problem/468/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
int p[N],arr[N],mask[N],pmask[N];
map<int,int> ind;
int fp(int x){return p[x]==x?x:p[x]=fp(p[x]);}
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i)cin >> arr[i],ind[arr[i]]=i,p[i]=i,pmask[i]=3;
    for(int i = 0; i < n; ++i){
        if(ind.count(a-arr[i]))p[fp(ind[a-arr[i]])]=fp(i),mask[i]|=2;
        if(ind.count(b-arr[i]))p[fp(ind[b-arr[i]])]=fp(i),mask[i]|=1;
    }
    for(int i = 0; i < n; ++i)pmask[fp(i)]&=mask[i];
    for(int i = 0; i < n; ++i)if(pmask[i] == 0){printf("NO\n");return 0;}
    printf("YES\n");
    for(int i = 0; i < n; ++i)printf("%d ",pmask[fp(i)]&1);
    return 0;
}