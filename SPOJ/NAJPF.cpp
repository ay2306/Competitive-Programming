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
#define MAXN 1000010
using namespace std;
int lps[MAXN];

void setLPS(string &pat){
    int i = 1;
    int j = 0;
    lps[0] = 0;
    while(i < pat.size()){
        if(pat[i] == pat[j]){
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
}

void solve(){
    V<int> ans;
    string pattern,text;
    cin >> text >> pattern;
    setLPS(pattern);
    int i = 0;
    int j = 0;
    while(i < text.size()){
        if(pattern[j] == text[i]){
            i++;
            j++;
            if(j == pattern.size()){
                ans.pb(i-j);
                j = lps[j-1];
            }
        }else{
            if(j == 0)i++;
            else j = lps[j-1];
        }
    }
    if(ans.size() == 0){
        cout << "Not Found\n";
        return;
    }
    cout << ans.size() << "\n";
    for(auto &k: ans)cout << k+1 << " ";
    cout << "\n";
}

int main(){
    // FILE_READ_OUT
    FAST
    int t = 1;
    cin >> t;
    while(t--){solve();if(t)printf("\n");}
    return 0;
}