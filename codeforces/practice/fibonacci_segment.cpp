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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    int n;
    cin >> n;
    ull *arr = new ull[n];   
    ull mx=0,c=2;
    cin >> arr[0];
    if(n==1){
        cout << "1";
        return 0;
    }
    cin >> arr[1];
    if(n==2){
        cout << "2";
        return 0;
    }
    for(int i = 2; i < n; ++i){
        cin >> arr[i];
        if(arr[i] == arr[i-1]+arr[i-2]){
            c++;
        }else{
            // cout << arr[i]  << " != " << arr[i-1] << " + " << arr[i-2] << endl;
            if(c > mx)mx = c;
            c = 2;
        }
    }
    if(c > mx)mx = c;
    cout << mx;
    return 0;
}