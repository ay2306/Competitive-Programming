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

bool check(V<int> &arr){
    if(accumulate(arr.begin(),arr.end(),0) == 0)return false;
    return true;
}

void solve(){
    int n;
    cin >> n;
    V<string> arr;
    loop(i,0,n){
        string a;
        cin >> a;
        arr.pb(a);
    }
    string ans = "";
    V<bool> lost(n,false);
    V<int> ind(n,0);
    do{
        int state = 0;
        loop(i,0,n){
            if(lost[i])continue;
            if(arr[i][ind[i]] == 'R')state=(state|4);
            if(arr[i][ind[i]] == 'P')state=(state|2);
            if(arr[i][ind[i]] == 'S')state=(state|1);
        }
        if(state == 0){
            cout << ans << "\n";
            return;
        }
        if(state == 7){
            cout << "IMPOSSIBLE\n";
            return;
        }
        if(state == 6){
            ans+="P";
            loop(i,0,n){
                if(arr[i][ind[i]] == 'R')lost[i] = true;
            }
        }
        if(state == 5){
            ans+="R";
            loop(i,0,n){
                if(arr[i][ind[i]] == 'S')lost[i] = true;
            }
        }
        if(state == 4){
            ans+="P";
            cout << ans << "\n";
            return;
        }
        if(state == 3){
            ans+="S";
            loop(i,0,n){
                if(arr[i][ind[i]] == 'P')lost[i] = true;
            }
        }
        if(state == 2){
            ans+="S";
            cout << ans << "\n";
            return;
        }
        if(state == 1){
            ans+="R";
            cout << ans << "\n";
            return;
        }
        loop(i,0,n){
            ind[i]++;
            if(ind[i] == arr[i].size())ind[i] = 0;
        }
    }while(ans.size() <= 500);
}

int main(){
    int t = 1;
    cin >> t;
    loop(i,1,t+1){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}