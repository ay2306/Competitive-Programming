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

void solve(){
    double l1,h1,l2,h2;
    cin >> l1 >> h1 >> l2 >> h2;
    if(l1 < h1)swap(l1,h1);
    if(l2 < h2)swap(l2,h2);
    if(l2 < l1 && h2 < h1){
        cout << "Escape is possible.\n";
    }else{
        double k = (l2*l2) + (h2*h2) - (l1*l1) - (h1*h1);
        k = k/(2*l1*h1);
        if(k>0 && k<sqrt(2)){
            cout << "Escape is possible.\n";
        }else{
            cout << "Box cannot be dropped.\n";
        }
    }
}

int main(){
    // FILE_READ
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}