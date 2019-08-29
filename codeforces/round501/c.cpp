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

bool cmp(ll a, ll b){
    // if(a.first > b.first)return true;
    // if(a.first < b.first)return false;
    // if(a.second > b.second)return false;
    // return true;
    if(a >= b)return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    ll m,sum=0;
    cin >> m;
    ll *p = new ll[n];
    loop(i,0,n){
        ll a,b;
        cin >> a >> b;
        p[i] = a-b;
        sum+=a;
    }
    if(sum <= m){
        cout << "0";
        return 0;
    }
    sort(p,p+n);
    int moves = 0;
    for(int i = n-1; i >= 0; --i){
        ++moves;
        sum-=p[i];
        if(sum <= m){
            cout << moves;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}