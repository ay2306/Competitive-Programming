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

void solve(){
    ll n,q; int k;
    cin >> n >> q >> k;
    list<PII> arr;
    V<int> ar(n);
    loop(i,0,n){
        cin >> ar[i];
    }
    arr.pb(mp(ar[0],1));
    loop(i,1,n){
        if(arr.rbegin()->first == ar[i]){
            arr.rbegin()->second++;
        }else{
            arr.pb(mp(ar[i],1));
        }
    }
    ll mx1 = 0;
    ll mx2 = 0;
    if(arr.begin()->first == 1 && arr.rbegin()->first == 1){
        mx1 = arr.begin()->second+arr.rbegin()->second;
    }
    for(auto i: arr){
        if(i.first == 1){
            if(i.second >= mx1){
                mx2 = mx1;
                mx1 = i.second;
            }else if(i.second > mx2){
                mx2 = i.second;
            }
        }
    }
    string a;
    cin >> a;
    for(auto c: a){
        if(c == '!'){
            if(arr.begin()->first == arr.rbegin()->first){
                arr.begin()->second++;
                arr.rbegin()->second--;
            }
            else if(arr.begin()->first != arr.rbegin()->first){
                arr.push_front(mp(arr.rbegin()->first,1));
                arr.rbegin()->second--;
            }
            if(arr.rbegin()->second == 0)arr.pop_back();
        }else{
            int ans = 0;
            if(arr.size()*q <= 90000000){
                for(auto l: arr){
                    if(l.first == 1){
                        int o = l.second;
                        o = min(l.second,k);
                        ans=max(o,ans);
                    }
                }
            }
            else{
                if(arr.size() == 1){
                    if(arr.begin()->first == 1)ans=arr.begin()->second;
                }else{
                    if(arr.begin()->first == 1 && arr.rbegin()->first == 1 && arr.begin()->second+arr.rbegin()->second == mx1){
                        ans = mx2;
                    }else{
                        ans = mx1;
                    }
                    if(arr.begin()->first == 1)ans=max(arr.begin()->second,ans);
                    if(arr.rbegin()->first == 1)ans=max(arr.rbegin()->second,ans);
                }
            }
            cout  << min(ans,k) << "\n";
        }
    }
}

int main(){
    FAST
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}

 