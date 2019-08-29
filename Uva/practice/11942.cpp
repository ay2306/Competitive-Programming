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
#define MAXN 1001000
using namespace std;
int main(){
    // FILE_READ
    cout << "Lumberjacks:\n";
    int t;
    cin >> t;
    while(t--){
        vector<ll> arr(10),arr1(10),arr2(10);
        for(int i = 0; i < 10; ++i){
            cin >> arr[i];
            arr1[i] = arr[i];
            arr2[i] = arr[i];
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end(),greater<ll>());
        int k1 = 1; 
        int k2 = 1;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] != arr1[i])k1 = 0;
            if(arr[i] != arr2[i])k2 = 0;
        }
        if(k1 || k2){
            cout << "Ordered\n";
        }else{
            cout << "Unordered\n";
        }
        // for(auto i: arr)cout << i << " ";
        // cout << endl;
    }
    return 0;
}