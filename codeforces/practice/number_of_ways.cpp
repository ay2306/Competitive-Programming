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
    int n;
    // cin >> n;
    n = readInt();
    ll sum = 0;
    ll *arr = new ll[n];
    for(int i = 0; i < n; ++i){
        // cin >> arr[i];
        arr[i] = readInt();
        sum+=arr[i];
    }
    if(sum%3 != 0){
        cout << 0;
        return 0;
    }
    ll s = 0;
    int *cnt = new int[n];
    for(int i = n-1; i >= 0; --i){
        s+=arr[i];
        if(s == sum/3)cnt[i]=1;
        else cnt[i] = 0;
    }
    for(int i = n-2; i >= 0; --i)cnt[i]+=cnt[i+1];
    s = 0;
    ll ans = 0;
    // for(int i = 0 ; i < n; ++i)cout << cnt[i]  << " ";
    // cout << endl;
    for(int i = 0; i+2 < n; ++i){
        s+=arr[i];
        if(s == sum/3){
            ans+=cnt[i+2];
        }
    }
    cout << ans;
    return 0;
}