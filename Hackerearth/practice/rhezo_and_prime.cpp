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
const int maxn = 5010;
int main(){
    FILE_READ
    int t[maxn] = {0};
    for(int i = 2; i < maxn; ++i)if(!t[i])for(int j = 2; i*j < maxn; ++j)t[i*j]++;
    int n;
    cin >> n;
    if(n == 1){cout << "0"; return 0;}
    // cout << n << endl;
    // cout << k << endl;
    ll *arr = new ll[n];
    loop(i,0,n)cin >> arr[i];
    ll ans = 0;
    for(int i = 0; i < n; ++i)ans+=arr[i];
    // ll sum = ans;
    // for(int i = k; i < n; ++i){
    //     cout << sum << endl;
    //     sum-=arr[i-k];
    //     sum+=arr[i];
    //     ans = max(sum,ans);
    // }
    // cout << sum << endl;
    int i = 0;
    int j = n-1;
    // while(t[n] != 0){
    //     if(arr[i] < arr[j]){
    //         ans-=arr[i];
    //         ++i;
    //     }else{
    //         ans-=arr[j];
    //         --j;
    //     }
    //     n--;
    // }
    cout << ans;
    return 0;
}