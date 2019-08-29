/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define PR pair
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
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define P pair<pair<long long int,long long int> , pair<long long int,long long int> >
#define MAXN 25
using namespace std;

ll readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
 
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
 
	if (ch == '-') minus = true; else result = ch-'0';
 
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
 
	if (minus)
		return -result;
	else
		return result;
}

P multi(P a, P b){
    P c;
    c.first.first = (a.first.first*b.first.first + a.first.second*b.second.first)%MOD;
    c.first.second = (a.first.first*b.first.second + a.first.second*b.second.second)%MOD;
    c.second.first = (a.second.first*b.first.first + a.second.second*b.second.first)%MOD;
    c.second.second = (a.second.first*b.first.second + a.second.second*b.second.second)%MOD;
    return c;
}

P binaryExponent(P a,ll n){
    if(n == 1)return a;
    P c = multi(a,a);
    c = binaryExponent(c,n/2);
    if(n%2 == 1){
        c = multi(c,a);
    }
    return c;
}


void solve(){
    ll n;
    cin >> n;
    if(n < 0){cout << "0";return;}
    if(n == 1){cout << "2";return;}
    if(n == 2){cout << "3";return;}
    P a = make_pair(make_pair(1,1),make_pair(1,0));
    P ans = make_pair(make_pair(-1,-1),make_pair(-1,-1));
    n-=2;
    ll ab = 1;
    int i = 0;
    vector<int> v;
    while((ab << i) <= n){
        if((n >> i)&1 == 1){
            v.push_back(i);
        }
        ++i;
    }
    for(vector<int>::reverse_iterator itr = v.rbegin(); itr != v.rend(); ++itr){
        int i = *itr;
        // cout << (ab << i) << endl;
        P d = binaryExponent(a,(ab << i));
        if(ans.first.first == -1 && ans.first.second == -1 && ans.second.first == -1 && ans.second.second == -1){
            ans = d;
        }else{
            ans = multi(d,ans);
        }
        // cout << d.first.first << " " << d.first.second << endl;
        // cout << d.second.first << " "  << d.second.second << endl;
    }
    P c = ans;
    // P c = binaryExponent(a,n);
    // cout << c.first.first << " " << c.first.second << endl;
    // cout << c.second.first << " "  << c.second.second << endl;
    cout << (3*c.first.first+2*c.first.second)%MOD << "\n";
}


int main(){
    int t;
    cin >> t;
    while(t--)solve();
}