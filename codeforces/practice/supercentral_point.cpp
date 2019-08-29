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
    PII *arr = new PII[n];
    for(int i=0,a,b; i < n; ++i){
        cin >> a >> b;
        arr[i] = mp(a,b);
    }
    int c = 0;
    for(int i = 0; i < n; ++i){
        int a[4] = {0,0,0,0};
        for(int j = 0; j < n; ++j){
            if(i == j)continue;
            if(arr[i].first == arr[j].first && arr[i].second < arr[j].second)a[0]++;
            else if(arr[i].first == arr[j].first && arr[i].second > arr[j].second)a[1]++;
            else if(arr[i].first < arr[j].first && arr[i].second == arr[j].second)a[2]++;
            else if(arr[i].first > arr[j].first && arr[i].second == arr[j].second)a[3]++;
        }
        if(a[1] && a[2] && a[3] && a[0])c++;
    }
    cout << c;
    return 0;
}