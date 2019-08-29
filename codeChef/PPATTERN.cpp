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

void solve(){
    int n;
    cin >> n;
    int p = 1;
    V<V<int> > arr (n,V<int>(n,0));
    for(int k = 0; k < n; ++k){
        int j = k;
        int i = 0;
        while(i < n && j >= 0){
            arr[i][j] = p;
            p++;
            i++;
            j--;
        } 
    }
    for(int k = 1; k < n; ++k){
        int j = n-1;
        int i = k;
        while(i < n && j >= 0){
            arr[i][j] = p;
            p++;
            i++;
            j--;
        } 
    }
    for(auto i: arr){
        for(auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}