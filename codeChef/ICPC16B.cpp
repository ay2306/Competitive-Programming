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

void solve(){
    int n;
    cin >> n;
    // if(n == 1){
    //     int a;
    //     cin >> a;
    //     printf("no\n");
    //     return;
    // }
    unordered_map<ll,int> m;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        m[a]++;
    }
    cnt = n - m[0] - m[1] - m[-1];
    if(cnt > 1){
        printf("no\n");
        return;
    }
    if(cnt && m[-1]){
        printf("no\n");
        return;
    }
    if(m[-1] > 1 && m[1] == 0){
        printf("no\n");
        return;
    }
    printf("yes\n");
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}