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
    int n,a,s1=0,s2=0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a == 100)s1++;
        else s2++;
    }
    // cout << s1 << "  " << s2 << endl; 
    if(s1 == 0 || s2 == 0){
        if(s1 % 2 == 1 || s2 %2 == 1){
            cout << "NO";
            return 0;
        }
    }
    s1%=2;
    s2%=2;
    if((s1 == 0 && s2 == 0) || (s2 == 1 && s1 == 0)){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}