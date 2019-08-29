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
string a;
int n;
vector<int> arr;

int main(){
    cin >> a;
    n = a.length();
    // int c = 0;
    arr = vector<int> (n,0);
    vector<int> c(n,0);
    c[n-1] = (a[n-1] == 'a');
    for(int i = n-2; i >= 0; --i){
        c[i] = c[i+1] + (a[i] == 'a');
    }
    for(int i = 0; i < n; ++i){
        if(a[i] == 'b' && i+1 < n && a[i+1] == 'a' && a[0]=='a'){
            reverse(a.begin(),a.begin()+1+i);
            arr[i] = 1;
            // cout << a << "\n";
        }
        else if(a[i] == 'a' && (i+1 == n || a[i+1] == 'b') && a[0]=='b'){
            arr[i] = 1;
            reverse(a.begin(),a.begin()+1+i);
            // cout << a << "\n";
        }
    }
    // cout << a << "\n";
    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}