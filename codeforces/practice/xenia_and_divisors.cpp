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
    int arr[8] = {0};
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr[a]++;
        if(a != 1 && a != 2 && a != 3 && a != 4 && a != 6 ){
            cout << "-1";
            return 0;
        }
    }
    if(arr[1] != n/3){
        cout << "-1";
        return 0;
    }
    if(arr[2]+arr[3] != arr[4]+arr[6] || arr[2] < arr[4]){
        cout << "-1";
        return 0;
    }
    int ans[3] = {0};
    ans[0]+=arr[4];
    arr[2]-=arr[4];
    ans[1]+=arr[2];
    ans[2]+=arr[3];
    for(int i = 0; i < ans[0]; ++i){
        cout << "1 2 4\n";
    }
    for(int i = 0; i < ans[1]; ++i){
        cout << "1 2 6\n";
    }
    for(int i = 0; i < ans[2]; ++i){
        cout << "1 3 6\n";
    }
    return 0;
}