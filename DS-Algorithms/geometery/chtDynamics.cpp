#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
struct Line{
    mutable long long k,m,p;
    bool operator<(const Line &rhs)const{return k < rhs.k;}
    bool operator<(long long x)const{return p < x;}
};

struct cht: multiset<Line,less<>>{
    const long long inf = LLONG_MAX;
    long long div (long long a, long long b){
        return a/b - ((a^b) < 0 && a%b);
    }
    bool intersect(iterator x, iterator y){
        if(y == end()){x->p = inf; return false;}
        if(x->k == y->k)x->p = x->m > y->m ? inf:-inf;
        else x->p = div(y->m-x->m,y->k-x->k);
        return x->p >= y->p;
    }
    void add(long long k, long long m){
        auto z = insert({k,m,0}), y = z++, x = y;
        while(intersect(y,z))erase(z);
        if(x != begin() && intersect(--x,y))intersect(x,y=erase(y));
        while((y=x) != begin() && (--x)->p >= y->p)intersect(x,erase(y));
    }
    long long query(long long x){
        assert(!empty());
        auto l = lower_bound(x);
        return l->k*x + l->m;
    }
};
int n;
long long ans,arr[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%lld",arr+i);
    for(int i = 2; i <= n; ++i)arr[i]+=arr[i-1];
    cht s;
    s.add(-2-2*arr[1],1+arr[0]*arr[0]);
    for(int i = 2; i <= n; ++i){
        ans = i*i + arr[i]*arr[i] + s.query(i)
    }
    return 0;
}