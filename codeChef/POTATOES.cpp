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
V<int> sieve;

int BS(int a){
    int low = 0;
    int high = sieve.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(sieve[mid] == a)return sieve[mid+1];
        if(sieve[mid] < a && sieve[mid+1] > a)return sieve[mid+1];
        if(sieve[mid] > a && sieve[mid-1] < a)return sieve[mid];
        if(sieve[mid] > a)high = mid-1;
        else low = mid+1;
    }
}


int main(){
    int v[100000] = {0};
    for(int i = 2; i < 100000; ++i)if(v[i] == 0)for(int j = 2; i*j < 100000; ++j)v[i*j]=1;
    for(int i = 2; i < 100000; ++i)if(v[i] == 0)sieve.pb(i);
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        cout << BS(x+y)-x-y << endl;
    }
    return 0;
}