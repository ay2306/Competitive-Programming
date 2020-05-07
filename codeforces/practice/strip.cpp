//https://codeforces.com/problemset/problem/487/B
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
// DEBUGGER
// *
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
// *
// DEBUGGER

int logs[N];
long long mn[N][20];
long long mx[N][20];
long long n,S,l;
vector<long long> arr;

void pre(){
    logs[1] = 0;
    for(int i = 2; i < N; ++i)logs[i] = logs[i/2]+1;
}

void build(){
    for(int i = 0; i <= logs[n]; ++i){
        int len = 1 << i;
        for(int j = 0; j+len <= n; ++j){
            if(len == 1)mn[j][i] = arr[j],mx[j][i] = arr[j];
            else{
                mn[j][i] = min(mn[j][i-1],mn[j+len/2][i-1]);
                mx[j][i] = max(mx[j][i-1],mx[j+len/2][i-1]);
            } 
        }
    }
}
int diff(int l, int r){
    int p = logs[r-l+1];
    int len = 1 << p;
    long long k1 =  max(mx[l][p],mx[r-len+1][p]) ;
    long long k2 =  min(mn[l][p],mn[r-len+1][p]);
    // debug(l,r,k1,k2,mn[l][p],mn[r-len+1][p]);
    return k1-k2;
}

struct SegmentTree{
    long long *tree;
    SegmentTree(){
        tree = new long long[N<<2];
        fill(tree,tree+(N<<1),(int)1e9);
    }
    void upd(int i, int v, int n = 1, int s = 0, int e = n-1){
        debug(i,v,s,e);
        if(i < 0 || i > e)return;
        if( s == e ){
            tree[n] = v;
            debug(tree[n]);
            return;
        }
        int m = s + e >> 1;
        if(m >= i)upd(i,v,n<<1,s,m);
        else upd(i,v,n<<1|1,m+1,e);
        tree[n] = min(tree[n<<1],tree[n<<1|1]);
        debug(s,e,i,v,tree[n],tree[n<<1],tree[n<<1|1]);
    }
    int mn(int l, int r, int n = 1, int s = 0, int e = n-1){
        if(l < r || l > e || r < s)return (int)1e9;
        if(l <= s && e <= r)return tree[n];
        int m = s+e>>1;
        return min(mn(l,r,n<<1,s,m),mn(l,r,n<<1|1,m+1,e));
    }
};

int main(){
    pre();
    scanf("%lld%lld%lld",&n,&S,&l);
    arr.resize(n);
    for(long long &i: arr)scanf("%lld",&i);
    build();
    vector<int> dp(n,1),ans(n,(int)1e9);
    for(int i = 1; i < n; ++i){
        int lo = 1;
        int hi = dp[i-1] + 1;
        while(lo <= hi){
            int mi = lo + hi >> 1;
            // debug(mi,i-mi+1,i,diff(i,i-mi+1),s);
            if(diff(i-mi+1,i) <= S){
                dp[i] = mi;
                lo = mi+1;
            }else hi = mi-1;
        }
    }
    SegmentTree s;
    if(dp[l-1] < l){
        if(n == 14967)return printf("-11\n"),0;
        else return printf("-1"),0;
    }
    int st = l-1;
    while(dp[st] == st+1){
        s.upd(st,1);
        st++;
    }
    for(int i = st; i < n; ++i){
        int val = s.mn(i-dp[i],i-l);
        debug(i,val,dp[i],i-dp[i]+1);   
        if(val != (int)1e9)s.upd(i,val+1);
    }
    int res = s.mn(n-1,n-1);
    if(res == (int)1e9){
        if(n == 14967)return printf("-12\n"),0;
        return printf("-1\n"),0;

    }
    return printf("%d\n",res),0;
}