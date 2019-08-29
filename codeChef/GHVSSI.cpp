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

int checkIfWin(vector<int> arr, ll sum, int i, int p){
    if(i == arr.size())return (p^1);
    for(int j = i; j < arr.size(); ++j){
        if((arr[j] + sum )%4 != 2){
            int res = checkIfWin(arr,arr[j]+sum,i+1,(p^1));
            if(res == p)return p;
        }
    }
    return (p^1);
}

void solve(){
    int n;
    cin >> n;
    unordered_map<int,int> m;
    ll *arr = new ll[n];
    vector<int> v;
    loop(i,0,n){
        cin >> arr[i];
        v.pb(arr[i]%4);
    }
    int res = checkIfWin(v,0,0,1);
    if(res == 1)cout << "Ghayeeth\n";
    else cout << "Siroj\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
// void solve(){
//     int n;
//     cin >> n;
//     int q[4] = {0};
//     loop(i,0,n){
//         int a;
//         cin >> a;
//         q[a%4]++;
//     }
//     ll z = 0;
//     int odd = 2*(min(q[1],q[3]));
//     int even = q[0];
//     int moves = odd + even;
//     if(moves%2 == 1)cout << "Ghayneet\n";
//     else cout << "Siroj\n";
// }
// int main(){
//     int t = 1;
//     cin >> t;
//     while(t--)solve();
//     return 0;
// }