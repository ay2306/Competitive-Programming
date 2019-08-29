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


void solve(){
    string a;
    cin >> a;
    V<int> num;
    V<char> op;
    loop(i,0,a.size()){
        if(i%2 == 0){
            num.pb(atoi(&a[i]));
        }else{
            op.pb(a[i]);
        }
    }
    V<V<ll> > min_cost(num.size()+1,V<ll>(num.size()+1,LLONG_MAX));
    V<V<ll> > max_cost(num.size()+1,V<ll>(num.size()+1,0));
    loop(i,0,num.size())min_cost[i][i] = max_cost[i][i] = num[i];

    for(int sz = 2; sz <= num.size(); ++sz){
        for(int i = 0; i <= num.size() - sz ; ++i){
            int j = i+sz-1;
            for(int k = i; k < j && k < op.size(); ++k){
                ll min_tmp = 0;
                ll max_tmp = 0;
                if(op[k] == '+'){
                    min_tmp = min_cost[i][k] + min_cost[k+1][j];
                    max_tmp = max_cost[i][k] + max_cost[k+1][j];
                }
                if(op[k] == '*'){
                    min_tmp = min_cost[i][k] * min_cost[k+1][j];
                    max_tmp = max_cost[i][k] * max_cost[k+1][j];
                }
                min_cost[i][j] = min(min_cost[i][j],min_tmp);
                max_cost[i][j] = max(max_cost[i][j],max_tmp);
            }
        }
    }
    cout << max_cost[0][num.size()-1] << " " << min_cost[0][num.size()-1] << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}