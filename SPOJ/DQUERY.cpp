#include<bits/stdc++.h>
using namespace std;
const int K = 200, Q_LIMIT =2e5+10, A_LIMIT = 1e6+10, N_LIMIT = 3e4+10;

struct query{
    int l,r,ind;
    query(){}
    bool operator<(const query &rhs)const{
        if(l/K != rhs.l/K)return l < rhs.l;
        if(l/K&1)return r > rhs.r;
        return r < rhs.r;
    }
}q[Q_LIMIT];

int f[A_LIMIT],a[N_LIMIT], ans[Q_LIMIT], n, Q, curL = 1, curR = 0, res = 0;

void remove(int x){
    res-=f[a[x]]==1;
    f[a[x]]--;
}
void add(int x){
    res+=f[a[x]]==0;
    f[a[x]]++;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%d",a+i);
    scanf("%d",&Q);
    for(int i = 1; i <= Q; ++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].ind = i;
    sort(q+1,q+Q+1);
    curL = n, curR = n-1;
    for(int i = 1; i <= Q; ++i){
        int ind = q[i].ind, L = q[i].l, R = q[i].r;
        while(curL < L)remove(curL++);
        while(curL > L)add(--curL);
        while(curR < R)add(++curR);
        while(curR > R)remove(curR--);
        ans[ind] = res;
    }
    for(int i = 1; i <= Q; ++i)printf("%d\n",ans[i]);
    return 0;
}