#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
unordered_map<char,char> m1;

vector<int> string_match(string &a, string &b){
    V<int> ans;
    V<int> lps(b.size(),0);
    int j = 0;
    int i = 1;
    while(i < b.size()){
        if(b[i] == b[j]){
            j++;
            lps[i] = j;
            i++;
        }else{
            if(j == 0){
                lps[i] = 0;
                i++;
            }else{
                j = lps[j-1];
            }
        }
    }
    i = 0;
    j = 0;
    while(i < a.length()){
        if(a[i] == b[j]){
            ++j;
            ++i;
            if(j == b.size()){
                ans.pb(i);
                j = lps[j-1];
            }
        }else{
            if( j == 0){
                i++;
            }else{
                j = lps[j-1];
            }
        }
    }
    // cout << "ans: ";
    // for(auto i: ans)cout << i << " ";
    // cout << "\n";
    return ans;
}

int main(){
    // FILE_READ_IN
    FAST
    m1['a'] = '2';
    m1['b'] = '2';
    m1['c'] = '2';
    m1['d'] = '3';
    m1['e'] = '3';
    m1['f'] = '3';
    m1['g'] = '4';
    m1['h'] = '4';
    m1['i'] = '1';
    m1['j'] = '1';
    m1['k'] = '5';
    m1['l'] = '5';
    m1['m'] = '6';
    m1['n'] = '6';
    m1['o'] = '0';
    m1['p'] = '7';
    m1['q'] = '0';
    m1['r'] = '7';
    m1['s'] = '7';
    m1['t'] = '8';
    m1['u'] = '8';
    m1['v'] = '8';
    m1['w'] = '9';
    m1['x'] = '9';
    m1['y'] = '9';
    m1['z'] = '0';
    while(1){
        int dp[101];
        string a;
        cin >> a;
        // cout << a << "\n";
        V<V<int>> mat;
        if(a == "-1")break;
        int n;
        cin >> n;
        unordered_map<char,int> m;
        for(char i: a)m[i]++;
        V<string> arr;
        V<V<int>> ans(a.size()+1    );
        unordered_map<string,string> ulta;
        loop(i,0,n){
            string b;
            cin >> b;
            string d = b;
            unordered_map<char,int> m2;
            for(auto &j: b){
                j=m1[j];
            }
            if(ulta.find(b) != ulta.end())continue;
            // cout << b << ": ";
            arr.pb(b);
            V<int> op = string_match(a,b);
            // for(int i: op)cout << i << " ";
            // cout << "\n";
            if(op.size() == 0){
                arr.pop_back();
            }else{
                ulta[b] = d;
                mat.pb(op);
            }
        }
        fill(dp,dp+a.size()+1,inf);
        dp[0] = 0;
        for(int i = 1; i <= a.size(); ++i){
            for(int j = 0; j < arr.size(); ++j){
                if(arr[j].size() <= i){
                    // cout << i << " " << arr[j].size() << " " << arr[j] << " " << ulta[arr[j]] << " (";
                    // for(int i : mat[j])cout << i << ", ";
                    // cout << ") ";
                    // cout << dp[i-arr[j].size()] << " " << dp[i] << "\n";
                    if(binary_search(all(mat[j]),i)){
                        if(dp[i] > dp[i-arr[j].size()]+1){
                            dp[i] = dp[i-arr[j].size()]+1;
                            ans[i] = ans[i-arr[j].size()];
                            ans[i].pb(j);
                        }
                    }
                }
            }
        }
        // cout << "dp : ";
        // for(int i = 0; i <= a.size(); i++)cout << dp[i] << " ";
        // cout << "\n";
        if(dp[a.size()] == inf){
            cout << "No solution.\n";
        }else{
            for(auto i: ans[a.size()]){
                cout << ulta[arr[i]] << " ";
            }
            cout << "\n";
        }
    }
   return 0;
}