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

int main(){
    unordered_map<char,list<int> > left;
    unordered_map<char,list<int> > right;
    unordered_map<int,int> pl;
    unordered_map<int,int> pr;
    V<PII> ans;
    int n;
    cin >> n;
    string a;
    cin >> a;
    for(int i = 0;i < a.size(); ++i){
        left[a[i]].pb(i);
    }
    string b;
    cin >> b;
    for(int i = 0; i < b.size(); ++i){
        if(b[i] == '?')right['?'].pb(i);
        else if(left[b[i]].size() != 0){
            ans.pb(mp(*left[b[i]].begin(),i));
            pl[*left[b[i]].begin()]++;
            pr[i]++;
            left[b[i]].pop_front();
        }else{
            right[b[i]].pb(i);
        }
    }
    list<int> l,r;
    for(auto i: left){
        if(i.first == '?')continue;
        for(auto j: i.second)l.pb(j);
    }
    for(auto i: right){
        if(i.first == '?')continue;
        for(auto j: i.second)r.pb(j);
    }
    while(r.size() && left['?'].size()){
        ans.pb(mp(*left['?'].begin(),*r.begin()));
        left['?'].pop_front();
        r.pop_front();
    }
    while(l.size() && right['?'].size()){
        ans.pb(mp(*l.begin(),*right['?'].begin()));
        right['?'].pop_front();
        l.pop_front();
    }
    while(left['?'].size() && right['?'].size()){
        ans.pb(mp(*left['?'].begin(),*right['?'].begin()));
        right['?'].pop_front();
        left['?'].pop_front();
    }
    cout << ans.size() << "\n";
    for(auto i: ans){
        cout << i.F+1 << " " << i.S+1 << "\n";
    }
    return 0;
}