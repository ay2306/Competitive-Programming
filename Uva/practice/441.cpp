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
#define MAXN 1001000
using namespace std;
vector<int> arr;

void solve(int i, vector<int> p){
    if(p.size() == 6){
        for(int i = 0; i < p.size(); ++i){
            cout << p[i];
            if(i+1 < 6)cout << " ";
        }
        cout << "\n";
        return;
    }
    if(i >= arr.size())return;
    vector<int> t = p;
    t.pb(arr[i]);
    solve(i+1,t);
    solve(i+1,p);
}

int main(){
    // FILE_READ
    int k = 1;
    while(1){
        int n;
        cin >> n;
        if(n == 0)return 0;
        if(k > 1)cout << "\n";
        arr.assign(n,0);
        for(int i = 0; i < n; ++i)cin >> arr[i];
        sort(arr.begin(),arr.end());
        solve(0,vector<int> ());
        k++;
    }
    return 0;
}