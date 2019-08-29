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
    int n,k;
    cin >> n >> k;
    int *chef = new int[n];
    int *best = new int[n];
    for(int i = 0; i < n; ++i)cin >> best[i];
    for(int i = 0; i < n; ++i)cin >> chef[i];
    sort(chef,chef+n);
    sort(best,best+n);
    int i = 0;
    int j = 0;
    int cnt = 0;
    for(; i < n && j < n ; ){
        if(best[i] >= chef[j])j++;
        else{
            cnt++;
            j++;
            i++;
        }
    }
    if(cnt >= k)cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    // FILE_READ
    FAST
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}