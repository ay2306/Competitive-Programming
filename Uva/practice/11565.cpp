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
#define MAXN 1001000
using namespace std;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    for(int i = -100; i <= 100; ++i){
        for(int j = i+1; j <= 100; ++j){
            for(int k = j+1; k <= 100; ++k){
                if(i!=j && i!=k && j!=k){
                    if(i*j*k == b && i+j+k ==a && i*i+j*j+k*k == c){
                        cout << i << " " << j << " " << k << "\n";
                        return; 
                    }
                }
            }
        }
    }
    cout << "No solution.\n";
}

int main(){
    FILE_READ
    int n;
    cin >> n;
    while(n--)solve();
    return 0;
}