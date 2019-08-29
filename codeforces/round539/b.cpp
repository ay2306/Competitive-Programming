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
    vector<vector<PII> > arr(101,vector<PII>()) ;
    for(int i = 1; i <= 100; i++){
        for(int j = i; j <= 100; ++j){
            for(int x = 1; x <= 100; ++x){
                if(j%x != 0)continue;
                arr[j].pb(mp(0-i-j+i*x+(j/x),i));
            }
        }
    }
    int n;
    cin >> n;
    int s = 0;
    int a;
    unordered_map<int,int> p;
    loop(i,0,n){
        cin >> a;
        p[a]++;
        s+=a;
    }
    int mn = 0;
    for(auto i: p){
        for(auto j: arr[i.first]){
            if(p.find(j.second) != p.end()){
                if(((j.second == i.first) && (p[i.first] > 1)) || (i.first != j.second)){
                    mn = min(j.first,mn);
                }
            }
        }
    }
    cout << s + mn;
    return 0;
}