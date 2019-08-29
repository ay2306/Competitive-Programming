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
    cin >> a;
    bool pos = true;
    int n = a.length();
    for(int i = 0; i < n; ++i){
        if(a[i] == '1'){
            if(i+1 < n){
                if(a[i+1] == '4'){
                    if(i+2 < n){
                        if(a[i+2]=='4')++i;
                    }
                    ++i;
                }
            }
        }else{
            pos = false;
        }
    }
    if(pos)cout <<"YES";
    else cout << "NO";
    return 0;
}