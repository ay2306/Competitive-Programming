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

int main(){
    FAST
    int n,m;
    cin >> n;
    V<ll> a(n);
    ll s1 = 0;
    ll s2 = 0;
    loop(i,0,n){
        cin >> a[i];
        s1+=a[i];
    }
    cin >> m;
    V<ll> b(m);
    loop(i,0,m){
        cin >> b[i];
        s2+=b[i];
    }
    if(s1 != s2){
        cout << -1;
        return 0;
    }
    s1 = 0;
    s2 = 0;
    int i = 0;
    int j = 0;
    int ans = 0;
    do{
        if(s1 == 0 && s2 == 0){
            s1+=a[i++];
            s2+=b[j++];
        }
        else if(s1 > s2){
            s2+=b[j++];
        }
        else if(s2 > s1){
            s1+=a[i++];
        }
        if(s1 == s2){
            ans++;
            s1 = 0;
            s2 = 0;
        }
    }while(i < n || j < m);
    cout << ans;
    return 0;
}