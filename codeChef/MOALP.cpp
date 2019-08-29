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
V<int> arr(2*1000000 + 10);
void solve(){
    int l,r;
    cin >> l >> r;
    cout << arr[r] - arr[l-1] << "\n";
}

int main(){
    for(int i = 1; i <= 2*1000000; ++i){
        int j = i;
        while(j){
            if(j % 16 > 9)m[i]++;
            j/=16;
        }
    }
    arr[0] = 0;
    for(int i = 1; i <= 2*1000000; ++i){
        arr[i] = m[i];
        arr[i]+=arr[i-1];
    }
    
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}