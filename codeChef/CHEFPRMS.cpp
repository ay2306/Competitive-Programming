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
// #define MAXN 25
using namespace std;
const int maxn = 210;
vector<int>primes;
vector<int> prs;
vector<int> prs1;

void solve(){
    int n;
    cin >> n;
    int i = 0;
    int j = primes.size()-1;
    while(i <= j){
        if(primes[i] + primes[j] == n)break;
        else if(primes[i] + primes[j] > n)j--;
        else if(primes[i] + primes[j] < n)++i;
    }
    if(j < 0 || i >= primes.size()){
        cout << "NO\n";
    }else{
        if(primes[i] + primes[j] == n){
            // cout << primes[i] << " " << primes[j] << " \n";
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    // if(binary_search(primes.begin(),primes.end(),n)){
    //     cout << "YES\n";
    // }else{
    //     cout << "NO\n";
    // }
}

int main(){
    FILE_READ
    int arr[maxn] = {0};
    for(int i = 2; i < maxn; ++i)if(arr[i] == 0)for(int j = 2; i*j < maxn; ++j)arr[i*j]++;
    for(int i = 2; i < maxn; ++i)if(arr[i] == 0)prs.pb(i);
    for(int i = 0; i < prs.size(); ++i){
        for(int j = i+1; j < prs.size(); ++j){
            primes.pb(prs[i]*prs[j]);
        }
    }
    sort(primes.begin(),primes.end());
    // for(int i = 0; i < prs1.size(); ++i){
    //     for(int j = i; j < prs1.size(); ++j){
    //         primes.insert(prs1[i]+prs1[j]);
    //     }
    // }
    // for(auto i : primes){
    //     cout << i << " ";
    // }
    // cout << "\n";
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}