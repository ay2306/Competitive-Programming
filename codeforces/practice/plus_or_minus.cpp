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
V<ll> arr; 
V<char> op;
ll steps = LLONG_MAX;

void f(V<char> t){
    if(t.size() == op.size()){
        ll ans = arr[0];
        loop(i,1,arr.size()){
            if(t[i-1] == '+')ans+=arr[i];
            else ans-=arr[i];
        }
        if(ans == 0){
            ll c = 0;
            loop(i,0,op.size()){
                if(t[i] != op[i])c++;
            }
            steps = min(steps,c);
            // if(c == steps){
            //     cout << arr[0];
            //     // loop(i, 1, arr.size()){
            //     //     cout << t[i-1]
            //     // }
            // }
        }
        return;
    }
    t.pb('+');
    f(t);
    t.pop_back();
    t.pb('-');
    f(t);
}

int main(){
    int n;
    cin >> n;
    arr = V<ll> (n);
    cin >> arr[0];
    op = V<char> (n-1);
    loop(i,1,n){
        cin >> op[i-1] >> arr[i];
    }
    V<char> temp;
    f(temp);
    if(steps == LLONG_MAX)steps = -1; 
    cout << steps;
    return 0;
}