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
    /*
    dp[i][0] means 0 0
    dp[i][1] means 0 1
    dp[i][2] means 1 0
    dp[i][3] means 1 1
    */
    ll aa,bb,cc;
    cin >> aa >> bb >> cc;
    vector<int> a = vector<int> (32,0);
    vector<int> b = vector<int> (32,0);
    vector<int> c = vector<int> (32,0);
    for(int i = 0; i < 32; ++i){
        a[i] = ((aa >> i)%2);
        b[i] = ((bb >> i)%2);
        c[i] = ((cc >> i)%2);
    }

    int ans = 0;
    for(int i = 0; i < 32; ++i){
        int pos = 0;
        if(a[i] == 0 && b[i] == 1){
            for(int j = i+1; j < 32; ++j){
                if(a[j] == 1 && b[j] == 0)pos++;
            }
        }
        if(a[i] == 1 && b[i] == 0){
            for(int j = i+1; j < 32; ++j){
                if(a[j] == 0 && b[j] == 1)pos++;
            }
        }
        ll j = pos;
        while(pos){
            j*=pos;
            pos--;
        }
        // cout << j << "\n";
        ans+=j;
    }
    if(aa + bb == cc)ans*=2;
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}