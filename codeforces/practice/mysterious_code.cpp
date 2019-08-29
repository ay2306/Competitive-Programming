/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
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
using namespace std;

const ll maxn = 1e5;
const ll inf = 1e9+7;

void init(string &s, V<V<int>> &nxt){
    int n = s.size()-2;
    V<int> lps(s.size() + 10,0);
    //Normal lps calculations 1 based index
    for(int i = 2; i <= n; ++i){
        int cur = lps[i-1];
        while(cur > 0 && s[cur+1] != s[i]){
            cur = lps[cur];
        }
        if(s[cur+1] == s[i]){
            ++cur;
        }
        lps[i] = cur;
    }
    for(int i = 0; i <= n; ++i){
        for(char c = 'a'; c <= 'z'; ++c){
            //As this is the largest possible prefix length
            int cur = i;
            //LPS CALCULATION
            while(cur > 0 && s[cur+1] != c){
                cur = lps[cur];
            }
            if(s[cur+1] == c){
                ++cur;
            }
            nxt[i][c-'a'] = cur;
        }
    }
}

int main(){
    string code,s,t;
    cin >> code >> s >> t;
    int k = code.size(), n = s.size(), m = t.size();
    code = " " + code;
    s = " " + s;
    t = " " + t;
    code+="\n";
    s+="\n";
    t+="\n";
    V<V<int>> nxt_s(n+1,V<int> (26,0));
    V<V<int>> nxt_t(m+1,V<int> (26,0));
    V<V<V<int>>> dp(k+1,V<V<int>>(n+1,V<int>(m+1,-inf)));
    init(s,nxt_s);
    init(t,nxt_t);
    dp[0][0][0] = 0;
    for(int i = 0; i < k; ++i){
        for(int ks = 0; ks <= n; ++ks){
                    int ns = nxt_s[ks][c-'a'];
            for(int kt = 0; kt <= m; ++kt){
                for(char c = 'a'; c <= 'z'; ++c){
                    int nt = nxt_t[kt][c-'a'];
                    int tmp = dp[i][ks][kt] + (ns == n) - (nt == m);
                    dp[i+1][ns][nt] = max(dp[i+1][ns][nt],tmp);
                }
            }
        }
    }
    int ans = -inf;
    for(int ks = 0; ks <= n; ++ks){
        for(int kt = 0; kt <= m; ++kt){
            ans = max(ans,dp[k][ks][kt]);
        }
    }
    cout << ans;
  return 0;
}
