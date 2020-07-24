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

using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const long long N = 1e5 + 100;
const long long inf = 1e9;
const long double pi = acos(-1);


// template<int MAXN>
// class SuffixAutomaton{  
//     struct node{
//         int len,link;
//         map<char,int> next;
//         node():len(0),link(-1){}
//     } *tree;
//     int last, sz;
//     long long *dp;
// public:
//     SuffixAutomaton(){
//         last = 0;
//         sz = 1;
//         dp = new long long[MAXN*2];
//         tree = new node[MAXN*2];
//     }
//     void add(char c){
//         int cur = sz++,p;
//         tree[cur].len = tree[last].len + 1;
//         for(p = last; p != -1 && !tree[p].next.count(c); p = tree[p].link)
//             tree[p].next[c] = cur;
//         if(p == -1)tree[cur].link = 0;
//         else{
//             int q = tree[p].next[c];
//             if(tree[q].len == tree[p].len+1)tree[cur].link = q;
//             else{
//                 int clone = sz++;
//                 tree[clone].len = tree[p].len + 1;
//                 tree[clone].next = tree[q].next;
//                 tree[clone].link = tree[q].link;
//                 for(; p != -1 && tree[p].next[c] == q; p = tree[p].link){
//                     tree[p].next[c] = clone;
//                 }
//                 tree[q].link = tree[cur].link = clone;
//             }
//         }
//         last = cur;
//     }
//     long long distinct(){
//         fill(dp,dp+MAXN*2,-1);
//         return dfs(0);
//     }
//     long long dfs(int cur, string a = "", int parent = -1){
//         long long &res = dp[cur];
//         if(~res)return res;
//         res = (parent != -1);
//         for(auto &i: tree[cur].next){
//             res+=dfs(i.second,a+i.first,cur);
//         }
//         return res;
//     }
// };
 

// int countSubstrings(string s) {
//         int n = s.length();
//         if (n == 0 || n == 1) return n;
//         int left = 0, right = 0, count = 0;
        
//         for (int i = 0; i < n; i++) {
//             //checking odd-length substring
//             left = i;
//             right = i;
//             while (left >= 0 && right < n && s[left] == s[right]) {
//                 left--;
//                 right++;
//                 count++;
//             }
            
//             //checking even-length substring
//             left = i;
//             right = i + 1;
//             while (left >= 0 && right < n && s[left] == s[right]) {
//                 left--;
//                 right++;
//                 count++;
//             }
//         }
//         return count;
//     }

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         string a;
//         cin >> a;
//         SuffixAutomaton<1010> s;
//         for(auto &i: a)s.add(i);
//         cout << s.distinct() << "\n";  
//          cout << countSubstrings(a) << "\n";
//     }
//     return 0;
// } 

void solve(){
    int d;
    cin >> d;

    cout << 2*d << "\n" << string(d,'a') << string(d,'b') << "\n";
}

int main(){
	FAST
	int t = 1;
	cin >> t;
    while(t--)solve();
    return 0;
}
