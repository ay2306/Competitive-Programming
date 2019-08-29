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


bool methCheck(string a, string b){
    int i = 0,j = 0;
    while(true){
        if(i == a.length())return true;
        if(j == b.length())return false;
        if(a[i] == b[j]){
            ++i; ++j;
        }
        else if(i == 0)++j;
        else i = 0;
    }
}

void solve(){
    string a;
    cin >> a;
    int k = 0;
    int i = 0;
    int j = -1;
    int n = a.length();
    string ans="";
    for(i = 1; i < a.length(); ++i){
        if(a[i] == a[0]){
            k = i;
            j = 0;
            while(a[i] == a[j] && i < n){
                ans+=a[i];
                ++i;++j;
            }
            if(i+1 < n)ans = "";
            else if(a[i]==a[0]){
                break;
            }
            ans = "";
        }
    }

    if(ans == "")ans="impossible";
    else cout << ans << endl;
    if(ans!="impossible")ans+=a;
    // if(ans!="impossible")if(methCheck(a,ans)){
    //     cout << "MATCHED FOR CASE: " << a << endl;
    // }
    
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }   
    return 0;
}