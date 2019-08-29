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
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int kind_of_coins, *coin_values;
        cin >> kind_of_coins;
        coin_values = (int*)calloc(kind_of_coins,sizeof(int));
        for(int i = 0; i < kind_of_coins; ++i)cin >> coin_values[i];
        int val;
        cin >> val;
        int *dp = (int*)calloc(val+1, sizeof(int));
        for(int i = 1; i <= val; ++i){
            int minRes = INT_MAX;
            for(int j = 0; j < kind_of_coins && coin_values[j] <= i; ++j){
                int tres = dp[i-coin_values[j]]+1;
                if(tres < minRes)minRes=tres;
            }
            dp[i] = minRes;
        }
        cout << dp[val];
    }
    return 0;
}