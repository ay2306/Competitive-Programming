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
    int arr[2] = {0};
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(a)arr[1]++;
        else arr[0]++;
    }
    arr[1]/=9;
    if(arr[1] > 0 && arr[0] > 0){
        for(int i = 0; i < 9*arr[1]; ++i)cout << "5";
        for(int i = 0; i < arr[0]; ++i)cout << "0";
    }
    else if(arr[1] == 0 && arr[0] > 0){
        cout << "0";
    }
    else if((arr[1] == 0 && arr[0] == 0) || (arr[1] > 0 && arr[0] == 0)){
        cout << "-1";
    }
    return 0;
}