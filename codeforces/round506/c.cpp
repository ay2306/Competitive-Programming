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
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
int n;
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

int main(){
    FAST
    // cin >> n;
    n = readInt();
    PLL *arr = new PLL[n];
    loop(i,0,n){
    
        // cin >> arr[i].first >> arr[i].second;
        arr[i].first = readInt();
        arr[i].second = readInt();
    }
    ll l = LLONG_MIN, l1 = LLONG_MIN, r = LLONG_MAX, r1 = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        if(arr[i].first > l){
            l1 = l;
            l = arr[i].first;
        }
        else if(arr[i].first > l1){
            l1 = arr[i].first;
        }
        if(arr[i].second < r){
            r1 = r;
            r = arr[i].second;
        }
        else if(arr[i].second < r1){
            r1 = arr[i].second;
        }
    }
    bool match = false;
    loop(i,0,n){
        if(arr[i].first == l && arr[i].second == r){
            match = true;
            break;
        }
    }
    ll zero = 0;
    if(match){
        cout << max(zero,r1-l1);
    }else{
        cout << max(max(zero,r1-l),max(zero,r-l1));
    }
        // loop(i,0,n)cin >> l[i] >> r[i];
    // loop(i,0,n)cin >> l[i] >> r[i];
    return 0;
}