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
    FAST
    int n;
    cin >> n;
    ll *arr = new ll [n+1];
    loop(i,0,n)cin >> arr[i];
    if(n == 1){
        cout << "Yes";
        return 0;
    }
    if(n == 2){
        if(__gcd(arr[0],arr[1])!=1){
            cout << "Yes";
        }else{
            cout << "No";
        }
        return 0;
    }
    for(int i = 0; i < n; ++i){
        ll a=1,b=1;
        if(i+1 < n)a = __gcd(arr[i],arr[i+1]);
        if(i-1 >= 0)b = __gcd(arr[i],arr[i-1]);
        if(a == 1 && b == 1){
            cout << "No";
            return 0;
        }  
    }
    cout << "Yes";
    return 0;
}