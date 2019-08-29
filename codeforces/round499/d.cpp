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

int query(ll y)
{
    cout<<y<<"\n";
    fflush(stdout);
    int t;
    cin>>t;
    if(t==0||t==-2)
        exit(0);
    return t;
}

int main(){
    ll m;
    int n,input;
    cin >> m >> n;
    int *p = new int[n];
    for(int i = 0; i < n; ++i){
        input = query(1LL * 1);
        if(input == 0){
            return 0;
        }
        if(input == 1){
            p[i] = 1;
        }else{
            p[i] = -1;
        }
    }
    int i = 0;
    ll high = m;
    ll low = 1;
    while(low <= high){
        ll mid = (low+high)/2;
        input = query(mid);
        input*=p[i%n];
        if(input == 1){
            low = mid+1;
        }else{
            high = mid-1;
        }
        ++i;
    }
    return 0;
}