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
    ll ans = 0;
    ll n,k;
    cin >> n >> k;
    V<ll> a(n);
    loop(i,0,n)cin >> a[i];
    for(int i = 0; i < n; ++i){
        priority_queue<ll, V<ll> > left;
        priority_queue<ll, V<ll>, greater<ll> > right;
        map<ll,ll> m;
        for(int j = i; j < n; ++j){
            ll val;
            m[a[j]]++;
            left.push(a[j]);
            ll mult = k/(j-i+1);
            ll length = j-i+1;
            if(k%length != 0)mult++;
            ll index = (k-1)/mult + 1;
            if(k%length == 0)val = m.rbegin()->first;
            else if(index < 40){
                ll o = mult*(j-i+1);
                ll pp = 0;
                auto lp = m.begin();
                auto l = m.rbegin();
                for(; l!=m.rend(); ++l){
                    if(o - (l->second * mult) >= k)o-=(l->second * mult);
                    else{
                        val = l->first;
                        break;
                    }
                    if(lp->second*mult + pp < k)pp+=(lp->second*mult);
                    else{
                        val = lp->first;
                        break;
                    }
                    lp++;
                }
            }
            else{
                while(left.size() > index){
                    right.push(left.top());
                    left.pop();
                }
                while(left.size() < index){
                    left.push(right.top());
                    right.pop();
                }
                val = left.top();
            }
            ll freq = m[val];
            freq = m[freq];
            if(freq > 0){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
};