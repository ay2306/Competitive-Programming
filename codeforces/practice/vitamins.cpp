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
    cin >> n;
    ll cost[8];
    loop(i,0,8)cost[i] = INT_MAX;
    for(int i = 0; i < n; ++i){
        ll a,b=0;
        string k;
        cin >> a >> k;
        for(int j = 0; j < k.length(); ++j){
            if(k[j] == 'A' && (b%2 == 0)){
                b++;
            }
            if(k[j] == 'B' && ((b<<1)%2 == 0)){
                b+=(1<<1);
            }
            if(k[j] == 'C' && ((b<<2)%2 == 0)){
                b+=(1<<2);
            }
        }
        cost[b] = min(cost[b],a);
    }
    // loop(i,0,8){
    //     printf("index = %d and cost[%d] = %lld\n",i,i,cost[i]);
    // }
    ll z = cost[7];
    ll y = cost[1]+cost[2]+cost[4];
    // printf("z = %d, y = %d\n",z,y);
    y = min(z,y);
    // printf("z = %d, y = %d\n",z,y);
    z = cost[1]+cost[6];
    y = min(z,y);
    // printf("z = %d, y = %d\n",z,y);
    z = cost[2]+cost[5];
    y = min(z,y);
    // printf("z = %d, y = %d\n",z,y);
    z = cost[4]+cost[3];
    y = min(z,y);
    z = cost[5]+cost[6];
    y = min(z,y);
    z = cost[6]+cost[3];
    y = min(z,y);
    z = cost[5]+cost[3];
    y = min(z,y);
    // printf("z = %d, y = %d\n",z,y);
    if(y == INT_MAX)cout << -1;
    else cout << y;
    return 0;
}