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

void solve_for_simple(V<bool> &row, V<bool> &col){

}


void solve(){
    string a,b;
    cin >> a >> b;
    V<bool> col(a.size());
    V<bool> col1(a.size());
    col[0] = (a[0] == '1' || b[0] == '1');
    loop(i,1,a.size()){
        col[i] = (!col[i-1] || a[i] == '1');
    }
    V<bool> row(b.size());
    V<bool> row1(b.size());
    row[0] = col[0];
    loop(i,1,b.size()){
        row[i] = (!row[i-1] || b[i] == '1');
    }
    if(a.size() == 1 || b.size() == 1){solve_for_simple(row,col);return;}
    col1[0] = row[1];
    loop(i,1,a.size()){
        col1[i] = (!col[i] || !col1[i-1]);
    }
    row1[0] = col[1];
    loop(i,1,a.size()){
        col1[i] = (!col[i] || !col1[i-1]);
    }
    string ans = "";
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(a == 0){
            if(col[b])ans+="1";
            else ans+="0";
        }else if(b == 0){
            if(row[a])ans+="1";
            else ans+="0";
        }else{
            int diff = a-1;
            if(b-diff < 1){
                
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}