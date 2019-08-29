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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int bs(V<ll> v, ll e){
    ll low = 0;
    ll high = v.size()-1;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(v[mid] == e)return mid;
        if(v[mid] > e)high = mid-1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    int pos=0;
    ll mn,mx,n,x,y;
    cin >> n;
    if(n == 1){
        cin >> x;
        cout << "no";
        return 0;
    }   
    if(n == 2){
        cin >> x >> y;
        cout << "no";
        return 0;
    }   
    V<ll> v;
    cin >> x >> y;
    v.pb(x);
    v.pb(y);
    for(int i = 2; i < n; ++i){
        // cout << i << " " << n << endl;
        cin >> x;
        v.pb(x);
        sort(v.begin(),v.end());
        ll li = bs(v,y);
        ll ci = bs(v,x);
        // cout << ci << " " << li << "  cl" << endl;
        y = x;
        if(ci == li+1 || ci == li-1){
            continue;
        }else if((ci == 0 && li == v.size()-1) || (li == 0 && ci == v.size()-1)){
            continue;
        }else{
            pos = 1;
        }
    }
    if(pos)cout << "yes";
    else cout << "no";
    return 0;
}