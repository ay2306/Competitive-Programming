#include<bits/stdc++.h>
#define loop(a,b,c) for(int a = b; a < c; ++a)
using namespace std;
int n,m,b,c;
const int inf = 1e9;
vector<vector<int>> a;
bool pos(int mid){
    vector<int> mask(1 << m, -1);
    loop(i,0,n){
        int cur = 0;
        loop(j,0,m){
            if(a[i][j] >= mid)cur^=(1<<j);
        }
        mask[cur] = i;
    }
    if(mask[(1<<m)-1] != -1){
        b = c = mask[(1 << m) - 1];
        return true;
    }
    loop(i,0,(1<<m)){
        loop(j,0,(1<<m)){
            if(mask[i]!=-1 && mask[j]!=-1 && ((i|j) == (1 << m)-1)){
                b = mask[i];
                c = mask[j];
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    a.resize(n,vector<int>(m));
    loop(i,0,n)loop(j,0,m)scanf("%d",&a[i][j]);
    int lo = 0;
    int hi = inf+100;
    while(lo <= hi){
        int mid = lo + hi >> 1;
        if(pos(mid)){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    printf("%d %d",b+1,c+1);
    return 0;
}