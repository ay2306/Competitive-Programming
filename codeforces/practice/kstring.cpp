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
    string a;
    int k;
    cin >> k;
    cin >> a;
    int f[26] = {0};
    for(int i = 0; i < a.length(); ++i){
        f[a[i]-'a']++;
    }
    for(int i = 0; i < 26; ++i){
        if(f[i]%k != 0){
            cout << "-1";
            return 0;
        }
    }
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < 26; ++j){
            for(int p = 0; p < f[j]/k; ++p){
                cout << char(j+'a');
            }
        }
    }
    return 0;
}