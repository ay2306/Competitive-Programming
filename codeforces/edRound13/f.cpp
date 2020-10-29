#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int is_queries = -(1LL<<62);
struct Line {
    int m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_queries) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        int x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct CHT : public multiset<Line> { 
    void newStart(){
        clear();
    }
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m - x->m);
    }
    void add(int m, int b) {
        // cout << m << " " << b << "\n";
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    int query(int x) {
        if(empty())return LLONG_MIN;
        auto l = *lower_bound((Line) { x, is_queries });
        return l.m * x + l.b;
    }
};

const int N = 3e5+10;
CHT tree[N<<2];
int n;
int endPoint[N],t[N],A[N],B[N];
void update(int l, int r, pair<int,int> L, int node = 1, int start = 0, int end = n-1){
    if(l > end || r < start)return;
    if(l <= start && end <= r){
        // printf("added to range(%lld %lld) node = %lld\n",start,end,node);
        tree[node].add(L.first,L.second);
        return;
    }
    int mid = start + end >> 1;
    update(l, r, L, node << 1, start, mid);
    update(l, r, L, node << 1 | 1, mid+1, end);
}

int query(int idx, int x, int node = 1, int start = 0, int end = n-1){
    if(start > idx || end < idx || start > end)return LLONG_MIN;
    int ans = LLONG_MIN;
    if(!tree[node].empty()){
        int res = tree[node].query(x);
        ans = max(ans,res);
    }
    if(end - start <= 0){
        // printf("Searching for idx = %lld in range (%lld %lld) node = %lld | ",idx,start,end,node);
        // printf("ret1 = %lld\n",ans);
        return ans;
    }
    int mid = start + end >> 1;
    int p1 = query(idx, x , node << 1, start, mid);
    int p2 = query(idx, x,  node << 1 | 1, mid+1, end);
    // printf("Searching for idx = %lld in range (%lld %lld) node = %lld | ",idx,start,end,node);
    // printf("ret2 = %lld, p1 = %lld, p2 = %lld\n",max({ans,p1,p2}),p1,p2);
    return max({ans,p1,p2});
}

signed main(){
    scanf("%lld",&n);
    for(int i = 0; i < n; ++i){
        scanf("%lld",t+i);
        if(t[i] == 1){
            scanf("%lld%lld",A+i,B+i);
            endPoint[i] = n;
        }
        else if(t[i] == 2){
            scanf("%lld",B+i);
            endPoint[B[i]-1] = i;
        }else{
            scanf("%lld",A+i);
        }
    }
    for(int i = 0; i < n; ++i){
        if(t[i] == 1){
            if(endPoint[i] <= i+1)continue;
            // printf("Adding %lld till %lld\n",i,endPoint[i]);
            update(i+1,endPoint[i]-1,make_pair(A[i],B[i]));
        }
    }
    for(int i = 0; i < n; ++i){
        if(t[i] == 3){
            int ans = query(i,A[i]);
            if(ans == LLONG_MIN)printf("EMPTY SET\n");
            else printf("%lld\n",ans);
        }
    }
    return 0;
}