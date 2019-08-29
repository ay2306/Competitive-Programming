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

int main(){
    ll n,k,s;
    cin >> n >> k >> s;
    if(s < k){
        cout << "NO";
        return 0;
    }
    if(s%k == 0){
        ll a = s/k;
        if(a+1 > n){
            cout << "NO";
            return 0;
        }
        cout << "YES\n";
        for(int i = 1; i <= k; ++i){
            if(i%2 == 1)cout << a+1;
            else cout << " 1 ";
        }
    }
    if(s%k != 0){
        ll t = n-1;
        if(t*(k-1) + n - 1 < s){
            cout << "NO";
            return 0;
        }
        ll a = min(s/(k-1),n-1);
        ll b = s-(a*(k-1));
        ll last = 1;
        // if(a+1 > n){
        //     cout << "NO";
        //     return 0;
        // }
        cout << "YES\n";
        for(int i = 1; i < k; ++i){
            
            if(last == 1){
                last = a+1;
                cout << last << " ";
            }else{
                last-=a;
                cout << last << " ";
            }
        }
        if(last + b <= n)cout << last + b;
        else cout << last - b;
    }
    return 0;
}