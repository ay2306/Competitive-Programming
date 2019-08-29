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
    ull arr[26] = {0};
    ull n,k;
    cin >> n >> k;
    string a;
    cin >> a;
    for(int i = 0; i < a.length(); ++i){
        arr[a[i]-'A']++;
    }
    sort(arr,arr+26,greater<ull>());
    ull ans = 0;
    ull i = 0;
    while(k){
        if(k > arr[i]){
            ans+=(arr[i]*arr[i]);
            k-=arr[i];
            ++i;
        }else{
            ans+=(k*k);
            k = 0;
        }
    }
    cout << ans;
    return 0;
}