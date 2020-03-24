#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
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
#define M map
#define UM unordered_map
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
#define random_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuffle_random(a) random_shuffle(all(a),rng);
using namespace std;
// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator>>(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
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
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}

// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// Constants
const ll N = 1e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
vector<int> zf(string &a, string &b){
	string pat = a+"#"+b;
	int n = pat.size();
	vector<int> z(pat.size());
	for(int i = 0,r = 0,l=0; i < pat.size(); ++i){
		if(i <= r)z[i] = min(r-i+1,z[i-l]);
		while(z[i]+i < pat.size() && pat[z[i]] == pat[z[i]+i])z[i]++;
		
		if(z[i]+i-1 > r)l=i,r=z[i]+i-1;
	}
	return vector<int> (z.begin()+a.size()+1,z.end());
}

void solve(int test_case){
	string a;
	cin >> a;
	string ra = a;
	reverse(all(ra));
	int q;
	cin >> q;
	int ans = 0;
	while(q--){
		string b;
		cin >> b;
		if(b.size() < 2)continue;	
		vector<int> z = zf(b,a);
		reverse(all(b));
		vector<int> zr = zf(b,ra);
		vector<int> pref(b.size()+1,INT_MAX);
		vector<int> suff(b.size()+1,-1);
		int pmin=0,smin=0;
		loop(i,0,a.size()){
			for(int j = pmin; j <= z[i]; ++j)pref[j]=i;
			pmin=max(z[i]+1,pmin);
			int ending = a.size()-1-i;
			int starting = ending-(zr[i]-1);
			//from starting index we have suffix of z[i] length, 
			// and since ending decreases eventually therefore 
			// this is the rightmost index
			for(int j = zr[i],k=0; j > smin; --j,k++)suff[j]=(starting+k);
			smin = max(zr[i],smin);
			// suff[z[i]] = max(suff[zr[i]],int(a.size()-(i+1+z[i]))-1);
		}
		// cout << "STRING " << b << "\n";
		// cout << "Z " << z << "\n";
		// cout << "PREF " << pref << "\n";
		// cout << "ZR " << zr << "\n";
		// cout << "suff " << suff << "\n";
		if(pref[b.size()] != INT_MAX){
			ans++;
		}else{
			loop(i,1,b.size()+1){
				if(pref[i] == INT_MAX || suff[b.size()-i] == -1)continue;
				// printf("i = %d, pref[i] = %d, suff[b.size()-i] = %d\n",i,pref[i],suff[b.size()-i]);
				int endIND = i+pref[i]-1;
				if(suff[b.size()-i] > endIND){
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	FAST
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
