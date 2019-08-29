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

ll getBits(ll a){
    ll c = 0;
    while(a){
        if(a%2 == 1)c++;
        a = (a>>1);
    }
    return c;
}

int main(){
    int n = 0;
    cin >> n;
    ll *arr = new ll[n];
    loop(i,0,n){
        cin >> arr[i];
        arr[i] = getBits(arr[i]);
    } 
    ll ans = 0;
    ll last = 0;
    ll current = 1;
    loop(i,1,n){
        current  = i;
        if(arr[i] == arr[i-1])continue;
        else{
            if(last != current-1){
                ll size = current-last+1;
                ans+=((size*(size+1))/2);
            }
            last = current;
        }
        cout << current << " " << last << endl;
    }
    if(last != current){
        ll size = current-last+1;
        ans+=((size*(size+1))/2);
        // cout << size << " ";
    }
    // cout << first << " " << last << endl;
    // cout << endl;
    cout << ans;
    return 0;
}