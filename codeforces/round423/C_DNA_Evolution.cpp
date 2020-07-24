#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
const long long mod = 1e9+7;
// const long long mod = 998244353;
const long long int special_prime = 982451653;
using namespace std;
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

#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define mp make_pair
#define pb emplace_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
#define sz(x) (int)((x).size())
#define square(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define distance(a,b,c,d) ((a-c)*1LL*(a-c)+(b-d)*1LL*(b-d))
#define range(i,x,y) ((x <= i) && (i <= y))
#define SUM(a) accumulate(a.begin(),a.end(),0LL)
#define lb lower_bound
#define ub upper_bound
#define REV reverse
#define seive(N) int pr[N]; void preSieve(){for(int i = 2; i < N; ++i){if(!pr[i])for(int j = i; j < N; j+=i)pr[j]=i;}}
#define modInv(N) ll inv[N]; void preModInv(){inv[0]=0;inv[1]=1;for(int i = 2; i < N; ++i)inv[i] = mod-mod/i*inv[mod%i]%mod;}
#define fact(N) ll fact[N]; void preFact(){fact[0] = 1,fact[1] = 1; for(int i = 2; i < N; ++i)fact[i]=fact[i-1]*i%mod;}
#define inFact(N) ll ifact[N]; void preiFact(){ifact[1] = 1; for(int i = 2; i < N; ++i)ifact[i]=ifact[i-1]*inv[i]%mod;}

// Randomization



// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator<<(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
template<class T, class U>pair<T,U> operator+(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first+b.first,a.second+b.second);}
template<class T, class U>pair<T,U> operator-(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first-b.first,a.second-b.second);}
// Linear STL
// VECTOR
template<class T>istream& operator>>(istream& in, vector<T> &a){for(auto &i: a)cin >> i;return in;}
template<class T>ostream& operator<<(ostream& out, const vector<T> &a){for(auto &i: a)cout << i << " ";return out;}
// SET
template<class T>ostream& operator<<(ostream& out, const set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const unordered_set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const multiset<T> &a){for(auto &i: a)cout << i << " ";return out;}
// MAP
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}

const long long N = 1e5 + 10;
const long long inf = 1e9;
const long double pi = acos(-1);

int val(char c){
    if(c == 'A')return 0;
    if(c == 'T')return 1;
    if(c == 'G')return 2;
    return 3;
}

struct Node{
    int cnt[4];
    Node(char s = ' '){
        memset(cnt,0,sizeof(cnt));
        if(s != ' ')cnt[val(s)]++;  
    }
    Node operator+(const Node &r){
        Node a;
        loop(i,0,4){
            a.cnt[i] = cnt[i] + r.cnt[i];
        }
        return a;
    }
};

struct segmentTree{
    Node tree[(N+10)<<2];
    void update(int id, char s,int node = 1, int start = 1, int end = N){
        if(start == end){
            memset(tree[node].cnt,0,sizeof(tree[node].cnt));
            tree[node].cnt[val(s)]++;
            return;
        }
        int mid = start + end >> 1;
        if(id <= mid)update(id,s,node<<1,start,mid);
        else update(id,s,node<<1|1,mid+1,end);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    Node query(int l, int r, int node = 1, int start = 1, int end = N){
        if(r < l || l > end || r < start)return Node();
        if(l <= start && end <= r)
            return tree[node];
        int mid = start + end >> 1;
        return query(l,r,node << 1, start, mid)+query(l,r,node << 1 | 1, mid+1, end);
    }
};

struct query{
    string a;
    int t, l, r, x;
    char p;
    query(){}
    query(int t, int x, char p):t(t),x(x),p(p){}
    query(int t, int l, int r, string a):t(t),l(l),r(r),a(a){}
};

void solve(int test_case){
    string st;
    cin >> st;
    int q;
    cin >> q;
    vector<query> Q;
    int idx = 0;
    loop(j,0,q){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            char p;
            cin >> x >> p;
            Q.pb(1,x,p);
            continue;
        }else{
            idx++;
            string a;
            int l,r;
            cin >> l >> r;
            cin >> a;
            Q.pb(2,l,r,a);
        }
    }
    vector<int> ans(idx);
    loop(md,1,11){
        idx = -1;
        segmentTree *s = new segmentTree[md];
        loop(i,0,st.size()){
            s[(i+1)%md].update(i+1,st[i]);
        }
        loop(qu,0,q){
            if(Q[qu].t ==1){
                s[Q[qu].x%md].update(Q[qu].x,Q[qu].p);
                continue;
            }
            idx++;
            int n = Q[qu].a.size();
            if(n != md)continue;
            loop(i,0,n){
                if(Q[qu].l + i > Q[qu].r)break;
                ans[idx] += s[(Q[qu].l+i)%n].query(Q[qu].l,Q[qu].r).cnt[val(Q[qu].a[i])];
            }
        }
        delete[] s;
    }
    for(int i : ans)cout << i << "\n";
}

int main(){
	FAST
	auto clk = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
	#ifdef LOCAL
		cout << "\n\nTIME ELAPSED : " << double(clock() - clk)/CLOCKS_PER_SEC * 1000.0 << " ms.\n";
	#endif
}
