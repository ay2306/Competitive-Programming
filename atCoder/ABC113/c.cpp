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

string getString(int f, int s){
    string ans = "";
    for(int i = 0; i < 12; ++i)ans+="0";
    int i = 5;
    while(f){
        ans[i--]=(char((f%10) + '0'));
        f/=10;
    }
    i = 11;
    while(s){
        ans[i--]=(char((s%10) + '0'));
        s/=10;
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    map<int,vector<pair<ll,int> > > m;
    for(int i = 0; i < k; ++i){
        ll a,b;
        cin >> a >> b;
        if(m.find(a) == m.end())m[a] = vector<pair<ll,int> > ();
        m[a].pb(mp(b,i));
    } 
    // for(auto i: m){
    // }
    vector<string> ans(k,"");
    for(auto i: m){
        int l = 1;
        sort(i.second.begin(),i.second.end());
        for(auto j: i.second){
            // cout << j.first << " " << j.second << "\n";
            ans[j.second] = getString(i.first,l++);
        }
    }
    for(auto i: ans){
        cout << i << "\n";
    }
    return 0;
}