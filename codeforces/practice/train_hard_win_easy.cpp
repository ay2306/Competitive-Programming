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
V<P<PLL,int> > arr;
V<P<PLL,int> > arr1;

bool cmp(P<PLL,int> a, P<PLL,int> b){
    if(a.F.F < b.F.F)return true;
    if(a.F.F > b.F.F)return false;
    return false;
}

int main(){
    FAST
    int n,m;
    cin >> n >> m;
    loop(i,0,n){
        ll a,b;
        cin >> a >> b;
        arr.pb(mp(mp(a-b,b),i));
        arr1.pb(mp(mp(a,b),i));
    } 
    sort(arr.begin(),arr.end(),cmp);
    // for(auto i: arr){
    //     printf("(%lld, %lld, %d) ", i.F.F, i.F.S, i.S);
    // }
    // cout << "\n";
    // for(auto i: arr1){
    //     printf("(%lld, %lld, %d) ", i.F.F, i.F.S, i.S);
    // }
    V<ll> pf(n,0);
    V<ll> ss(n,0);
    V<ll> ps(n,0);
    pf[0] = arr[0].F.F;
    ps[0] = arr[0].F.S;
    ss[n-1] = arr[n-1].F.S;
    loop(i,1,n){
        pf[i] = pf[i-1]+arr[i].F.F;
        ps[i] = ps[i-1]+arr[i].F.S;
        ss[n-1-i] = ss[n-i]+arr[n-i-1].F.S;
    }
    V<ll> ans(n);
    // cout << "\n";
    // for(auto i : ss){
    //     cout << i << " ";
    // }
    unordered_map<int,int> sorted_index;
    for(int i = 0; i < n; ++i){
        int index = arr[i].S;
        sorted_index[index] = i;
        if(i == 0){
            ans[index] = (arr[i].F.F * (n-i-1) + (n-1)*arr[i].F.S + ss[i+1]);
        }else if(i == n-1){
            ans[index] = (arr[i].F.S*i + pf[i-1] + ps[i-1]);
        }else{
            ans[index] = (pf[i-1] + ps[i-1] + (n-i-1)*arr[i].F.F + (n-1)*(arr[i].F.S) + ss[i+1]);
        }
    }
    // cout << "\n";
    // for(auto i : ans){
    //     cout << i << " ";
    // }
    // cout << "\n";
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        // a = sorted_index[a];
        // b = sorted_index[b];
        // if(a > b)swap(a,b);
        ans[a]-=(min(arr1[a].F.F + arr1[b].F.S,arr1[a].F.S+arr1[b].F.F));
        ans[b]-=(min(arr1[a].F.F + arr1[b].F.S,arr1[a].F.S+arr1[b].F.F));
    }
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}