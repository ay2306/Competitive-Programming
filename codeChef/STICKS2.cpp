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
    int n,k;
    cin >> n >> k;
    if(n <4 || k < 4){
        cout << "-1\n";
        return;
    }
    V<P<ll,ll> > arr;
    V<P<ll,int> > doub;
    int uq = n;
    M<ll,int> m;
    M<ll,int>ind;
    M<ll,int>d_ind;
    ll u = 1;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        if(m[a] == 0){
            // u++;
            m[a]++;
            ind[a] = arr.size();
            arr.pb(mp(a,1));
        }else{
            arr[ind[a]].second++;
            uq--;
            if(arr[ind[a]].second == 2){
                uq--;
                u++;
                d_ind[a] = doub.size();
                doub.pb(mp(a,1));
            }
            if(arr[ind[a]].second == 4){
                u++;
            }
            doub[d_ind[a]].second++;
        }
    }
    for(int i = 0 ; i < doub.size(); ++i)doub[i].second--;
    // for(int i = 0; i < arr.size(); ++i){
    //     cout << "( " << arr[i].first << ", " << arr[i].second << "), "; 
    // }
    // cout << endl;
    // cout << uq + doub.size() + 1 << endl;
    if(uq+doub.size()+1 >= k){
        cout << "-1"<< endl;
        return;
    }
    k-=uq;
    sort(doub.begin(),doub.end());
    ll a,b;
    a=-1;b=-1;
    int i = 0;

    while(k){
        int p = doub[i].second;
        if(k-p <= 0){
            a = doub[i].first;
            b = doub[i].first;
        }if(k-p == 1){
            a = doub[i+1].first;
            b = doub[i].first;
        }if(k-p == 2){
            a = doub[i+1].first;
            b = doub[i].first;
        }if(k-p == 3){
            a = doub[i+1].first;
            b = doub[i+1].first;
        }
        if(a!=-1 && b!=-1)break;
        ++i;
        k-=p;
    }
    
    cout << a*b << endl;
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}