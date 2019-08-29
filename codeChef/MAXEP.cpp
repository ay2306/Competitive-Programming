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
    int n,c;
    cin >> n >> c;
    int l = 1;
    int r = n;
    int ans = 1;
    while(l+20 <= r){
        int diff = r-l;
        diff/=10;
        int curr = l;
        while(curr <= r){
            cout << "1 " << curr << endl;
            int res;
            cin >> res;
            if(res == 1){
                if(curr == 1){
                    cout << "3 1\n";
                    return;
                }
                cout << "2" << endl;
                l = curr-diff;
                r = curr;
                break;
            }
            if(curr == r){
                break;
            }
            curr += diff;
            if(curr > r)curr = r;
        }
    }    
    for(int i = l; i <= r+1; ++i){
        cout << "1 " << i << endl;
        int res;
        cin >> res;
        if(res == 1){
            cout << "2\n3 " << i << endl;
            return; 
        }
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}