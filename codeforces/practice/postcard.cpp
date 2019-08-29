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

int main(){
    string pp;
    cin >> pp;
    int n;
    cin >> n;
    string a = "";
    int j = -1;
    for(int i = 0; i+1 < pp.length(); ++i){
        if(pp[i+1]=='?')continue;
        else if(pp[i] == '*' && j == -1)j = a.size()-1;
        else if(pp[i] != '*' && pp[i] != '?')a+=pp[i];
    }
    a+=(*pp.rbegin());
    if(a.size() == n){
        cout << a << "\n";
        return 0;
    }
    if(j == -1){
        cout << "Impossible\n";
        return 0;
    }
    string ans = "";
    // cout << a << " " <<  j << "\n";
    for(int i = 0; i <= j; ++i)ans+=a[i];
    for(int i = 0; i < n-a.size(); ++i)ans+=a[j];
    for(int i = j+1; i < a.size(); ++i)ans+=a[i];
    cout << ans << "\n";
    return 0;
}