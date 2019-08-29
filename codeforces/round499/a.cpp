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

int main(){
    int n,k;
    cin >> n >> k;
    int j = 1;
    string a;
    cin >> a;
    sort(a.begin(),a.end());
    int ans = a[0]-'a'+1;
    string b = "";
    b+=a[0];
    for(int i = 1; i < n; i++){
        if(b.length() == k)break;
        // cout << *b.rbegin();
        if(a[i] <= *b.rbegin() +1 )continue;
        b+=a[i];
        ans+=(a[i]-'a'+1);
        ++j;
    }
    if(b.length() != k){
        cout << "-1";
    }else{
        cout << ans;
        // cout << endl << b;
    }
    return 0;
}