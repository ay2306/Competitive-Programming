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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
unordered_map<int,int> m;
V<PII> pos;
int mx,mn;
void check(int a){
    for(auto i: pos){
        int k = m[i.first];
        int ct = 0;
        for(int j = 0; j < 7; ++j){
            if(((1 << j) & k) && ((1 << j) & a)){
                ct++;
            }
        }
        if(ct != i.S)return;
    }
    int ans = 0;
    for(int i = 0; i < 7; ++i){
        if((1 << i) & a)ans++;
        // cout << ((((1 << i) & a) > 0)?1:0);
    }
    // cout << "\n";
    ans = 7-ans;
    mx = max(ans,mx);
    mn = min(ans,mn);
}

void solve(){
    int n;
    cin >> n;
    pos = V<PII> (n);    
    loop(i,0,n){
        int a,b;
        cin >> a >> b;
        pos[i] = mp(a,b);
    }
    mx = 0;
    mn = 8;
    // check((1 << 8)-1);
    for(int i = 0; i < (1 << 7); ++i){
        check(i);
    }
    if(mn == 8){
        cout << "invalid\n";
    }else{
        cout << mn << " " << mx << "\n";
    }
}

int main(){
    m[0] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5);
    m[1] = (1 << 1) + (1 << 2) ;
    m[2] = (1 << 0) + (1 << 1) + (1 << 3) + (1 << 4) + (1 << 6);
    m[3] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 6);
    m[4] = (1 << 1) + (1 << 2) + (1 << 5) + (1 << 6);
    m[5] = (1 << 0) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 6);
    m[6] = (1 << 0) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6);
    m[7] = (1 << 0) + (1 << 1) + (1 << 2);
    m[8] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6);
    m[9] = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 6);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}