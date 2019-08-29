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
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 1001000
using namespace std;

void solve(){
    string a;
    cin >> a;
    V<int> lps(a.size(),0);
    int j = 0;
    loop(i,1,a.size()){
        if(a[i] == a[j]){
            j++;
            lps[i] = j;
        }else{
            while(j > 0 && a[i] != a[j]){
                j = lps[j-1];
            }
            if(a[i] == a[j]){
                j++;
                lps[i] = j;
            }else{
                lps[i] = 0;
            }
        }
    }
    if(lps[a.size()-1] == 0){
        cout << a.size() << "\n";
        return ;
    }
    int res = a.size() - lps[a.size()-1];
    if(a.size()%res != 0){
        cout << a.size() << "\n";
        return ;
    }
    cout << res << "\n";
}

int main(){
    // FILE_READ_OUT
    int t;
    cin >> t;
    while(t--){
        solve();
        if(t > 0)printf("\n");
    }
    return 0;
}