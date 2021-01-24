#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10, sz = 340;

int n,m,ans,l,r,t,k;
int f[sz][N];
deque<int> q[sz];
int arr[N];

void init(){
    for(int i = 0, id = 0; i < n; i+=sz, id++){
        for(int j = i; j < i + sz && j < n; ++j){
            f[id][arr[j]]++;
            q[id].emplace_back(arr[j]);
        }
    }
}

void shift(int l, int r){
    int t = q[r/sz][r%sz];
    f[r/sz][t]--;
    f[l/sz][t]++;
    q[r/sz].erase(q[r/sz].begin()+r%sz);
    int cur = t;
    for(int id = l/sz; id < r/sz; ++id){
        t = q[id].back();
        q[id].pop_back();
        f[id][t]--;
        q[id+1].emplace_front(t);
        f[id+1][t]++;
    }
    q[l/sz].insert(q[l/sz].begin()+l%sz,cur);
}

int get(int l, int r, int k){
    int ans = 0;
    while(l%sz && l < r)ans+=q[l/sz][l%sz]==k,l++;
    while(l/sz < r/sz)ans+=f[l/sz][k],l+=sz;
    while(l <= r)ans+=q[l/sz][l%sz]==k,l++;
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d",arr+i);
    scanf("%d",&m);
    init();
    while(m--){
        scanf("%d%d%d",&t,&l,&r);
        l = (ans+l-1)%n;
        r = (ans+r-1)%n;
        if(l > r)swap(l,r);
        if(t == 1)shift(l,r);
        else{
            scanf("%d",&k);
            k = (k+ans-1)%n+1;
            ans = get(l,r,k);
            printf("%d\n",ans);
        }
    }
    return 0;
}