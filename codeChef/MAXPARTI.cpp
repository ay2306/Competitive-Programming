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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

bool cmp(P<int,int> a, P<int,int> b){
    if(a.first > b.first)return true;
    return false;
}

int solve(){
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    P<int,int> *p = new P<int,int>[n];
    loop(i,0,n){
        cin >> arr[i];
        p[i] = mp(arr[i],i);
    }
    sort(p,p+n,cmp);
    int *ar = new int[k];
    for(int i = 0; i < k-1; ++i){
        ar[i] = p[i].second;
    }
    sort(ar,ar+k);
    for(int i = 0; i < k-1; ++i){
        cout << arr[ar[i]] << " ";
    }
    int ind = ar[k-1];
    int mx = arr[ind];
    M<int,int> m;
    for(int i = ind; i < n; ++i){
        m[arr[i]]++;
    }
    // cout << endl;
    for(M<int,int>::RIT itr = m.rbegin(); itr != m.rend(); ++itr){
        // cout << itr->first << " " << itr->second;   
        if(itr->second%2 == 1){
            cout << itr->first;
            return 0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}