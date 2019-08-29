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
    string b;
    int diff1 = -1;
    int diff2 = -1;
    cin >> a >> b;
    int f1[26]={0};
    int f2[26]={0};
    if(a.length() != b.length()){
        cout << "NO";
        return 0;
    }
    int t = 0;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] != b[i]){
            ++t;
            if(diff1 == -1)diff1 = i;
            else diff2 = i;
        }
    }
    if(t > 2){
        cout << "NO\n";
        return 0;
    }
    // cout << a[diff1] << " " << b[diff2] << endl;
    // cout << a[diff2] << " " << b[diff1] << endl;
    if(a[diff1] == b[diff2] && a[diff2] == b[diff1]){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}