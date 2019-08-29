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
using namespace std;

const ll maxn = 1e5;
int a[510][510];
int b[510][510];
int c[510][510];
int main(){
    int n,m;
    cin >> n >> m;
    loop(i,0,n){
        loop(j,0,m)cin >> a[i][j];
    } 
    loop(i,0,n){
        loop(j,0,m)cin >> b[i][j];
    } 
    loop(i,0,n-1){
        loop(j,0,m-1){
            if(a[i][j] != b[i][j]){
                a[i][j]^=1;
                a[i][j+1]^=1;
                a[i+1][j]^=1;
                a[i+1][j+1]^=1;
            }
        }
    } 
    bool p1 = true;
    bool p2 = true;
    // loop(i,0,n-1){
    //     loop(j,0,m-1){
    //         cout << a[i][j] << " ";
    //     }
    // } 
    
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j] != b[i][j]){
                cout << "No";
                return 0;
            }
        }
    } 
    cout << "Yes";

    return 0;
}