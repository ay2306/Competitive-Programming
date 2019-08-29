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
    int k = 1;
    string ar;
    cin >> ar;
    while(1){
        int *arr = new int[ar.length()];
        arr[0] = 0;
        for(int i = 1; i < ar.length(); ++i){
            if(ar[i] == ar[i-1]){
                arr[i] = arr[i-1];
            }else{
                arr[i] = i;
            }
        }
        printf("Case %d:\n",k++);
        int q;
        cin >> q;
        while(q--){
            int a,b;
            cin >> a >> b;
            if(a > b)swap(a,b);
            // cout << a << " " << b << "\n";
            // cout << arr[a] << " " << arr[b] << "\n";
            // for(int i = a; i <= b; ++i)cout << ar[i];
            // cout << "\n";
            if(arr[b] > a){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }
        if(cin >> ar){

        }else{
            break;
        }
    }
    return 0;
}