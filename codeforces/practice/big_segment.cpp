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
    int n,i;
    ull a,b,max,min;
    cin >> n;
    PUU *arr = new PUU[n];
    cin >> min >> max;
    arr[0] = mp(min,max);
    loop(i,1,n){
        ull a,b;
        cin >> a >> b;
        if(a < min)min = a;
        if(b > max)max = b;
        arr[i] = mp(a,b);
    }
    loop(i,0,n){
        if(arr[i].first == min && arr[i].second == max){
            cout << i+1;
            return 0;
        }
    }
    cout << "-1";
    return 0;

}