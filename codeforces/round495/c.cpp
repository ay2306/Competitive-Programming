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

int main(){
    int n;
    cin >> n;
    M<int,int> l,r;
    int *a = new int[n];
    int *R = new int[n];
    for(int i = 0; i < n; ++i)cin >> a[i];
    R[n-1] = 1;
    r.insert(mp(a[n-1],1));
    for(int i = n-2; i >= 0; --i){
        if(r.count(a[i])==0){
            r.insert(mp(a[i],1));
            R[i]=R[i+1]+1;
        }else{
            R[i] = R[i+1];
        }
    }   
    ll ans = 0;
    for(int i = 0; i+1 < n; ++i){
        if(l.count(a[i])==0){
            ans+=R[i+1];
            l.insert(mp(a[i],1));
        }
    }
    cout << ans;    
    return 0;
}