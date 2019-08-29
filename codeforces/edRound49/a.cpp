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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int j = s.length()-1;
    while(i < j){
        char a = s[i];
        char b = s[j];
        // cout << a+1 << " " << b-1 << endl;
        if(a == b){
            ++i;
            --j;
            continue;
        }
        else if(a-1 >= 'a' && b+1 <= 'z' && (a-1 == b+1)){
            ++i;
            --j;
            continue;
        }
        else if(a+1 <= 'z' && b-1 >= 'a' && (b-1 == a+1)){
            ++i;
            --j;
            continue;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}