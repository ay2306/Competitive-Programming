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

vector<int> f(vector<int> v,int x){
    if(x+1 == v.size())return v;
    v = f(v,x+1);    
    swap(v[x],v[x+1]);
    return v;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; ++i)v.pb(i);
    v = f(v,0);
    for(int i = 0; i < n; ++i)cout << v[i] << " ";
    return 0;
}