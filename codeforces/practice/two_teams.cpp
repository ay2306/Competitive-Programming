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
    int n,k;
    cin >> n >> k;
    V<PII> arr(n);
    loop(i,0,n){
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr.rbegin(),arr.rend());
    queue<int> q;
    loop(i,0,n)q.push(arr[i].S);
    set<int> s;
    loop(i,0,n)s.insert(i);
    vector<int> ans(n,0);
    int p = 0;
    while(s.size()){
        while(q.size() && s.find(q.front()) == s.end())q.pop();
        int pos = q.front();
        auto it = s.find(pos);
        V<set<int>::iterator> items;
        for(int i = 0; i <= k; ++i){
            items.pb(it);
            if(it == s.begin())break;
            it--;
        }
        it = s.find(pos);
        ++it;
        loop(i,0,k){
            if(it==s.end())break;
            items.pb(it);
            it++;
        }
        for(auto i: items){
            // cout << *i << " ";
            ans[*i] = p;
            s.erase(i);
        }
        // cout << endl;
        p = 1-p;
    }
    loop(i,0,n){
        cout << ans[i]+1;
    }
  return 0;
}