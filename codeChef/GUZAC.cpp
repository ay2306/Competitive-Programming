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
    ll n,k,x;
    cin >> n >> k >> x;
    ll mn = LLONG_MAX;
    ll *arr = new ll[k+1];
    map<ll,int> m;
    loop(i,1,k+1){
        cin >> arr[i];
        mn = min(arr[i],mn);
        m[arr[i]]++;
    }
    ll max_term = mn+x;
    if(max_term >= 1000000000)max_term = 1000000000;
    ll max_sum = ((max_term)*(max_term+1))/2;
    // cout << max_sum << endl;
    ll min_term = ((mn+x)-(n-k));
    ll min_sum = ((min_term)*(min_term+1))/2;
    // cout << min_sum << endl;
    ll sum = max_sum-min_sum;
    // cout << sum << endl;
    min_term++;
    // cout << min_term << endl;
    sort(arr+1,arr+k+1);
    for(int i = k; i > 0; --i){
        // cout << arr[i] << "   ";
        if(arr[i] >= min_term){
            while(m[min_term]!=0)min_term--;
            sum+=min_term;
            // cout << sum << " " << min_term << endl;
        }else{
            sum+=arr[i];
            // cout << sum << " " << min_term << endl;
        }
    }
    cout << sum << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}