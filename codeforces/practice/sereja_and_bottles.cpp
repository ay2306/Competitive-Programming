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
    int a[1001] = {0}, b[1001] = {0}, same[1001] = {0};
    int n;
    cin >> n;
    for(int i=0,inp1,inp2; i < n; ++i){
        cin >> inp1 >> inp2;
        a[inp1]++;
        if(inp1 != inp2){
            b[inp2]++;
        }else{
            same[inp2]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < 1001; ++i){
        if(a[i] > 0){
            if(b[i] == 0){
                if(same[i] == 1){
                    ans++;
                }
                if(same[i] == 0){
                    ans+=a[i];
                }
            }
        }
    }
    cout << ans;
    return 0;
}