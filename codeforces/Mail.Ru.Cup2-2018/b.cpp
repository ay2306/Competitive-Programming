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
    ll n,m,l,c = 0;
    cin >> n >> m >> l;
    vector<ll> arr(n);
    cin >> arr[0];
    if(arr[0] > l)c++;
    loop(i,1,n){
        ll a;
        cin >> a;
        if(a > l && arr[i-1] <= l)c++;
        arr[i] = a;
    }
    if(n == 1){
        loop(i,0,m){
            ll t;
            cin >> t;
            if(t == 0){
                cout << c << "\n";
            }else{
                ll p,d;
                cin >> p >> d;
                arr[0]+=d;
                if(arr[0] > l){
                    c = 1;
                }else{
                    c = 0;
                }
            }
        }
    }
    else if(n == 2){
        loop(i,0,m){
            ll t;
            cin >> t;
            if(t == 0){
                cout << c << "\n";
            }else{
                ll p,d;
                cin >> p >> d;
                arr[p-1]+=d;
                if(arr[1] > l || arr[0] > l){
                    c = 1;
                    // cout << 1 << "\n";
                }else{
                    c = 0;
                    // cout << 0 << "\n";
                }
            }
        }
    }else{
        loop(i,0,m){
            ll t;
            cin >> t;
            if(t == 0){
                cout << c << "\n";
            }else{
                ll p,d;
                cin >> p >> d;
                if(arr[p-1] <= l){
                    if(arr[p-1]+d > l){
                        if(p == 1){
                            if(arr[1] <= l)c++;
                        }
                        else if(p == n){
                            if(arr[n-2] <= l)c++;
                        }
                        else if(arr[p-2] <= l && arr[p] <= l){
                            c++;
                        }else if(arr[p-2] > l && arr[p] > l){
                            c--;
                        }
                    }
                } 
                arr[p-1]+=d;
            }
        }
    }
    return 0;
}