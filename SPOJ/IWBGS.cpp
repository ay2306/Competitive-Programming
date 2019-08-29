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

string add(string a, string b){
    while(a.size() < b.size())a = "0" + a;
    while(a.size() > b.size())b = "0" + b;
    string c = "";
    int carry = 0;
    for(int i = a.size()-1; i >= 0; --i){
        int e = a[i] - '0';
        int f = b[i] - '0';
        e = e+f+carry;
        char p = (e%10)+'0';
        c+=p;
        carry = e/10;
    }
    if(carry){
        char p = (carry)+'0';
        c+=p;
    }
    reverse(c.begin(),c.end());
    return c;
}

int main(){
    int t = 1;
    int n;
    cin >> n;
    V<V<string> > dp(n+1,V<string> (2,"0"));
    dp[1][0] = "1";
    dp[1][1] = "1";
    for(int i = 2; i <= n; ++i){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = add(dp[i-1][1],dp[i-1][0]);
    }
    cout << add(dp[n][0],dp[n][1]);
    return 0;
}