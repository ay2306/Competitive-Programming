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
int n,m;

bool make_move(V<string> &arr, int i, int j, int p, char d){
    if(d == 'V'){
        loop(k,0,n){
            if(arr[k][j] == '#'){
                return false;
            }
        }
        loop(k,0,n){
            arr[k][j] = 'O';
        }
    }
    if(d == 'V'){
        loop(k,0,m){
            if(arr[i][k] == '#'){
                return false;
            }
        }
        loop(k,0,m){
            arr[i][k] = 'O';
        }
    }
}

void solve(){
    cin >> n >> m;
    V<string> arr;
    loop(i,0,n){
        string a;
        cin >> a;
        arr.pb(a);
    }
    int ans = 0;
    loop(i,0,n){
        loop(j,0,n){
            if(make_move(arr,i,j,1,'H')){
                ans++;
            }
            if(make_move(arr,i,j,1,'V')){
                ans++;
            }
        }
    }
}

int main(){
    int t = 1;
    cin >> t;
    loop(i,1,t+1){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}