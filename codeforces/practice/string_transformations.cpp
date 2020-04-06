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

vector<int> zf(string a, string b){
	string c = a+'\0'+b;
	int n = 2*a.size()+1;
	vector<int> z(n,0);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r)z[i] = min(z[i-l],r-i+1);
		while(z[i]+i < n && c[z[i]+i] == c[z[i]])z[i]++;
		if(i+z[i]-1 > r)l=i,r=z[i]+i-1;
	}
	return z;
	// return vector<int>(z.begin()+a.size()+1,z.end());
}

vector<int> pref(string a, string b){
	string s = a+'\0'+b;
	int n = 2*a.size()+1;
	vector<int> p(n,0);
	for(int i = 1; i < n; ++i){
		p[i] = p[i-1];
		while(p[i] > 0 && s[p[i]] != s[i])p[i]=p[p[i]-1];
		if(s[p[i]] == s[i])++p[i];
	}
	// for(int i = 0; i < n; ++i){
	// 	printf("i = %d, p[i] = %d, s[i] = %c\n",i,p[i],s[i]);
	// }
	return p;
}

void solve(int test_case){
	string a,b,c,d;
	getline(cin,a);
	getline(cin,b);
	int n = a.size();
	if(a.size() != b.size()){
		cout << "-1 -1";
		return;
	}
	c = a;
	reverse(all(c));
	auto z1 = pref(c,b);
	auto z2 = zf(b,a);
	/*
	*    Compute z1 for b#a
	*	 for index i+1 we get j-1, let's say ind = i+1, then ind+z1[ind]-1 = j-1 this 
	*	 Since it therefore i = ind-1 and j = ind+z1[ind]
	*    Now it is guaranteed by z function that s[i+1 ... j-1] is a prefix of b
	*    let len = j-1-(i+1)+1 = j-i-1
	*    Now we have to prove that b[len ... (n-j)] is the next sequence of and is a suffix of 'a' of length n-j-len+1 
	*	 This can be done by computing z2 for rev(a) # b
	*    Now we have to confirm reverse(a[0 ... i]) is suffix of b
	*    Thus this can be done by z3 for rev(b) # rev(a)
	*	 in reverse form i is n-i
	*	
	*/
    int a1 = -1, a2 = -1;
	for(int i = 0; i < a.size()-1; ++i){
		if(a[i] != b[n-1-i])break;
		int len = z1[2*n-i-1];
		if(z2[n + i + 2] >= n - i - len - 1){
			a1 = i;
			a2 = n - len;
		}
	}
	printf("%d %d\n",a1,a2);
}

int main(){
	// freopen("output.out","w",stdout);
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
