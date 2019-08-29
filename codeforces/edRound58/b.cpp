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

void solve(string s){
    int a = -1;
    int b = -1;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == ':'){
            a = i;
            break;
        }
    }
    for(int i = s.size()-1; i > a; --i){
        if(s[i] == ':'){
            b = i;
            break;
        }
    }
    // cout << s << "  " <<  a << " " << b << "\n";
    if(a == -1 || b == -1){
        cout << "-1";
        return ;
    }
    int ans = 4;
    for(int i = a; i < b; ++i){
        if(s[i] == '|')ans++;
    }
    cout << ans;
}

int main(){
    string s;
    cin >> s;
    int a = -1;
    int b = -1;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '['){
            a = i;
            break;
        }
    }
    for(int i = s.size()-1; i > a; --i){
        if(s[i] == ']'){
            b = i;
            break;
        }
    }
    if(a == -1 || b == -1){
        cout << "-1";
        return 0;
    }
    string ans = "[";
    // cout << 
    for(int i = a+1; i < b; ++i){
        if(s[i] == '|' || s[i] == ':')ans+=s[i];
    }
    s+=']';
    solve(ans);
    return 0;
}