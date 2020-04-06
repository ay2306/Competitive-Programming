#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("inp","r",stdin);
    freopen("out","w",stdout);
    int t,a,n,sum=0,r=0,c=0;
    set<int> row[110],col[110];
    scanf("%d",&t);
    for(int test = 1; test <= t; ++test){
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%d",&a); 
                row[i].insert(a);
                col[j].insert(a);
                if(i==j)sum+=a;
            }
        }
        for(int i = 0; i < n; ++i){
            r+=((int)row[i].size()!=n),c+=((int)col[i].size()!=n);
            row[i].clear();
            col[i].clear();
        }
        printf("Case #%d: %d %d %d\n",test,sum,r,c);
        sum = 0, r = 0, c = 0;
        
    }
    return 0;
}